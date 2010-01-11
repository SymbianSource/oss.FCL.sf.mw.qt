/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicssceneevent.h>
#include <qgraphicsview.h>
#include <qstyleoption.h>
#include "../../shared/util.h"

class tst_QGraphicsObject : public QObject {
    Q_OBJECT

public slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void pos();
    void x();
    void y();
    void z();
    void opacity();
    void enabled();
    void visible();
};


// This will be called before the first test function is executed.
// It is only called once.
void tst_QGraphicsObject::initTestCase()
{
}

// This will be called after the last test function is executed.
// It is only called once.
void tst_QGraphicsObject::cleanupTestCase()
{
}

// This will be called before each test function is executed.
void tst_QGraphicsObject::init()
{
}

// This will be called after every test function.
void tst_QGraphicsObject::cleanup()
{
}


class MyGraphicsObject : public QGraphicsObject
{
public:
    MyGraphicsObject() : QGraphicsObject() {}
    virtual QRectF boundingRect() const { return QRectF(); }
    virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) {}
};

void tst_QGraphicsObject::pos()
{
    MyGraphicsObject object;
    QSignalSpy xSpy(&object, SIGNAL(xChanged()));
    QSignalSpy ySpy(&object, SIGNAL(yChanged()));
    QVERIFY(object.pos() == QPointF(0, 0));
    object.setPos(10, 10);
    QCOMPARE(xSpy.count(), 1);
    QCOMPARE(ySpy.count(), 1);

    QVERIFY(object.pos() == QPointF(10,10));

    object.setPos(10, 10);
    QCOMPARE(xSpy.count(), 1);
    QCOMPARE(ySpy.count(), 1);

    object.setProperty("pos", QPointF(0, 0));
    QCOMPARE(xSpy.count(), 2);
    QCOMPARE(ySpy.count(), 2);
    QVERIFY(object.property("pos") == QPointF(0,0));

    object.setProperty("pos", QPointF(10, 0));
    QCOMPARE(xSpy.count(), 3);
    QCOMPARE(ySpy.count(), 2);
    QVERIFY(object.property("pos") == QPointF(10,0));

    object.setProperty("pos", QPointF(10, 10));
    QCOMPARE(xSpy.count(), 3);
    QCOMPARE(ySpy.count(), 3);
    QVERIFY(object.property("pos") == QPointF(10, 10));
}

void tst_QGraphicsObject::x()
{
    MyGraphicsObject object;
    QSignalSpy xSpy(&object, SIGNAL(xChanged()));
    QSignalSpy ySpy(&object, SIGNAL(yChanged()));
    QVERIFY(object.pos() == QPointF(0, 0));
    object.setX(10);
    QCOMPARE(xSpy.count(), 1);
    QCOMPARE(ySpy.count(), 0);

    QVERIFY(object.pos() == QPointF(10, 0));
    QVERIFY(object.x() == 10);

    object.setX(10);
    QCOMPARE(xSpy.count(), 1);
    QCOMPARE(ySpy.count(), 0);

    object.setProperty("x", 0);
    QCOMPARE(xSpy.count(), 2);
    QCOMPARE(ySpy.count(), 0);
    QVERIFY(object.property("x") == 0);
}

void tst_QGraphicsObject::y()
{
    MyGraphicsObject object;
    QSignalSpy xSpy(&object, SIGNAL(xChanged()));
    QSignalSpy ySpy(&object, SIGNAL(yChanged()));
    QVERIFY(object.pos() == QPointF(0, 0));
    object.setY(10);
    QCOMPARE(xSpy.count(), 0);
    QCOMPARE(ySpy.count(), 1);

    QVERIFY(object.pos() == QPointF(0, 10));
    QVERIFY(object.y() == 10);

    object.setY(10);
    QCOMPARE(xSpy.count(), 0);
    QCOMPARE(ySpy.count(), 1);

    object.setProperty("y", 0);
    QCOMPARE(xSpy.count(), 0);
    QCOMPARE(ySpy.count(), 2);
    QVERIFY(object.property("y") == 0);
}

void tst_QGraphicsObject::z()
{
    MyGraphicsObject object;
    QSignalSpy zSpy(&object, SIGNAL(zChanged()));
    QVERIFY(object.zValue() == 0);
    object.setZValue(10);
    QCOMPARE(zSpy.count(), 1);

    QVERIFY(object.zValue() == 10);

    object.setZValue(10);
    QCOMPARE(zSpy.count(), 1);

    object.setProperty("z", 0);
    QCOMPARE(zSpy.count(), 2);
    QVERIFY(object.property("z") == 0);
}

void tst_QGraphicsObject::opacity()
{
    MyGraphicsObject object;
    QSignalSpy spy(&object, SIGNAL(opacityChanged()));
    QVERIFY(object.opacity() == 1.);
    object.setOpacity(0);
    QCOMPARE(spy.count(), 1);

    QVERIFY(object.opacity() == 0.);

    object.setOpacity(0);
    QCOMPARE(spy.count(), 1);

    object.setProperty("opacity", .5);
    QCOMPARE(spy.count(), 2);
    QVERIFY(object.property("opacity") == .5);
}

void tst_QGraphicsObject::enabled()
{
    MyGraphicsObject object;
    QSignalSpy spy(&object, SIGNAL(enabledChanged()));
    QVERIFY(object.isEnabled() == true);
    object.setEnabled(false);
    QCOMPARE(spy.count(), 1);

    QVERIFY(object.isEnabled() == false);

    object.setEnabled(false);
    QCOMPARE(spy.count(), 1);

    object.setProperty("enabled", true);
    QCOMPARE(spy.count(), 2);
    QVERIFY(object.property("enabled") == true);
}

void tst_QGraphicsObject::visible()
{
    MyGraphicsObject object;
    QSignalSpy spy(&object, SIGNAL(visibleChanged()));
    QVERIFY(object.isVisible() == true);
    object.setVisible(false);
    QCOMPARE(spy.count(), 1);

    QVERIFY(object.isVisible() == false);

    object.setVisible(false);
    QCOMPARE(spy.count(), 1);

    object.setProperty("visible", true);
    QCOMPARE(spy.count(), 2);
    QVERIFY(object.property("visible") == true);
}


QTEST_MAIN(tst_QGraphicsObject)
#include "tst_qgraphicsobject.moc"

