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

#include "gestures.h"

#include <QTouchEvent>

Qt::GestureType ThreeFingerSlideGesture::Type = Qt::CustomGesture;

QGesture *ThreeFingerSlideGestureRecognizer::createGesture(QObject *)
{
    return new ThreeFingerSlideGesture;
}

QGestureRecognizer::Result ThreeFingerSlideGestureRecognizer::filterEvent(QGesture *state, QObject *, QEvent *event)
{
    ThreeFingerSlideGesture *d = static_cast<ThreeFingerSlideGesture *>(state);
    QGestureRecognizer::Result result;
    switch (event->type()) {
    case QEvent::TouchBegin:
        result = QGestureRecognizer::MaybeGesture;
    case QEvent::TouchEnd:
        if (d->gestureFired)
            result = QGestureRecognizer::GestureFinished;
        else
            result = QGestureRecognizer::NotGesture;
    case QEvent::TouchUpdate:
        if (d->state() != Qt::NoGesture) {
            QTouchEvent *ev = static_cast<QTouchEvent*>(event);
            if (ev->touchPoints().size() == 3) {
                d->gestureFired = true;
                result = QGestureRecognizer::GestureTriggered;
            } else {
                result = QGestureRecognizer::MaybeGesture;
                for (int i = 0; i < ev->touchPoints().size(); ++i) {
                    const QTouchEvent::TouchPoint &pt = ev->touchPoints().at(i);
                    const int distance = (pt.pos().toPoint() - pt.startPos().toPoint()).manhattanLength();
                    if (distance > 20) {
                        result = QGestureRecognizer::NotGesture;
                    }
                }
            }
        } else {
            result = QGestureRecognizer::NotGesture;
        }

        break;
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseMove:
        if (d->state() != Qt::NoGesture)
            result = QGestureRecognizer::Ignore;
        else
            result = QGestureRecognizer::NotGesture;
        break;
    default:
        result = QGestureRecognizer::Ignore;
        break;
    }
    return result;
}

void ThreeFingerSlideGestureRecognizer::reset(QGesture *state)
{
    static_cast<ThreeFingerSlideGesture *>(state)->gestureFired = false;
    QGestureRecognizer::reset(state);
}


QGesture *RotateGestureRecognizer::createGesture(QObject *)
{
    return new QGesture;
}

QGestureRecognizer::Result RotateGestureRecognizer::filterEvent(QGesture *, QObject *, QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:
    case QEvent::TouchEnd:
    case QEvent::TouchUpdate:
        break;
    default:
        break;
    }
    return QGestureRecognizer::Ignore;
}

void RotateGestureRecognizer::reset(QGesture *state)
{
    QGestureRecognizer::reset(state);
}

#include "moc_gestures.cpp"
