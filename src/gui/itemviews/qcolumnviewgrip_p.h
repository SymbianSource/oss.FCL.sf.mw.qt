/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
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

#ifndef QCOLUMNVIEWGRIP_P_H
#define QCOLUMNVIEWGRIP_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <private/qwidget_p.h>

#ifndef QT_NO_QCOLUMNVIEW

QT_BEGIN_NAMESPACE

class QColumnViewGripPrivate;

class Q_AUTOTEST_EXPORT QColumnViewGrip : public QWidget {

Q_OBJECT

Q_SIGNALS:
    void gripMoved(int offset);

public:
    explicit QColumnViewGrip(QWidget *parent = 0);
    ~QColumnViewGrip();
    int moveGrip(int offset);

protected:
    QColumnViewGrip(QColumnViewGripPrivate &, QWidget *parent = 0, Qt::WFlags f = 0);
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Q_DECLARE_PRIVATE(QColumnViewGrip)
    Q_DISABLE_COPY(QColumnViewGrip)
};

class QColumnViewGripPrivate : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QColumnViewGrip)

public:
    QColumnViewGripPrivate();
    ~QColumnViewGripPrivate() {}

    int originalXLocation;
};

QT_END_NAMESPACE

#endif // QT_NO_QCOLUMNVIEW

#endif //QCOLUMNVIEWGRIP_P_H
