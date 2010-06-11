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


#include "raycasting.h"
#include "autotest.h"


void autoTest::initTestCase()
{
    Q_INIT_RESOURCE(qtp_raycasting);
}

void autoTest::testDefaults()
{
	
	Raycasting mw;
	mw.show();

	// mw.openFile(":/files/bubbles.svg");

	// Test default values for widget properties
	QCOMPARE( mw.acceptDrops(), false );
/*
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
*/
        QCOMPARE( mw.updatesEnabled(), true );
	
	mw.hide();
}

void autoTest::testRaycasting()
{
	
	ray = new Raycasting;
	ray->show();

	// mw.openFile(":/files/bubbles.svg");

	// Test at least playerpos with keyboard input
        // what else?
        /*
	QCOMPARE( ray->playerPos.x(), 1.50f );
	QCOMPARE( ray->playerPos.y(), 1.50f );
        */
	ray->hide();
	delete ray;
}
