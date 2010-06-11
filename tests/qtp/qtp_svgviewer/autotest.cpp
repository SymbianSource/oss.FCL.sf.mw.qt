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
    Q_INIT_RESOURCE(qtp_svgviewer);
}

void autoTest::testDefaults()
{
	
	MainWindow mw;
        mw.openFile(":/files/bubbles.svg");
        mw.show();

        // Test default values for widget properties
//	QVERIFY( !mw.acceptDrops() );
//	QVERIFY( !mw.hasEditFocus() );
	QVERIFY( !mw.hasFocus() );
	QVERIFY( !mw.hasMouseTracking() );
	QVERIFY( mw.isActiveWindow() );
	QVERIFY( mw.isEnabled() );
        /*
//	QVERIFY( mw.isFullScreen() );
//	QVERIFY( mw.isHidden() );
	QVERIFY( mw.isMaximized() );
	QVERIFY( mw.isMinimized() );
	QVERIFY( mw.isModal() );
	QVERIFY( !mw.isVisible() );
	QVERIFY( mw.isWindow() );
	QVERIFY( mw.isWindowModified() );
	QVERIFY( mw.underMouse() );
        QVERIFY( mw.updatesEnabled() );
        */

        mw.hide();

}

void autoTest::testMainWindow()
{
        MainWindow mw;
        mw.openFile(":/files/bubbles.svg");
        mw.show();

        // What to test here...
        // renderer switch
        //

        QMenu *rendererMenu = NULL;
        QMenu *viewMenu = NULL;
        QList<QMenu *> allMenus = mw.findChildren<QMenu *>();
        QVERIFY( allMenus.count() > 0 );

        for ( int i = 0; i < allMenus.count(); i++ )
        {
            if ( allMenus.at(i)->title() == QString("&Renderer"))
            {
                rendererMenu = allMenus.at(i);
            }
            else if ( allMenus.at(i)->title() == QString("&View"))
            {
                viewMenu = allMenus.at(i);
            }
            else
            {
                // not currently tested by this autotest
            }
        }
        QVERIFY( rendererMenu );
        QVERIFY( !rendererMenu->isEmpty() );

        QVERIFY( viewMenu );
        QVERIFY( !viewMenu->isEmpty() );

        QAction *backgroundAction = NULL;
        QAction *outlineAction = NULL;
        QAction *nativeAction = NULL;
        QAction *openglAction = NULL;
        QAction *imageAction = NULL;
        QList<QAction *> allActions = mw.findChildren<QAction *>();
        QVERIFY( allActions.count() > 0 );

        for ( int i = 0; i < allActions.count(); i++ )
        {
            if ( allActions.at(i)->text() == QString("&Background"))
            {
                backgroundAction = allActions.at(i);
            }
            else if ( allActions.at(i)->text() == QString("&Outline"))
            {
                outlineAction = allActions.at(i);
            }
            else if ( allActions.at(i)->text() == QString("&Native"))
            {
                nativeAction = allActions.at(i);
            }
            else if ( allActions.at(i)->text() == QString("&OpenGL"))
            {
                openglAction = allActions.at(i);
            }
            else if ( allActions.at(i)->text() == QString("&Image"))
            {
                imageAction = allActions.at(i);
            }
            else
            {
                // not currently tested by this autotest
            }
        }
        QVERIFY( backgroundAction );
        QVERIFY( outlineAction );

        rendererMenu->show();
        QTest::qWait(300);
        imageAction->trigger();
        QTest::qWait(200);
        rendererMenu->hide();
        QTest::qWait(1000);

#ifndef QT_NO_OPENGL
        rendererMenu->show();
        QTest::qWait(300);
        openglAction->trigger();
        QTest::qWait(200);
        rendererMenu->hide();
        QTest::qWait(1000);
#endif

        rendererMenu->show();
        QTest::qWait(300);
        nativeAction->trigger();
        QTest::qWait(200);
        rendererMenu->hide();
        QTest::qWait(1000);

        viewMenu->show();
        QTest::qWait(300);
        backgroundAction->trigger();
        QTest::qWait(200);
        viewMenu->hide();
        QTest::qWait(500);

        viewMenu->show();
        QTest::qWait(300);
        backgroundAction->trigger();
        QTest::qWait(200);
        viewMenu->hide();
        QTest::qWait(500);

        viewMenu->show();
        QTest::qWait(300);
        outlineAction->trigger();
        viewMenu->hide(); // calling trigger directly doesn't hide menu item
        QTest::qWait(500);

        viewMenu->show();
        QTest::qWait(300);
        outlineAction->trigger(); // have to use trigger method, because qaction won't accept mouse clicks
        viewMenu->hide(); // calling trigger directly doesn't hide menu item
        QTest::qWait(1000);

        QTest::qWait(2000);
        mw.hide();


}
