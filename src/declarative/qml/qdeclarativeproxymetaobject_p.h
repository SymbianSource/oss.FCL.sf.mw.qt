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

#ifndef QDECLARATIVEPROXYMETAOBJECT_P_H
#define QDECLARATIVEPROXYMETAOBJECT_P_H

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

#include "private/qmetaobjectbuilder_p.h"
#include "qdeclarative.h"

#include <QtCore/QMetaObject>
#include <QtCore/QObject>

#include <private/qobject_p.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Declarative)

class QDeclarativeProxyMetaObject : public QAbstractDynamicMetaObject
{
public:
    struct ProxyData {
        typedef QObject *(*CreateFunc)(QObject *);
        QMetaObject *metaObject;
        CreateFunc createFunc;
        int propertyOffset;
        int methodOffset;
    };

    QDeclarativeProxyMetaObject(QObject *, QList<ProxyData> *);
    virtual ~QDeclarativeProxyMetaObject();

protected:
    virtual int metaCall(QMetaObject::Call _c, int _id, void **_a);

private:
    QList<ProxyData> *metaObjects;
    QObject **proxies;

    QAbstractDynamicMetaObject *parent;
    QObject *object;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QDECLARATIVEPROXYMETAOBJECT_P_H

