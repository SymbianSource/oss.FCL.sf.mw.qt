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
#include "addresswidget.h"
#include "adddialog.h"
#include "newaddresstab.h"
#include "tablemodel.h"
#include "autotest.h"

void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
	MainWindow mw;
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

void autoTest::testMainWindow()
{
    MainWindow mw;
    mw.show();

    QTest::qWait(1000);

    QAction *openAction = NULL;
    QAction *saveAction = NULL;
    QList<QAction *> allActions = mw.findChildren<QAction *>();
    QVERIFY( allActions.count() > 0 );

    for ( int i = 0; i < allActions.count(); i++ )
    {
        if ( allActions.at(i)->text() == QString("&Open..."))
        {
            openAction = allActions.at(i);
        }
        else if ( allActions.at(i)->text() == QString("&Save As..."))
        {
            saveAction = allActions.at(i);
        }
        else
        {
            // not currently tested by this autotest
        }
    }

    // verifies that these items exist, but no further testing is currently possible
    // due to limitations of event sending in kernel space between different threads.
    QVERIFY( openAction );
    QVERIFY( saveAction );

    QTest::qWait(1000);
}

void autoTest::testAddressWidget()
{
    QString name;
    QString address;

    MainWindow mw;
    mw.show();

    QTest::qWait(500);

    QList<AddressWidget *> allAddrWidgets = mw.findChildren<AddressWidget *>();
    QVERIFY( allAddrWidgets.count() == 1 );
    AddressWidget *wg = allAddrWidgets.at(0);

    // Some sanity checks for AddressWidget
    QVERIFY( wg != 0 );
	  
    QVERIFY( wg->width() > 0 );
    QVERIFY( wg->height() > 0 );
    QVERIFY( wg->width() <= mw.width() );
    QVERIFY( wg->height() <= mw.height() );   
    
    // Testing adding items to data fields
    QList<TableModel *> allTables = wg->findChildren<TableModel *>();
    QVERIFY( allTables.count() == 1 );
    TableModel *tm = allTables.at(0);
    QVERIFY( tm != 0 );

    QCOMPARE( tm->rowCount( QModelIndex()), 0 );
    QCOMPARE( tm->columnCount( QModelIndex()), 2 );

    name = "asdf";
    address = "0xD34DB33F";
    wg->addEntry( name, address );

    name = "qwerty";
    address = "usb1:0";
    wg->addEntry( name, address );

    name = "john";
    address = "doestreet";
    wg->addEntry( name, address );

    QCOMPARE( tm->rowCount( QModelIndex()), 3 );
    QCOMPARE( tm->columnCount( QModelIndex()), 2 );

    QTest::qWait(1000);

    // Testing removing items to data fields
    QTableView *tmp = static_cast<QTableView*>(wg->currentWidget());
    QVERIFY( tmp );
    tmp->selectRow(0);
    QTest::qWait(1000);

    wg->removeEntry();
    QTest::qWait(200);
    QCOMPARE( tm->rowCount( QModelIndex()), 2 );
    QCOMPARE( tm->columnCount( QModelIndex()), 2 );

    QTest::qWait(1000);

    mw.hide();
}

void autoTest::testAddDialog()
{
    MainWindow mw;
    mw.show();

    QTest::qWait(500);

    mw.hide();
}

void autoTest::testNewAddressTab()
{
    MainWindow mw;
    mw.show();

    QTest::qWait(500);

    QList<AddressWidget *> allAddrWidgets = mw.findChildren<AddressWidget *>();
    QVERIFY( allAddrWidgets.count() == 1 );
    AddressWidget *wg = allAddrWidgets.at(0);
    QVERIFY( wg != 0 );

    QList<NewAddressTab *> allNewWidgets = wg->findChildren<NewAddressTab *>();
    QVERIFY( allNewWidgets.count() == 1 );
    NewAddressTab *nat = allNewWidgets.at(0);
    QVERIFY( nat != 0 );

    QTableView *tmp = static_cast<QTableView*>(wg->currentWidget());
    QVERIFY( tmp );

    for (int i = 0; i < wg->count(); i++)
    {
        wg->setCurrentIndex(i);
        QTest::qWait(500);
    }
    wg->setCurrentIndex(0);

    QTest::keyClick ( wg, Qt::Key_Tab, Qt::NoModifier, 500 );
    QTest::keyClick ( wg, Qt::Key_Tab, Qt::NoModifier, 500 );

    mw.hide();
}

void autoTest::testTableModel()
{
    MainWindow mw;
    mw.show();

    QTest::qWait(500);

    QList<AddressWidget *> allAddrWidgets = mw.findChildren<AddressWidget *>();
    QVERIFY( allAddrWidgets.count() == 1 );
    AddressWidget *wg = allAddrWidgets.at(0);
    QVERIFY( wg != 0 );

    QList<TableModel *> allTables = wg->findChildren<TableModel *>();
    QVERIFY( allTables.count() == 1 );
    TableModel *tm = allTables.at(0);
    QVERIFY( tm != 0 );
    
    mw.hide();
}
