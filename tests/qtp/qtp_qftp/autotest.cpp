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


#include <QThread>
#include "ftpserver.h"
#include "ftpwindow.h"
#include "autotest.h"


 class serverThread : public QThread
 {
 public:
     void run();
 };

 void serverThread::run()
 {
    ftpServer testServer;

    while ( testServer.isDone() )
    {
        QTest::qWait(1000);
    }
 }

void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
        FtpWindow fw;

        fw.show();

        // Test default values for widget properties
//      QCOMPARE( fw.acceptDrops(), false );
//	QCOMPARE( fw.hasEditFocus(), false );
        QCOMPARE( fw.hasFocus(), false );
        QCOMPARE( fw.hasMouseTracking(), false );
        /*
        QCOMPARE( fw.isActiveWindow(), true );
        QCOMPARE( fw.isEnabled(), true );
        QCOMPARE( fw.isFullScreen(), false );
        QCOMPARE( fw.isHidden(), false );
        QCOMPARE( fw.isMaximized(), false );
        QCOMPARE( fw.isMinimized(), false );
        QCOMPARE( fw.isModal(), false );
        QCOMPARE( fw.isVisible(), true );
        QCOMPARE( fw.isWindow(), true );
        QCOMPARE( fw.isWindowModified(), false );
        QCOMPARE( fw.underMouse(), false );
        QCOMPARE( fw.updatesEnabled(), true );
        */

        fw.hide();
}

void autoTest::testFtpWindow()
{
        FtpWindow fw;

        fw.show();

        // what to test here
        serverThread testThread;
        testThread.start();

        QPushButton * connectButton;
        QList<QPushButton *> allPButtons = fw.findChildren<QPushButton *>();
        QVERIFY( allPButtons.count() > 0 );

        for ( int i = 0; i < allPButtons.count(); i++)
        {
            if ( allPButtons.at(i)->text() == QString("Connect") )
            {
                connectButton = allPButtons.at(i);
            }
            else
            {
                // Other buttons than connect ignored so far...
            }
        }
        QVERIFY(connectButton);

        QLineEdit * addressLine;
        QList<QLineEdit *> allLineEds = fw.findChildren<QLineEdit *>();
        QVERIFY( allLineEds.count() == 1 );

        addressLine = allLineEds.at(0);

        while ( !addressLine->text().isEmpty() )
        {
            QTest::keyClick ( addressLine, Qt::Key_Backspace, Qt::NoModifier, 100 );
        }

        QTest::qWait(2000);
        QTest::keyClicks( addressLine, "127.0.0.1" );

        QTest::qWait(2000);
        connectButton->click();

        QLabel * statusLabel;
        QList<QLabel *> allLabels = fw.findChildren<QLabel *>();
        QVERIFY( allLabels.count() > 0 );

        for ( int i = 0; i < allLabels.count(); i++)
        {
            if ( allLabels.at(i)->text() == QString("Logged onto 127.0.0.1.") )
            {
                statusLabel = allLabels.at(i);
            }
            else
            {
                // Other buttons than connect ignored so far...
            }
        }
        QVERIFY(statusLabel);

        QTest::qWait(2000);

        fw.hide();
}



