/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
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


#include <QtTest/QtTest>
#include <qapplication.h>
#include <qtabbar.h>

#include <qpushbutton.h>
#include <qstyle.h>
#include "../../shared/util.h"

class tst_QTabBar : public QObject
{
    Q_OBJECT

public:
    tst_QTabBar();
    virtual ~tst_QTabBar();

public slots:
    void initTestCase();
    void cleanupTestCase();
    void init();

private slots:
    void getSetCheck();
    void setIconSize();
    void setIconSize_data();

    void testCurrentChanged_data();
    void testCurrentChanged();

    void insertAtCurrentIndex();

    void removeTab_data();
    void removeTab();

    void setElideMode_data();
    void setElideMode();

    void setUsesScrollButtons_data();
    void setUsesScrollButtons();

    void removeLastTab();

    void closeButton();

    void tabButton_data();
    void tabButton();

    void selectionBehaviorOnRemove_data();
    void selectionBehaviorOnRemove();

    void moveTab_data();
    void moveTab();

    void task251184_removeTab();
    void changeTitleWhileDoubleClickingTab();
};

// Testing get/set functions
void tst_QTabBar::getSetCheck()
{
    QTabBar obj1;
    obj1.addTab("Tab1");
    obj1.addTab("Tab2");
    obj1.addTab("Tab3");
    obj1.addTab("Tab4");
    obj1.addTab("Tab5");
    // Shape QTabBar::shape()
    // void QTabBar::setShape(Shape)
    obj1.setShape(QTabBar::Shape(QTabBar::RoundedNorth));
    QCOMPARE(QTabBar::Shape(QTabBar::RoundedNorth), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::RoundedSouth));
    QCOMPARE(QTabBar::Shape(QTabBar::RoundedSouth), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::RoundedWest));
    QCOMPARE(QTabBar::Shape(QTabBar::RoundedWest), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::RoundedEast));
    QCOMPARE(QTabBar::Shape(QTabBar::RoundedEast), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::TriangularNorth));
    QCOMPARE(QTabBar::Shape(QTabBar::TriangularNorth), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::TriangularSouth));
    QCOMPARE(QTabBar::Shape(QTabBar::TriangularSouth), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::TriangularWest));
    QCOMPARE(QTabBar::Shape(QTabBar::TriangularWest), obj1.shape());
    obj1.setShape(QTabBar::Shape(QTabBar::TriangularEast));
    QCOMPARE(QTabBar::Shape(QTabBar::TriangularEast), obj1.shape());

    // bool QTabBar::drawBase()
    // void QTabBar::setDrawBase(bool)
    obj1.setDrawBase(false);
    QCOMPARE(false, obj1.drawBase());
    obj1.setDrawBase(true);
    QCOMPARE(true, obj1.drawBase());

    // int QTabBar::currentIndex()
    // void QTabBar::setCurrentIndex(int)
    obj1.setCurrentIndex(0);
    QCOMPARE(0, obj1.currentIndex());
    obj1.setCurrentIndex(INT_MIN);
    QCOMPARE(0, obj1.currentIndex());
    obj1.setCurrentIndex(INT_MAX);
    QCOMPARE(0, obj1.currentIndex());
    obj1.setCurrentIndex(4);
    QCOMPARE(4, obj1.currentIndex());
}

tst_QTabBar::tst_QTabBar()
{
}

tst_QTabBar::~tst_QTabBar()
{
}

void tst_QTabBar::initTestCase()
{
}

void tst_QTabBar::cleanupTestCase()
{
}

void tst_QTabBar::init()
{
}

void tst_QTabBar::setIconSize_data()
{
    QTest::addColumn<int>("sizeToSet");
    QTest::addColumn<int>("expectedWidth");

    int iconDefault = qApp->style()->pixelMetric(QStyle::PM_TabBarIconSize);
    int small = qApp->style()->pixelMetric(QStyle::PM_SmallIconSize);
    int large = qApp->style()->pixelMetric(QStyle::PM_LargeIconSize);
    QTest::newRow("default") << -1 << iconDefault;
    QTest::newRow("zero") << 0 << 0;
    QTest::newRow("same as default") << iconDefault << iconDefault;
    QTest::newRow("large") << large << large;
    QTest::newRow("small") << small << small;
}

void tst_QTabBar::setIconSize()
{
    QFETCH(int, sizeToSet);
    QFETCH(int, expectedWidth);
    QTabBar tabBar;
    tabBar.setIconSize(QSize(sizeToSet, sizeToSet));
    QCOMPARE(tabBar.iconSize().width(), expectedWidth);
}

void tst_QTabBar::testCurrentChanged_data()
{
    QTest::addColumn<int>("tabToSet");
    QTest::addColumn<int>("expectedCount");

    QTest::newRow("pressAntotherTab") << 1 << 2;
    QTest::newRow("pressTheSameTab") << 0 << 1;
}

void tst_QTabBar::testCurrentChanged()
{
    QFETCH(int, tabToSet);
    QFETCH(int, expectedCount);
    QTabBar tabBar;
    QSignalSpy spy(&tabBar, SIGNAL(currentChanged(int)));
    tabBar.addTab("Tab1");
    tabBar.addTab("Tab2");
    QCOMPARE(tabBar.currentIndex(), 0);
    tabBar.setCurrentIndex(tabToSet);
    QCOMPARE(tabBar.currentIndex(), tabToSet);
    QCOMPARE(spy.count(), expectedCount);
}

void tst_QTabBar::insertAtCurrentIndex()
{
    QTabBar tabBar;
    tabBar.addTab("Tab1");
    QCOMPARE(tabBar.currentIndex(), 0);
    tabBar.insertTab(0, "Tab2");
    QCOMPARE(tabBar.currentIndex(), 1);
    tabBar.insertTab(0, "Tab3");
    QCOMPARE(tabBar.currentIndex(), 2);
    tabBar.insertTab(2, "Tab4");
    QCOMPARE(tabBar.currentIndex(), 3);
}

void tst_QTabBar::removeTab_data()
{
    QTest::addColumn<int>("currentIndex");
    QTest::addColumn<int>("deleteIndex");
    QTest::addColumn<int>("spyCount");
    QTest::addColumn<int>("finalIndex");

    QTest::newRow("deleteEnd") << 0 << 2 << 0 << 0;
    QTest::newRow("deleteEndWithIndexOnEnd") << 2 << 2 << 1 << 1;
    QTest::newRow("deleteMiddle") << 2 << 1 << 1 << 1;
    QTest::newRow("deleteMiddleOnMiddle") << 1 << 1 << 1 << 1;
}
void tst_QTabBar::removeTab()
{
    QTabBar tabbar;

    QFETCH(int, currentIndex);
    QFETCH(int, deleteIndex);
    tabbar.addTab("foo");
    tabbar.addTab("bar");
    tabbar.addTab("baz");
    tabbar.setCurrentIndex(currentIndex);
    QSignalSpy spy(&tabbar, SIGNAL(currentChanged(int)));
    tabbar.removeTab(deleteIndex);
    QTEST(spy.count(), "spyCount");
    QTEST(tabbar.currentIndex(), "finalIndex");
}

void tst_QTabBar::setElideMode_data()
{
    QTest::addColumn<int>("tabElideMode");
    QTest::addColumn<int>("expectedMode");

    QTest::newRow("default") << -128 << qApp->style()->styleHint(QStyle::SH_TabBar_ElideMode);
    QTest::newRow("explicit default") << qApp->style()->styleHint(QStyle::SH_TabBar_ElideMode)
                                      << qApp->style()->styleHint(QStyle::SH_TabBar_ElideMode);
    QTest::newRow("None") << int(Qt::ElideNone) << int(Qt::ElideNone);
    QTest::newRow("Left") << int(Qt::ElideLeft) << int(Qt::ElideLeft);
    QTest::newRow("Center") << int(Qt::ElideMiddle) << int(Qt::ElideMiddle);
    QTest::newRow("Right") << int(Qt::ElideRight) << int(Qt::ElideRight);
}

void tst_QTabBar::setElideMode()
{
    QFETCH(int, tabElideMode);
    QTabBar tabBar;
    if (tabElideMode != -128)
        tabBar.setElideMode(Qt::TextElideMode(tabElideMode));
    QTEST(int(tabBar.elideMode()), "expectedMode");
}

void tst_QTabBar::setUsesScrollButtons_data()
{
    QTest::addColumn<int>("usesArrows");
    QTest::addColumn<bool>("expectedArrows");

    QTest::newRow("default") << -128 << !qApp->style()->styleHint(QStyle::SH_TabBar_PreferNoArrows);
    QTest::newRow("explicit default")
                        << int(!qApp->style()->styleHint(QStyle::SH_TabBar_PreferNoArrows))
                        << !qApp->style()->styleHint(QStyle::SH_TabBar_PreferNoArrows);
    QTest::newRow("No") << int(false) << false;
    QTest::newRow("Yes") << int(true) << true;
}

void tst_QTabBar::setUsesScrollButtons()
{
    QFETCH(int, usesArrows);
    QTabBar tabBar;
    if (usesArrows != -128)
        tabBar.setUsesScrollButtons(usesArrows);
    QTEST(tabBar.usesScrollButtons(), "expectedArrows");

    // Make sure style sheet does not override user set mode
    tabBar.setStyleSheet("QWidget { background-color: #ABA8A6;}");
    QTEST(tabBar.usesScrollButtons(), "expectedArrows");
}

void tst_QTabBar::removeLastTab()
{
    QTabBar tabbar;
    QSignalSpy spy(&tabbar, SIGNAL(currentChanged(int)));
    int index = tabbar.addTab("foo");
    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.at(0).at(0).toInt(), index);
    spy.clear();

    tabbar.removeTab(index);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.at(0).at(0).toInt(), -1);
    spy.clear();
}

void tst_QTabBar::closeButton()
{
    QTabBar tabbar;
    QCOMPARE(tabbar.tabsClosable(), false);
    tabbar.setTabsClosable(true);
    QCOMPARE(tabbar.tabsClosable(), true);
    tabbar.addTab("foo");

    QTabBar::ButtonPosition closeSide = (QTabBar::ButtonPosition)tabbar.style()->styleHint(QStyle::SH_TabBar_CloseButtonPosition, 0, &tabbar);
    QTabBar::ButtonPosition otherSide = (closeSide == QTabBar::LeftSide ? QTabBar::RightSide : QTabBar::LeftSide);
    QVERIFY(tabbar.tabButton(0, otherSide) == 0);
    QVERIFY(tabbar.tabButton(0, closeSide) != 0);

    QAbstractButton *button = static_cast<QAbstractButton*>(tabbar.tabButton(0, closeSide));
    QVERIFY(button);
    QSignalSpy spy(&tabbar, SIGNAL(tabCloseRequested(int)));
    button->click();
    QCOMPARE(tabbar.count(), 1);
    QCOMPARE(spy.count(), 1);
}

Q_DECLARE_METATYPE(QTabBar::ButtonPosition)
void tst_QTabBar::tabButton_data()
{
    QTest::addColumn<QTabBar::ButtonPosition>("position");

    QTest::newRow("left") << QTabBar::LeftSide;
    QTest::newRow("right") << QTabBar::RightSide;
}

// QTabBar::setTabButton(index, closeSide, closeButton);
void tst_QTabBar::tabButton()
{
    QFETCH(QTabBar::ButtonPosition, position);
    QTabBar::ButtonPosition otherSide = (position == QTabBar::LeftSide ? QTabBar::RightSide : QTabBar::LeftSide);

    QTabBar tabbar;
    tabbar.resize(500, 200);
    tabbar.show();
    QTRY_VERIFY(tabbar.isVisible());

    tabbar.setTabButton(-1, position, 0);
    QVERIFY(tabbar.tabButton(-1, position) == 0);
    QVERIFY(tabbar.tabButton(0, position) == 0);

    tabbar.addTab("foo");
    QCOMPARE(tabbar.count(), 1);
    tabbar.setTabButton(0, position, 0);
    QVERIFY(tabbar.tabButton(0, position) == 0);

    QPushButton *button = new QPushButton;
    button->show();
    button->setText("hi");
    button->resize(10, 10);
    QTRY_VERIFY(button->isVisible());
    QTRY_VERIFY(button->isVisible());

    tabbar.setTabButton(0, position, button);

    QCOMPARE(tabbar.tabButton(0, position), static_cast<QWidget *>(button));
    QTRY_VERIFY(!button->isHidden());
    QVERIFY(tabbar.tabButton(0, otherSide) == 0);
    QCOMPARE(button->parent(), static_cast<QObject *>(&tabbar));
    QVERIFY(button->pos() != QPoint(0, 0));

    QPushButton *button2 = new QPushButton;
    tabbar.setTabButton(0, position, button2);
    QVERIFY(button->isHidden());
}

typedef QList<int> IntList;
Q_DECLARE_METATYPE(QTabBar::SelectionBehavior)
Q_DECLARE_METATYPE(IntList)
#define ONE(x) (IntList() << x)
void tst_QTabBar::selectionBehaviorOnRemove_data()
{
    QTest::addColumn<QTabBar::SelectionBehavior>("selectionBehavior");
    QTest::addColumn<int>("tabs");
    QTest::addColumn<IntList>("select");
    QTest::addColumn<IntList>("remove");
    QTest::addColumn<int>("expected");

    //                                               Count            select remove current
    QTest::newRow("left-1") << QTabBar::SelectLeftTab << 3 << (IntList() << 0) << ONE(0) << 0;

    QTest::newRow("left-2") << QTabBar::SelectLeftTab << 3 << (IntList() << 0) << ONE(1) << 0; // not removing current
    QTest::newRow("left-3") << QTabBar::SelectLeftTab << 3 << (IntList() << 0) << ONE(2) << 0; // not removing current
    QTest::newRow("left-4") << QTabBar::SelectLeftTab << 3 << (IntList() << 1) << ONE(0) << 0; // not removing current
    QTest::newRow("left-5") << QTabBar::SelectLeftTab << 3 << (IntList() << 1) << ONE(1) << 0;
    QTest::newRow("left-6") << QTabBar::SelectLeftTab << 3 << (IntList() << 1) << ONE(2) << 1;
    QTest::newRow("left-7") << QTabBar::SelectLeftTab << 3 << (IntList() << 2) << ONE(0) << 1; // not removing current
    QTest::newRow("left-8") << QTabBar::SelectLeftTab << 3 << (IntList() << 2) << ONE(1) << 1; // not removing current
    QTest::newRow("left-9") << QTabBar::SelectLeftTab << 3 << (IntList() << 2) << ONE(2) << 1;

    QTest::newRow("right-1") << QTabBar::SelectRightTab << 3 << (IntList() << 0) << ONE(0) << 0;
    QTest::newRow("right-2") << QTabBar::SelectRightTab << 3 << (IntList() << 0) << ONE(1) << 0; // not removing current
    QTest::newRow("right-3") << QTabBar::SelectRightTab << 3 << (IntList() << 0) << ONE(2) << 0; // not removing current
    QTest::newRow("right-4") << QTabBar::SelectRightTab << 3 << (IntList() << 1) << ONE(0) << 0; // not removing current
    QTest::newRow("right-5") << QTabBar::SelectRightTab << 3 << (IntList() << 1) << ONE(1) << 1;
    QTest::newRow("right-6") << QTabBar::SelectRightTab << 3 << (IntList() << 1) << ONE(2) << 1; // not removing current
    QTest::newRow("right-7") << QTabBar::SelectRightTab << 3 << (IntList() << 2) << ONE(0) << 1; // not removing current
    QTest::newRow("right-8") << QTabBar::SelectRightTab << 3 << (IntList() << 2) << ONE(1) << 1; // not removing current
    QTest::newRow("right-9") << QTabBar::SelectRightTab << 3 << (IntList() << 2) << ONE(2) << 1;

    QTest::newRow("previous-0") << QTabBar::SelectPreviousTab << 3 << (IntList()) << ONE(0) << 0;
    QTest::newRow("previous-1") << QTabBar::SelectPreviousTab << 3 << (IntList()) << ONE(1) << 0; // not removing current
    QTest::newRow("previous-2") << QTabBar::SelectPreviousTab << 3 << (IntList()) << ONE(2) << 0; // not removing current

    QTest::newRow("previous-3") << QTabBar::SelectPreviousTab << 3 << (IntList() << 2) << ONE(0) << 1; // not removing current
    QTest::newRow("previous-4") << QTabBar::SelectPreviousTab << 3 << (IntList() << 2) << ONE(1) << 1; // not removing current
    QTest::newRow("previous-5") << QTabBar::SelectPreviousTab << 3 << (IntList() << 2) << ONE(2) << 0;

    // go back one
    QTest::newRow("previous-6") << QTabBar::SelectPreviousTab << 4 << (IntList() << 0 << 2 << 3 << 1) << (IntList() << 1) << 2;
    // go back two
    QTest::newRow("previous-7") << QTabBar::SelectPreviousTab << 4 << (IntList() << 0 << 2 << 3 << 1) << (IntList() << 1 << 2) << 1;
    // go back three
    QTest::newRow("previous-8") << QTabBar::SelectPreviousTab << 4 << (IntList() << 0 << 2 << 3 << 1) << (IntList() << 1 << 2 << 1) << 0;

    // pick from the middle
    QTest::newRow("previous-9") << QTabBar::SelectPreviousTab << 4 << (IntList() << 0 << 2 << 3 << 1) << (IntList() << 2 << 1) << 1;

    // every other one
    QTest::newRow("previous-10") << QTabBar::SelectPreviousTab << 7 << (IntList() << 0 << 2 << 4 << 6) << (IntList() << 6 << 4) << 2;


}

void tst_QTabBar::selectionBehaviorOnRemove()
{
    QFETCH(QTabBar::SelectionBehavior, selectionBehavior);
    QFETCH(int, tabs);
    QFETCH(IntList, select);
    QFETCH(IntList, remove);
    QFETCH(int, expected);

    QTabBar tabbar;
    tabbar.setSelectionBehaviorOnRemove(selectionBehavior);
    while(--tabs >= 0)
        tabbar.addTab(QString::number(tabs));
    QCOMPARE(tabbar.currentIndex(), 0);
    while(!select.isEmpty())
        tabbar.setCurrentIndex(select.takeFirst());
    while(!remove.isEmpty())
        tabbar.removeTab(remove.takeFirst());
    QVERIFY(tabbar.count() > 0);
    QCOMPARE(tabbar.currentIndex(), expected);
}

class TabBar : public QTabBar
{
    Q_OBJECT
public:
    void callMoveTab(int from, int to){ moveTab(from, to); }
};


Q_DECLARE_METATYPE(QTabBar::Shape)
void tst_QTabBar::moveTab_data()
{
    QTest::addColumn<QTabBar::Shape>("shape");
    QTest::addColumn<int>("tabs");
    QTest::addColumn<int>("from");
    QTest::addColumn<int>("to");

    QTest::newRow("null-0") << QTabBar::RoundedNorth << 0 << -1 << -1;
    QTest::newRow("null-1") << QTabBar::RoundedEast  << 0 << -1 << -1;
    QTest::newRow("null-2") << QTabBar::RoundedEast  << 1 << 0 << 0;

    QTest::newRow("two-0") << QTabBar::RoundedNorth << 2 << 0 << 1;
    QTest::newRow("two-1") << QTabBar::RoundedNorth << 2 << 1 << 0;

    QTest::newRow("five-0") << QTabBar::RoundedNorth << 5 << 1 << 3; // forward
    QTest::newRow("five-1") << QTabBar::RoundedNorth << 5 << 3 << 1; // reverse

    QTest::newRow("five-2") << QTabBar::RoundedNorth << 5 << 0 << 4; // forward
    QTest::newRow("five-3") << QTabBar::RoundedNorth << 5 << 1 << 4; // forward
    QTest::newRow("five-4") << QTabBar::RoundedNorth << 5 << 3 << 4; // forward
}

void tst_QTabBar::moveTab()
{
    QFETCH(QTabBar::Shape, shape);
    QFETCH(int, tabs);
    QFETCH(int, from);
    QFETCH(int, to);

    TabBar bar;
    bar.setShape(shape);
    while(--tabs >= 0)
        bar.addTab(QString::number(tabs));
    bar.callMoveTab(from, to);
}


class MyTabBar : public QTabBar
{
    Q_OBJECT
public slots:
    void onCurrentChanged()
    {
        //we just want this to be done once
        disconnect(this, SIGNAL(currentChanged(int)), this, SLOT(onCurrentChanged()));
        removeTab(0);
    }
};

void tst_QTabBar::task251184_removeTab()
{
    MyTabBar bar;
    bar.addTab("bar1");
    bar.addTab("bar2");
    QCOMPARE(bar.count(), 2);
    QCOMPARE(bar.currentIndex(), 0);

    bar.connect(&bar, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged()));
    bar.setCurrentIndex(1);

    QCOMPARE(bar.count(), 1);
    QCOMPARE(bar.currentIndex(), 0);
    QCOMPARE(bar.tabText(bar.currentIndex()), QString("bar2"));
}


class TitleChangeTabBar : public QTabBar
{
    Q_OBJECT

    QTimer timer;
    int count;

public:
    TitleChangeTabBar(QWidget * parent = 0) : QTabBar(parent), count(0)
    {
        setMovable(true);
        addTab("0");
        connect(&timer, SIGNAL(timeout()), this, SLOT(updateTabText()));
        timer.start(1);
    }

public slots:
    void updateTabText()
    {
        count++;
        setTabText(0, QString("%1").arg(count));
    }
};

void tst_QTabBar::changeTitleWhileDoubleClickingTab()
{
    TitleChangeTabBar bar;
    QPoint tabPos = bar.tabRect(0).center();

    for(int i=0; i < 10; i++)
        QTest::mouseDClick(&bar, Qt::LeftButton, 0, tabPos);
}

QTEST_MAIN(tst_QTabBar)
#include "tst_qtabbar.moc"