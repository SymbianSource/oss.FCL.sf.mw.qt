/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
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

#ifndef QDECLARATIVEBORDERIMAGE_P_H
#define QDECLARATIVEBORDERIMAGE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "private/qdeclarativeimagebase_p_p.h"
#include "private/qdeclarativescalegrid_p_p.h"

QT_BEGIN_NAMESPACE

class QNetworkReply;
class QDeclarativeBorderImagePrivate : public QDeclarativeImageBasePrivate
{
    Q_DECLARE_PUBLIC(QDeclarativeBorderImage)

public:
    QDeclarativeBorderImagePrivate()
      : border(0), sciReply(0),
        horizontalTileMode(QDeclarativeBorderImage::Stretch),
        verticalTileMode(QDeclarativeBorderImage::Stretch),
        redirectCount(0)
    {
    }

    ~QDeclarativeBorderImagePrivate()
    {
    }


    QDeclarativeScaleGrid *getScaleGrid()
    {
        Q_Q(QDeclarativeBorderImage);
        if (!border) {
            border = new QDeclarativeScaleGrid(q);
            static int borderChangedSignalIdx = -1;
            static int doUpdateSlotIdx = -1;
            if (borderChangedSignalIdx < 0)
                borderChangedSignalIdx = QDeclarativeScaleGrid::staticMetaObject.indexOfSignal("borderChanged()");
            if (doUpdateSlotIdx < 0)
                doUpdateSlotIdx = QDeclarativeBorderImage::staticMetaObject.indexOfSlot("doUpdate()");
            QMetaObject::connect(border, borderChangedSignalIdx, q, doUpdateSlotIdx);
        }
        return border;
    }

    QDeclarativeScaleGrid *border;
    QUrl sciurl;
    QNetworkReply *sciReply;
    QDeclarativeBorderImage::TileMode horizontalTileMode;
    QDeclarativeBorderImage::TileMode verticalTileMode;
    int redirectCount;
};

QT_END_NAMESPACE

#endif // QDECLARATIVEBORDERIMAGE_P_H
