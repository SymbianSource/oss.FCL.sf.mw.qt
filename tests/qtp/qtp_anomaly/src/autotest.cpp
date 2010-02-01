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
#include <QtWebKit>

#include "browserwindow.h"
#include "addressbar.h"
#include "homeview.h"
#include "browserview.h"
#include "httpserver.h"
#include "autotest.h"




//
class serverThread : public QThread
{
public:
    void run();
};

void serverThread::run()
{
   httpServer testServer;

   while ( testServer.isDone() )
   {
       QTest::qWait(1000);
   }
}


//
// from here normal autotest stuff follows...
//


void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
	BrowserWindow bw;
	bw.show();
	

	// Test default values for widget properties
	QCOMPARE( bw.acceptDrops(), false );
//	QCOMPARE( bw.hasEditFocus(), false );
/*
	QCOMPARE( bw.hasFocus(), false );
	QCOMPARE( bw.hasMouseTracking(), false );
	QCOMPARE( bw.isActiveWindow(), false );
	QCOMPARE( bw.isEnabled(), true );
	QCOMPARE( bw.isFullScreen(), false );
	QCOMPARE( bw.isHidden(), false );
	QCOMPARE( bw.isMaximized(), false );
	QCOMPARE( bw.isMinimized(), false );
	QCOMPARE( bw.isModal(), false );
	QCOMPARE( bw.isVisible(), true );
	QCOMPARE( bw.isWindow(), true );
	QCOMPARE( bw.isWindowModified(), false );
	QCOMPARE( bw.underMouse(), false );
	QCOMPARE( bw.updatesEnabled(), true );
*/
	bw.hide();
}

void autoTest::testBrowser()
{
	BrowserWindow bw;
	// bw.show();
    QWebSettings::globalSettings()->setObjectCacheCapacities(128*1024, 1024*1024, 1024*1024);
    QWebSettings::globalSettings()->setMaximumPagesInCache(3);

    bw.showFullScreen();
    
    HomeView *hView = NULL;
    QList<HomeView *> firstHiew = bw.findChildren<HomeView *>();
    if ( firstHiew.count() > 0 )
    	hView = firstHiew.at(0);
    else
    	hView = bw.getHomeView();    		
    QVERIFY( !hView );

    QTest::qWait(2000);

    QList<HomeView *> secHiew = bw.findChildren<HomeView *>();
    if ( secHiew.count() > 0 )
    	hView = secHiew.at(0);
    else
    	hView = bw.getHomeView();    		
    QVERIFY( hView );

    BrowserView *bView = NULL;
    QList<BrowserView *> browView = bw.findChildren<BrowserView *>();
    QVERIFY( browView.count() > 0 );
  	bView = browView.at(0);
    QVERIFY( bView );

    AddressBar *addrBar = NULL;
    QList<AddressBar *> allBars = hView->findChildren<AddressBar *>();
    QVERIFY( allBars.count() > 0 );
    addrBar = allBars.at(0);
    QVERIFY( addrBar );

    QLineEdit *addrEdit = NULL;
    QList<QLineEdit *> allLineEds = addrBar->findChildren<QLineEdit *>();
    if ( allLineEds.count() > 0 )
    	addrEdit = allLineEds.at(0);
    else
    	addrEdit = addrBar->getLineEdit();    		
    QVERIFY( addrEdit );

    QToolButton *goButton = NULL;
    QList<QToolButton *> aToolBtn = addrBar->findChildren<QToolButton *>();
    if ( aToolBtn.count() > 0 )
    	goButton = aToolBtn.at(0);
    else
    	goButton = addrBar->getToolButton();    		
    QVERIFY( goButton );

    serverThread mojave;
    mojave.start();

    QTest::qWait(2000);
    	

	// Fill in actual test set... (not much really)
	// test at least these;
  // class BookmarksView : public QWidget
  // try to click these
//      QPixmap zoomInPixmap;
//    QPixmap zoomOutPixmap;
//    QListWidget *m_iconView = new QListWidget(this);
// m_toolButton = new QToolButton(parent);
//    m_toolButton->setText("Go");

    QTest::qWait(3000);
		addrEdit->clear();
    addrEdit->setFocus(Qt::OtherFocusReason);
    QTest::keyClicks( addrEdit, "http://127.0.0.1/index.html" );
    addrEdit->clearFocus();
    goButton->click();
    QTest::qWait(2000);

		addrEdit->clear();
    addrEdit->setFocus(Qt::OtherFocusReason);
    QTest::keyClicks( addrEdit, "http://www.example.net" );
    addrEdit->clearFocus();
    goButton->click();
    QTest::qWait(3000);

		if ( mojave.isRunning() )
			{
			mojave.quit();
			QFAIL("GET not received by the stub server.");
		}

    QTest::qWait(3000);

	bw.showBrowserView();
    QTest::qWait(2000);

	bw.hide();
    QTest::qWait(1000);
    	    	
	bw.close();
    QTest::qWait(1000);
}
