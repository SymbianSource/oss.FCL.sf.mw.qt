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


#include "mouse.h"
#include "autotest.h"


void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
	Mouse clock;
	clock.show();
/*
	// Test default values for widget properties
	QCOMPARE( clock.acceptDrops(), false );
	QCOMPARE( clock.hasEditFocus(), false );
	QCOMPARE( clock.hasFocus(), false );
	QCOMPARE( clock.hasMouseTracking(), false );
	QCOMPARE( clock.isActiveWindow(), true );
	QCOMPARE( clock.isEnabled(), true );
	QCOMPARE( clock.isFullScreen(), false );
	QCOMPARE( clock.isHidden(), false );
	QCOMPARE( clock.isMaximized(), false );
	QCOMPARE( clock.isMinimized(), false );
	QCOMPARE( clock.isModal(), false );
	QCOMPARE( clock.isVisible(), true );
	QCOMPARE( clock.isWindow(), true );
	QCOMPARE( clock.isWindowModified(), false );
	QCOMPARE( clock.underMouse(), false );
	QCOMPARE( clock.updatesEnabled(), true );
*/
	clock.hide();
}

void autoTest::testMouse()
{
	Mouse mouse;
	mouse.show();

	// Fill in actual test set... (not much really)


	mouse.hide();
}
