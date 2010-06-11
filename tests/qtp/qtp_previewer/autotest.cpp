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


 class aboutThread : public QThread
 {
 public:
     void run();
     void setMainWindow(MainWindow *aPtr) { iPtr = aPtr; };
 private:
     MainWindow *iPtr;

 };

 void aboutThread::run()
 {
     qDebug() << "entered aboutThread";
        QTest::qWait(500);
        QList<QMessageBox *> allDialogs = iPtr->findChildren<QMessageBox *>();
        QVERIFY( !allDialogs.isEmpty() );

        QPushButton * okButton;
        QList<QPushButton *> allPButtons = allDialogs.at(0)->findChildren<QPushButton *>();
        QVERIFY( allPButtons.count() == 1 );

        okButton = allPButtons.at(0);

        QVERIFY(okButton);
        okButton->click();

     qDebug() << "exit aboutThread";
 }

 class openUrlThread : public QThread
 {
 public:
     void run();
     void setMainWindow(MainWindow *aPtr) { iPtr = aPtr; };
 private:
     MainWindow *iPtr;

 };

 void openUrlThread::run()
 {
        QTest::qWait(500);
        QList<QInputDialog *> allDialogs = iPtr->findChildren<QInputDialog *>();
        QVERIFY( allDialogs.count() == 1 );

        QPushButton * cancelButton;
        QPushButton * okButton;
        QList<QPushButton *> allPButtons = allDialogs.at(0)->findChildren<QPushButton *>();
        QVERIFY( allPButtons.count() == 2 );

        for ( int i = 0; i < allPButtons.count(); i++)
        {
            if ( allPButtons.at(i)->text() == QString("OK") )
            {
                okButton = allPButtons.at(i);
            }
            else if ( allPButtons.at(i)->text() == QString("Cancel") )
            {
                cancelButton = allPButtons.at(i);
            }
            else
            {
                QFAIL("This test application does not handle localised texts!");
            }
        }
        QVERIFY(okButton);
        QVERIFY(cancelButton);

        QList<QLineEdit *> allLineEdits = allDialogs.at(0)->findChildren<QLineEdit *>();
        QVERIFY( allLineEdits.count() == 1 );
        QCOMPARE( allLineEdits.at(0)->text(), QString("http://") );

        QTest::qWait(100);
        allLineEdits.at(0)->setText(QString("http://www.google.fi"));

        QCOMPARE( allLineEdits.at(0)->text(), QString("http://www.google.fi") );
        QTest::qWait(100);

        cancelButton->click();
 }

void autoTest::initTestCase()
{
}

void autoTest::testDefaults()
{
	MainWindow mw;

	mw.show();

	// Test default values for widget properties
//      QCOMPARE( mw.acceptDrops(), false );
//	QCOMPARE( mw.hasEditFocus(), false );
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
        aboutThread executioner;
        openUrlThread disruptor;
        MainWindow mw;
        mw.show();

        QList<Previewer *> subObjects = mw.findChildren<Previewer *>();
        QVERIFY( subObjects.count() == 1 );
        Previewer *prev = subObjects.at(0);

	QVERIFY( prev );

        // Menu items to be tested initiated
        QMenu *filemenu;
        QMenu *helpmenu;
        QList<QMenu *> menuObjects = mw.findChildren<QMenu *>();
        QVERIFY( menuObjects.count() == 2 );

        for ( int i = 0; i < menuObjects.count(); i++)
        {
            if ( menuObjects.at(i)->title() == QString("&File") )
            {
                filemenu = menuObjects.at(i);
            }
            else if ( menuObjects.at(i)->title() == QString("&Help") )
            {
                helpmenu = menuObjects.at(i);
            }
            else
            {
                QFAIL("This test application does not handle localisated text items!");
            }
        }

        QVERIFY( filemenu );
        QVERIFY( !filemenu->isEmpty() );
        QCOMPARE( filemenu->title(), QString("&File") );

        QVERIFY( helpmenu );
        QVERIFY( !helpmenu->isEmpty() );
        QCOMPARE( helpmenu->title(), QString("&Help") );

        QAction *openUrl;
        QAction *about;
        QList<QAction *> actionObjects = mw.findChildren<QAction *>();

        QCOMPARE(actionObjects.count(), 9);

        for ( int i = 0; i < actionObjects.count(); i++)
        {
            if ( actionObjects.at(i)->text() == QString("&Open URL...") )
            {
                openUrl = actionObjects.at(i);
            }
            else if ( actionObjects.at(i)->text() == QString("&About") )
            {
                about = actionObjects.at(i);
            }
            else
            {
                // no test actions for these QACTION items, yet
            }
        }
        QTest::qWait(1000);

/*  this part doesn't work yet, investigation underway...
        filemenu->show();
        QTest::qWait(500);

        executioner.setMainWindow(&mw);
        executioner.start();

        about->trigger();
        QTest::qWait(3000);
*/

        filemenu->show();
        QTest::qWait(500);

        disruptor.setMainWindow(&mw);
        disruptor.start();

        openUrl->trigger();
        QTest::qWait(1000);

        mw.hide();
}

void autoTest::testPreviewer()
{
	MainWindow mw;

	mw.show();

        // What to test here?
        QList<Previewer *> subObjects = mw.findChildren<Previewer *>();
        QVERIFY( subObjects.count() == 1 );
        Previewer *prev = subObjects.at(0);

	QVERIFY( prev );

        mw.hide();
}

