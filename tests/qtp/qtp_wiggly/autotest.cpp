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


#include "dialog.h"
#include "wigglywidget.h"
#include "autotest.h"


void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
    Dialog dialog(0,false);
    dialog.show();

    // Test default values for widget properties
    //	QCOMPARE( dialog.acceptDrops(), false );
    //	QCOMPARE( dialog.hasEditFocus(), false );
    QCOMPARE( dialog.hasFocus(), false );
    QCOMPARE( dialog.hasMouseTracking(), false );
    QCOMPARE( dialog.isActiveWindow(), true );
    QCOMPARE( dialog.isEnabled(), true );
    QCOMPARE( dialog.isFullScreen(), false );
    QCOMPARE( dialog.isHidden(), false );
    QCOMPARE( dialog.isMaximized(), false );
    QCOMPARE( dialog.isMinimized(), false );
    QCOMPARE( dialog.isModal(), false );
    QCOMPARE( dialog.isVisible(), true );
    QCOMPARE( dialog.isWindow(), true );
    QCOMPARE( dialog.isWindowModified(), false );
    QCOMPARE( dialog.underMouse(), false );
    QCOMPARE( dialog.updatesEnabled(), true );

    dialog.hide();
}

void autoTest::testWigglyWidget()
{
    Dialog dialog(0,false);
    dialog.show();

    QList<WigglyWidget *> subObjects = dialog.findChildren<WigglyWidget *>();
    QVERIFY( subObjects.count() == 1 );
    QWidget *wg = subObjects.at(0);

    QVERIFY( wg != 0 );

    // Some sanity checks for wiggle widget
    QVERIFY( wg->width() > 0 );
    QVERIFY( wg->height() > 0 );

    QVERIFY( wg->width() <= dialog.width() );
    QVERIFY( wg->height() <= dialog.height() );

    // but not much more to be verified here

    dialog.hide();
}

void autoTest::testInputWidget()
{
    Dialog dialog(0,false);
    dialog.show();

    QList<QLineEdit *> editObjects = dialog.findChildren<QLineEdit *>();
    QVERIFY( editObjects.count() == 1 );
    QLineEdit *le = editObjects.at(0);

    QList<WigglyWidget *> subObjects = dialog.findChildren<WigglyWidget *>();
    QVERIFY( subObjects.count() == 1 );
    WigglyWidget *wg = subObjects.at(0);

    QVERIFY( le != 0 );

    // Some sanity checks for text input widget
    QVERIFY( le->width() > 0 );
    QVERIFY( le->height() > 0 );

    QVERIFY( le->width() <= dialog.width() );
    QVERIFY( le->height() <= dialog.height() );

    // Tests the generic behaviour of the line edit widget
    le->setFocus(Qt::OtherFocusReason);

    QTest::qWait(1000);

    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );
    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );
    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );
    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );
    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );
    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );
    QTest::keyClick ( le, Qt::Key_Backspace, Qt::NoModifier, 10 );

    QTest::keyClicks( le, "!!!" );
    le->clearFocus();

    // Verifies that edited line information is correctly copied
    QCOMPARE( le->text(), QString("Hello!!!") );
    QCOMPARE( le->text(), wg->getText() );

    QTest::qWait(1000);

    dialog.hide();
}

