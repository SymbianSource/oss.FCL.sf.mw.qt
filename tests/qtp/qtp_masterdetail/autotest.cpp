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


#include "mainwindow.h"
#include "autotest.h"


void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
    QFile *albumDetails = new QFile("albumdetails.xml");

    MainWindow mw("artists", "albums", albumDetails);

	mw.show();

	// Test default values for widget properties
	QCOMPARE( mw.acceptDrops(), false );
	QCOMPARE( mw.hasEditFocus(), false );
	QCOMPARE( mw.hasFocus(), false );
	QCOMPARE( mw.hasMouseTracking(), false );
	QCOMPARE( mw.isActiveWindow(), true );
	QCOMPARE( mw.isEnabled(), true );
	QCOMPARE( mw.isFullScreen(), false );
	QCOMPARE( mw.isHidden(), false );
	QCOMPARE( mw.isMaximized(), false );
	QCOMPARE( mw.isMinimized(), false );
	QCOMPARE( mw.isModal(), false );
	QCOMPARE( mw.isVisible(), true );
	QCOMPARE( mw.isWindow(), true );
	QCOMPARE( mw.isWindowModified(), false );
	QCOMPARE( mw.underMouse(), false );
	QCOMPARE( mw.updatesEnabled(), true );

	mw.hide();	
}
void autoTest::testMainView()
{
    QFile *albumDetails = new QFile("albumdetails.xml");
    MainWindow mw("artists", "albums", albumDetails);

    mw.show();
    QComboBox *artv = mw.getArtistView();
    QTableView *albv = mw.getAlbumView();

    // sanity checks for items in view
    QVERIFY( artv );
    QVERIFY( albv );

    // verify that combobox is in default state
    QCOMPARE( artv->count(), 0 );
    QCOMPARE( artv->currentIndex(), -1 );

    // verify that albumview shows correct items
    QTest::mouseClick ( (QWidget *)artv, Qt::LeftButton );
		QTest::qWait(100);    
    artv->setCurrentIndex(0);
    QTest::mouseClick ( (QWidget *)albv, Qt::LeftButton );
    QTest::qWait(100);    
    QCOMPARE( artv->currentIndex(), 0 );

    // select one item from the combobox item list
    // verify that albumview shows correct items
    QTest::mouseClick ( (QWidget *)artv, Qt::LeftButton );
		QTest::qWait(100);    
    artv->setCurrentIndex(2);
    QTest::mouseClick ( (QWidget *)albv, Qt::LeftButton );
    QTest::qWait(100);    
    QCOMPARE( artv->currentIndex(), 2 );

    // select another item from the combobox item list
    // verify that albumview shows correct items
    QTest::mouseClick ( (QWidget *)artv, Qt::LeftButton );
		QTest::qWait(100);    
    artv->setCurrentIndex(1);
    QTest::mouseClick ( (QWidget *)albv, Qt::LeftButton );
    QTest::qWait(100);    
    QCOMPARE( artv->currentIndex(), 1 );

    mw.hide();	
}

void autoTest::testAlbumView()
{
    QFile *albumDetails = new QFile("albumdetails.xml");
    MainWindow mw("artists", "albums", albumDetails);

    //mw.show();
    QTableView *albv = mw.getAlbumView();

    // what is tested here?
    QVERIFY( albv );

    mw.hide();	
}

void autoTest::testArtistView()
{
    QFile *albumDetails = new QFile("albumdetails.xml");
    MainWindow mw("artists", "albums", albumDetails);

    //mw.show();
    QComboBox *artv = mw.getArtistView();

    // what is tested here?
    QVERIFY( artv );

    mw.hide();	
}

void autoTest::testTrackList()
{
    QFile *albumDetails = new QFile("albumdetails.xml");
    MainWindow mw("artists", "albums", albumDetails);

    //mw.show();
    QListWidget *tl = mw.getTrackList();
    
    // what is tested here?
    QVERIFY( tl );

    mw.hide();	
}

void autoTest::testModel()
{
    QFile *albumDetails = new QFile("albumdetails.xml");
    MainWindow mw("artists", "albums", albumDetails);

    mw.show();
    QSqlRelationalTableModel *mdl = mw.getModel();

    // what is tested here?
    // adding more items into model?
    // saving whole model?
    // deleting items from model?
    // reloading whole model?

    QVERIFY( mdl );

    // check the default values
    /*
    QCOMPARE( mdl->columnCount(), 2 );
    QCOMPARE( mdl->rowCount(), 2 );
    */

    mw.hide();	
}

