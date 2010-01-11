/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtScript module of the Qt Toolkit.
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

#ifndef QSCRIPTVALUE_P_H
#define QSCRIPTVALUE_P_H

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

#include <QtCore/qobjectdefs.h>

#include "wtf/Platform.h"
#include "JSValue.h"

QT_BEGIN_NAMESPACE

class QString;
class QScriptEnginePrivate;

class QScriptValue;
class QScriptValuePrivate
{
    Q_DISABLE_COPY(QScriptValuePrivate)
public:
    inline void* operator new(size_t, QScriptEnginePrivate*);
    inline void operator delete(void*);

    enum Type {
        JavaScriptCore,
        Number,
        String
    };

    inline QScriptValuePrivate(QScriptEnginePrivate*);
    inline ~QScriptValuePrivate();

    inline void initFrom(JSC::JSValue value);
    inline void initFrom(qsreal value);
    inline void initFrom(const QString &value);

    inline bool isJSC() const;
    inline bool isObject() const;

    QVariant &variantValue() const;
    void setVariantValue(const QVariant &value);

    static inline QScriptValuePrivate *get(const QScriptValue &q)
    {
        return q.d_ptr.data();
    }

    static inline QScriptValue toPublic(QScriptValuePrivate *d)
    {
        return QScriptValue(d);
    }

    static inline QScriptEnginePrivate *getEngine(const QScriptValue &q)
    {
        if (!q.d_ptr)
            return 0;
        return q.d_ptr->engine;
    }

    inline QScriptValue property(const JSC::Identifier &id, int resolveMode) const;
    QScriptValue propertyHelper(const JSC::Identifier &id, int resolveMode) const;
    inline QScriptValue property(quint32 index, int resolveMode) const;
    QScriptValue propertyHelper(quint32, int resolveMode) const;
    inline QScriptValue property(const QString &, int resolveMode) const;
    void setProperty(const JSC::Identifier &id, const QScriptValue &value,
                     const QScriptValue::PropertyFlags &flags);
    QScriptValue::PropertyFlags propertyFlags(
        const JSC::Identifier &id, const QScriptValue::ResolveFlags &mode) const;

    void detachFromEngine();

    qint64 objectId()
    {
        if ( (type == JavaScriptCore) && (engine) )
            return (qint64)jscValue.asCell();
        else
            return -1;
    }

    static inline void saveException(JSC::ExecState*, JSC::JSValue*);
    static inline void restoreException(JSC::ExecState*, JSC::JSValue);

    QScriptEnginePrivate *engine;
    Type type;
    JSC::JSValue jscValue;
    qsreal numberValue;
    QString stringValue;

    // linked list of engine's script values
    QScriptValuePrivate *prev;
    QScriptValuePrivate *next;

    QBasicAtomicInt ref;
};

inline QScriptValuePrivate::QScriptValuePrivate(QScriptEnginePrivate *e)
    : engine(e), prev(0), next(0)
{
    ref = 0;
}

inline bool QScriptValuePrivate::isJSC() const
{
    return (type == JavaScriptCore);
}

inline bool QScriptValuePrivate::isObject() const
{
    return isJSC() && jscValue && jscValue.isObject();
}

// Rest of inline functions implemented in qscriptengine_p.h

QT_END_NAMESPACE

#endif
