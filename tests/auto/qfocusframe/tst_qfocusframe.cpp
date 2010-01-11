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

#include <qcoreapplication.h>
#include <qdebug.h>
#include <qfocusframe.h>


//TESTED_CLASS=
//TESTED_FILES=

class tst_QFocusFrame : public QObject
{
Q_OBJECT

public:
    tst_QFocusFrame();
    virtual ~tst_QFocusFrame();

private slots:
    void getSetCheck();
};

tst_QFocusFrame::tst_QFocusFrame()
{
}

tst_QFocusFrame::~tst_QFocusFrame()
{
}

// Testing get/set functions
void tst_QFocusFrame::getSetCheck()
{
    QFocusFrame *obj1 = new QFocusFrame();
    // QWidget * QFocusFrame::widget()
    // void QFocusFrame::setWidget(QWidget *)
    QWidget var1;
    QWidget *var2 = new QWidget(&var1);
    obj1->setWidget(var2);
    QCOMPARE(var2, obj1->widget());
    obj1->setWidget((QWidget *)0);
    QCOMPARE((QWidget *)0, obj1->widget());
    delete obj1;
}

QTEST_MAIN(tst_QFocusFrame)
#include "tst_qfocusframe.moc"
