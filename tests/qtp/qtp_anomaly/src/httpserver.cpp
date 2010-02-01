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


#include <QTcpServer>
#include <QTcpSocket>

#include "BrowserWindow.h"
#include "httpserver.h"

#define HTTP_PORT 80

httpServer::httpServer( QObject *parent  )
         : QTcpServer( parent )
{
    httpSocket = NULL;

    tcpServer = new QTcpServer( /* this */ );
    not_done = true;
    bool result = tcpServer->listen(QHostAddress::Any, HTTP_PORT );
    if ( !result )
    {
        delete tcpServer;
        close();
        not_done = false;
        return;
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));

}

httpServer::~httpServer()
{
    if ( httpSocket )
    {
        httpSocket->disconnect(SIGNAL(readyRead()));
        httpSocket->disconnect(SIGNAL(error(QAbstractSocket::SocketError)));
        httpSocket->close();
        httpSocket->abort();
        httpSocket->deleteLater();
        httpSocket = NULL;
    }
}


bool httpServer::isDone()
{
    return not_done;
}
void httpServer::handleNewConnection()
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    clientConnection->setTextModeEnabled(true);

    if ( !httpSocket )
    {
        httpSocket = clientConnection;
        connect( httpSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(readConnection()));
        connect(httpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(displayConnectionError(QAbstractSocket::SocketError)));
    }
    else
    {
        // We already are busy with open connection?!
        // qDebug() << "Server busy.\n";
        clientConnection->disconnectFromHost();
    }
}


void httpServer::displayConnectionError(QAbstractSocket::SocketError /* socketError */ )
{
    httpSocket->disconnect(SIGNAL(readyRead()));
    httpSocket->disconnect(SIGNAL(error(QAbstractSocket::SocketError)));
    httpSocket->close();
    httpSocket->abort();
    httpSocket->deleteLater();
    httpSocket = NULL;
}


void httpServer::readConnection()
{
    while (httpSocket->canReadLine())
    {
        char buf[256];
        qint64 lineLength = httpSocket->readLine(buf, sizeof(buf));
        if (lineLength != -1)
        {
            QString tmpCommand(buf);
            tmpCommand = tmpCommand.simplified();

            // qDebug() << "Received: '" << buf << "'\n";

            if ( tmpCommand.left(4) == QString("GET ") )
            {
                qDebug() << "QTESTWEB: Received GET:" << buf << "\n";
		            // Craft and send a response
				        QString answer("HTTP/1.x 200 OK\nDate: Tue, 06 Jul 2004 17:59:22 GMT\n");
				        answer.append("Expires: Thu, 01 Jan 1970 00:00:00 GMT\n");
				        answer.append("Cache-Control: private, must-revalidate\n");
				        answer.append("Via: 1.0 cthulhu\n");
				        answer.append("Server: Apache/1.3.29 (Unix) PHP/4.3.4\n");
				        answer.append("X-Powered-By: PHP/4.3.4\n");
				        answer.append("Set-Cookie: fiwikiSession=a8015bd32eee4e5bd46fd83aea40f159; path=/\n");
				        answer.append("Vary: Accept-Encoding,Cookie\n");
				        answer.append("Content-Language: fi\n");
				        answer.append("Content-Type: text/html; charset=utf-8\n");
				        answer.append("X-Cache: MISS from wikipedia.org\n");
				        answer.append("Transfer-Encoding: chunked\n");
				        answer.append("Connection: keep-alive\n");
				        httpSocket->write(qPrintable(answer));
				        QString content("<HTML><HEAD><TITLE>Example Page</TITLE></HEAD>\n");
				        content.append("<body><p>Empty page sent by test server.</p></BODY></HTML>");
				        httpSocket->write(qPrintable(content));            
				        httpSocket->flush();

						    QTest::qWait(200);

				        not_done = false;
            }
/*
            else
            {
                qDebug() << "Received unknown:" << buf << "\n";
            }
*/            
        }
    }
}

