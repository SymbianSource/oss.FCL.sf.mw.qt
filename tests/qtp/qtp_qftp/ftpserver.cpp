/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "ftpserver.h"

#define FTP_CMND_PORT 21
#define FTP_DATA_PORT 9801

ftpServer::ftpServer( QObject *parent  )
         : QTcpServer( parent )
{
    ftpSocket = NULL;
    dataSocket = NULL;

    tcpServer = new QTcpServer( /* this */ );
    not_done = true;
    bool result = tcpServer->listen(QHostAddress::Any, FTP_CMND_PORT );
    if ( !result )
    {
        delete tcpServer;
        close();
        not_done = false;
        return;
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));

/*
    dataServer = new QTcpServer( );
    result = dataServer->listen(QHostAddress::Any, FTP_DATA_PORT );
    if ( !result )
    {
        delete tcpServer;
        close();
        not_done = false;

        delete dataServer;
        close();
        return;
    }

    connect(dataServer, SIGNAL(newConnection()), this, SLOT(handleNewDataConnection()));
*/
}

ftpServer::~ftpServer()
{
    if ( ftpSocket )
    {
        ftpSocket->disconnect(SIGNAL(readyRead()));
        ftpSocket->disconnect(SIGNAL(error(QAbstractSocket::SocketError)));
        ftpSocket->close();
        ftpSocket->abort();
        ftpSocket->deleteLater();
        ftpSocket = NULL;
    }
}

bool ftpServer::isDone()
{
    return not_done;
}
void ftpServer::handleNewConnection()
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    clientConnection->setTextModeEnabled(true);

    if ( !ftpSocket )
    {
        ftpSocket = clientConnection;
        connect( ftpSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(readConnection()));
        connect(ftpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(displayConnectionError(QAbstractSocket::SocketError)));

        QString greet("220 Service ready\n");
        ftpSocket->write(qPrintable(greet));

    }
    else if ( !dataSocket )
    {
        dataSocket = clientConnection;
        connect( dataSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(readConnection()));
        connect(dataSocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(displayConnectionError(QAbstractSocket::SocketError)));

        if ( dataSocket->waitForConnected() )
        {
        //qDebug() << "Data connection accepted.\n";
        }


    }
    else
    {
        // We already are busy with open connection?!
        // qDebug() << "Server busy.\n";
        clientConnection->disconnectFromHost();
    }
}

void ftpServer::handleNewDataConnection()
{
    QTcpSocket *dataConnection = tcpServer->nextPendingConnection();
    dataConnection->setTextModeEnabled(true);

    if ( !dataSocket )
    {
        dataSocket = dataConnection;
        connect( dataSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(readConnection()));
        connect(dataSocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(displayConnectionError(QAbstractSocket::SocketError)));

        QString list(".\n..\nasdf.txt\nqwerty.txt\n");
        ftpSocket->write(qPrintable(list));

    }
    else
    {
        // We already are busy with open connection?!
        //qDebug() << "Data Server busy.\n";
        dataConnection->disconnectFromHost();
    }
}

void ftpServer::displayConnectionError(QAbstractSocket::SocketError socketError)
{
		Q_UNUSED(socketError);
    ftpSocket->disconnect(SIGNAL(readyRead()));
    ftpSocket->disconnect(SIGNAL(error(QAbstractSocket::SocketError)));
    ftpSocket->close();
    ftpSocket->abort();
    ftpSocket->deleteLater();
    ftpSocket = NULL;
}

void ftpServer::displayDataConnectionError(QAbstractSocket::SocketError socketError)
{
		Q_UNUSED(socketError);
    dataSocket->disconnect(SIGNAL(readyRead()));
    dataSocket->disconnect(SIGNAL(error(QAbstractSocket::SocketError)));
    dataSocket->close();
    dataSocket->abort();
    dataSocket->deleteLater();
    dataSocket = NULL;
}

void ftpServer::readDataConnection()
{
    while (dataSocket->canReadLine())
    {
        dataSocket->readAll();
    }
}

void ftpServer::readConnection()
{
    while (ftpSocket->canReadLine())
    {
        char buf[256];
        qint64 lineLength = ftpSocket->readLine(buf, sizeof(buf));
        if (lineLength != -1)
        {
            QString tmpCommand(buf);
            tmpCommand = tmpCommand.simplified();

            // qDebug() << "Received: '" << buf << "'\n";
            if ( tmpCommand.left(5) == QString("USER ") )
            {
                QString acceptuser("331 User name ok\n");
                ftpSocket->write(qPrintable(acceptuser));
            }
            else if ( tmpCommand.left(5) == QString("PASS ") )
            {
                QString acceptCommand("230 User logged in\n");
                ftpSocket->write(qPrintable(acceptCommand));
            }
            else if ( tmpCommand.left(5) == QString("TYPE ") )
            {
                QString acceptCommand("200 Command OK\n");
                // QString acceptCommand("227 Entering Passive Mode. 21,21,21,21,21,21\n");
                ftpSocket->write(qPrintable(acceptCommand));
            }
            else if ( tmpCommand.left(4) == QString("PASV") )
            {
                QString acceptCommand("227 Entering Passive Mode. (127,0,0,1,0,21)\n");
                // QString acceptCommand("200 Command OK\n");
                ftpSocket->write(qPrintable(acceptCommand));
            }
            else if ( tmpCommand.left(4) == QString("LIST") )
            {
                // QString acceptuser("502 Command not implemented\n");
                // QString acceptuser("-rw-r--r--    1 vogel    user     1209041 May  1 13:55 IMPJET24.CAS\n-rw-r--r--    1 vogel    user     10259798 May  1 20:57 IMPJET24.DAT\n");
            // qDebug() << "sending 200...\n";
                QString acceptCommand("200 Command OK\n");
                ftpSocket->write(qPrintable(acceptCommand));
                // qDebug() << "sending 150...\n";
                QString port;
                port.setNum(dataSocket->localPort());
                QString dataCommand("150 ASCII data connection for /bin/ls (127.0.0.1,");
                dataCommand.append( port );
                dataCommand.append(") (0 bytes).");
                ftpSocket->write(qPrintable(dataCommand));
                // not_done = false;

                //
                //QString list(".\n..\nasdf.txt\nqwerty.txt\n");
                QString list("07.12.2009\t13:49\t<DIR>\tinclude\n03.12.2009\t14:01\t721\tINSTALL\n");


                dataSocket->write(qPrintable(list));
                dataSocket->flush();
                dataSocket->disconnectFromHost();
                dataSocket = NULL;

                // qDebug() << "sending 226...\n";
                QString finishCommand("226 Closing data connection, file transfer successful.\n");
                ftpSocket->write(qPrintable(finishCommand));

                not_done = false;

            }
            else
            {
                // qDebug() << "Received unknown:" << buf << "\n";
            }
        }
    }
}


