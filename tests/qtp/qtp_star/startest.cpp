/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtOpenGL module of the Qt Toolkit.
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

#include "startest.h"
#include "starwidget.h"

	
void starTests::initTestCase()
{
	/*
	QApplication::setGraphicsSystem("openvg");
*/	
}

void starTests::testVoid()
{
	StarWidget mw;

	// Test default values for widget properties
	QVERIFY( !mw.acceptDrops() );
	QVERIFY( !mw.hasEditFocus() );
	QVERIFY( !mw.hasFocus() );
	QVERIFY( !mw.hasMouseTracking() );
	QVERIFY( mw.isActiveWindow() );
//	QVERIFY( mw.isAncestorOf() );
	QVERIFY( mw.isEnabled() );
//	QVERIFY( mw.isEnabledTo() );
	QVERIFY( mw.isFullScreen() );
	QVERIFY( mw.isHidden() );
	QVERIFY( mw.isMaximized() );
	QVERIFY( mw.isMinimized() );
	QVERIFY( mw.isModal() );
	QVERIFY( !mw.isVisible() );
//	QVERIFY( mw.isVisibleTo() );
	QVERIFY( mw.isWindow() );
	QVERIFY( mw.isWindowModified() );
	QVERIFY( mw.underMouse() );
	QVERIFY( mw.updatesEnabled() );

	QVERIFY( 1 == 1 );
}
