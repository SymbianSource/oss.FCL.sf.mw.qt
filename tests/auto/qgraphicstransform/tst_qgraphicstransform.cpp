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
#include <qgraphicstransform.h>
#include "../../shared/util.h"

class tst_QGraphicsTransform : public QObject {
    Q_OBJECT

public slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void scale();
    void rotation();
    void rotation3d_data();
    void rotation3d();
};


// This will be called before the first test function is executed.
// It is only called once.
void tst_QGraphicsTransform::initTestCase()
{
}

// This will be called after the last test function is executed.
// It is only called once.
void tst_QGraphicsTransform::cleanupTestCase()
{
}

// This will be called before each test function is executed.
void tst_QGraphicsTransform::init()
{
}

// This will be called after every test function.
void tst_QGraphicsTransform::cleanup()
{
}

static QTransform transform2D(const QGraphicsTransform& t)
{
    QMatrix4x4 m;
    t.applyTo(&m);
    return m.toTransform(0);
}

void tst_QGraphicsTransform::scale()
{
    QGraphicsScale scale;

    // check initial conditions
    QCOMPARE(scale.xScale(), qreal(1));
    QCOMPARE(scale.yScale(), qreal(1));
    QCOMPARE(scale.zScale(), qreal(1));
    QCOMPARE(scale.origin(), QVector3D(0, 0, 0));

    scale.setOrigin(QVector3D(10, 10, 0));

    QCOMPARE(scale.xScale(), qreal(1));
    QCOMPARE(scale.yScale(), qreal(1));
    QCOMPARE(scale.zScale(), qreal(1));
    QCOMPARE(scale.origin(), QVector3D(10, 10, 0));

    QMatrix4x4 t;
    scale.applyTo(&t);

    QCOMPARE(t, QMatrix4x4());
    QCOMPARE(transform2D(scale), QTransform());

    scale.setXScale(10);
    scale.setOrigin(QVector3D(0, 0, 0));

    QCOMPARE(scale.xScale(), qreal(10));
    QCOMPARE(scale.yScale(), qreal(1));
    QCOMPARE(scale.zScale(), qreal(1));
    QCOMPARE(scale.origin(), QVector3D(0, 0, 0));

    QTransform res;
    res.scale(10, 1);

    QCOMPARE(transform2D(scale), res);
    QCOMPARE(transform2D(scale).map(QPointF(10, 10)), QPointF(100, 10));

    scale.setOrigin(QVector3D(10, 10, 0));
    QCOMPARE(transform2D(scale).map(QPointF(10, 10)), QPointF(10, 10));
    QCOMPARE(transform2D(scale).map(QPointF(11, 10)), QPointF(20, 10));

    scale.setYScale(2);
    scale.setZScale(4.5);
    scale.setOrigin(QVector3D(1, 2, 3));

    QCOMPARE(scale.xScale(), qreal(10));
    QCOMPARE(scale.yScale(), qreal(2));
    QCOMPARE(scale.zScale(), qreal(4.5));
    QCOMPARE(scale.origin(), QVector3D(1, 2, 3));

    QMatrix4x4 t2;
    scale.applyTo(&t2);

    QCOMPARE(t2.map(QVector3D(4, 5, 6)), QVector3D(31, 8, 16.5));

    // Because the origin has a non-zero z, mapping (4, 5) in 2D
    // will introduce a projective component into the result.
    QTransform t3 = t2.toTransform();
    QCOMPARE(t3.map(QPointF(4, 5)), QPointF(31 / t3.m33(), 8 / t3.m33()));
}

// QMatrix4x4 uses float internally, whereas QTransform uses qreal.
// This can lead to issues with qFuzzyCompare() where it uses double
// precision to compare values that have no more than float precision
// after conversion from QMatrix4x4 to QTransform.  The following
// definitions correct for the difference.
static inline bool fuzzyCompare(qreal p1, qreal p2)
{
    // increase delta on small machines using float instead of double
    if (sizeof(qreal) == sizeof(float))
        return (qAbs(p1 - p2) <= 0.00002f * qMin(qAbs(p1), qAbs(p2)));
    else
        return (qAbs(p1 - p2) <= 0.00001f * qMin(qAbs(p1), qAbs(p2)));
}
static bool fuzzyCompare(const QTransform& t1, const QTransform& t2)
{
    return fuzzyCompare(t1.m11(), t2.m11()) &&
           fuzzyCompare(t1.m12(), t2.m12()) &&
           fuzzyCompare(t1.m13(), t2.m13()) &&
           fuzzyCompare(t1.m21(), t2.m21()) &&
           fuzzyCompare(t1.m22(), t2.m22()) &&
           fuzzyCompare(t1.m23(), t2.m23()) &&
           fuzzyCompare(t1.m31(), t2.m31()) &&
           fuzzyCompare(t1.m32(), t2.m32()) &&
           fuzzyCompare(t1.m33(), t2.m33());
}

void tst_QGraphicsTransform::rotation()
{
    QGraphicsRotation rotation;
    QCOMPARE(rotation.axis(), QVector3D(0, 0, 1));
    QCOMPARE(rotation.origin(), QVector3D(0, 0, 0));
    QCOMPARE(rotation.angle(), (qreal)0);

    rotation.setOrigin(QVector3D(10, 10, 0));

    QCOMPARE(rotation.axis(), QVector3D(0, 0, 1));
    QCOMPARE(rotation.origin(), QVector3D(10, 10, 0));
    QCOMPARE(rotation.angle(), (qreal)0);

    QMatrix4x4 t;
    rotation.applyTo(&t);

    QCOMPARE(t, QMatrix4x4());
    QCOMPARE(transform2D(rotation), QTransform());

    rotation.setAngle(40);
    rotation.setOrigin(QVector3D(0, 0, 0));

    QCOMPARE(rotation.axis(), QVector3D(0, 0, 1));
    QCOMPARE(rotation.origin(), QVector3D(0, 0, 0));
    QCOMPARE(rotation.angle(), (qreal)40);

    QTransform res;
    res.rotate(40);

    QVERIFY(fuzzyCompare(transform2D(rotation), res));

    rotation.setOrigin(QVector3D(10, 10, 0));
    rotation.setAngle(90);
    QCOMPARE(transform2D(rotation).map(QPointF(10, 10)), QPointF(10, 10));
    QCOMPARE(transform2D(rotation).map(QPointF(20, 10)), QPointF(10, 20));
}

Q_DECLARE_METATYPE(Qt::Axis);
void tst_QGraphicsTransform::rotation3d_data()
{
    QTest::addColumn<Qt::Axis>("axis");
    QTest::addColumn<qreal>("angle");

    for (int angle = 0; angle <= 360; angle++) {
        QTest::newRow("test rotation on X") << Qt::XAxis << qreal(angle);
        QTest::newRow("test rotation on Y") << Qt::YAxis << qreal(angle);
        QTest::newRow("test rotation on Z") << Qt::ZAxis << qreal(angle);
    }
}

void tst_QGraphicsTransform::rotation3d()
{
    QFETCH(Qt::Axis, axis);
    QFETCH(qreal, angle);

    QGraphicsRotation rotation;
    rotation.setAxis(axis);

    QMatrix4x4 t;
    rotation.applyTo(&t);

    QVERIFY(t.isIdentity());
    QVERIFY(transform2D(rotation).isIdentity());

    rotation.setAngle(angle);

    // QGraphicsRotation uses a correct mathematical rotation in 3D.
    // QTransform's Qt::YAxis rotation is inverted from the mathematical
    // version of rotation.  We correct for that here.
    QTransform expected;
    if (axis == Qt::YAxis && angle != 180.)
        expected.rotate(-angle, axis);
    else
        expected.rotate(angle, axis);

    QVERIFY(fuzzyCompare(transform2D(rotation), expected));

    //now let's check that a null vector will not change the transform
    rotation.setAxis(QVector3D(0, 0, 0));
    rotation.setOrigin(QVector3D(10, 10, 0));

    t.setIdentity();
    rotation.applyTo(&t);

    QVERIFY(t.isIdentity());
    QVERIFY(transform2D(rotation).isIdentity());

    rotation.setAngle(angle);

    QVERIFY(t.isIdentity());
    QVERIFY(transform2D(rotation).isIdentity());

    rotation.setOrigin(QVector3D(0, 0, 0));

    QVERIFY(t.isIdentity());
    QVERIFY(transform2D(rotation).isIdentity());
}


QTEST_MAIN(tst_QGraphicsTransform)
#include "tst_qgraphicstransform.moc"

