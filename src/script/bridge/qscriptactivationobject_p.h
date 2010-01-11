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

#ifndef QSCRIPTACTIVATIONOBJECT_P_H
#define QSCRIPTACTIVATIONOBJECT_P_H

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

#include "JSVariableObject.h"

QT_BEGIN_NAMESPACE

namespace QScript
{

class QScriptActivationObject : public JSC::JSVariableObject {
public:
    QScriptActivationObject(JSC::ExecState *callFrame, JSC::JSObject *delegate = 0);
    virtual ~QScriptActivationObject();
    virtual bool isDynamicScope() const { return true; }

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getPropertyAttributes(JSC::ExecState*, const JSC::Identifier&, unsigned&) const;
    virtual void getOwnPropertyNames(JSC::ExecState*, JSC::PropertyNameArray&, bool includeNonEnumerable = false);

    virtual void putWithAttributes(JSC::ExecState *exec, const JSC::Identifier &propertyName, JSC::JSValue value, unsigned attributes);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue value, JSC::PutPropertySlot&);
    virtual void put(JSC::ExecState*, unsigned propertyName, JSC::JSValue value);

    virtual bool deleteProperty(JSC::ExecState*, const JSC::Identifier& propertyName, bool checkDontDelete = true);

    virtual void defineGetter(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSObject* getterFunction);
    virtual void defineSetter(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSObject* setterFunction);
    virtual JSC::JSValue lookupGetter(JSC::ExecState*, const JSC::Identifier& propertyName);
    virtual JSC::JSValue lookupSetter(JSC::ExecState*, const JSC::Identifier& propertyName);

    virtual const JSC::ClassInfo* classInfo() const { return &info; }
    static const JSC::ClassInfo info;

    struct QScriptActivationObjectData : public JSVariableObjectData {
        QScriptActivationObjectData(JSC::Register* registers, JSC::JSObject *dlg)
            : JSVariableObjectData(&symbolTable, registers),
              delegate(dlg)
        { }
        JSC::SymbolTable symbolTable;
        JSC::JSObject *delegate;
    };

    JSC::JSObject *delegate() const
    { return d_ptr()->delegate; }
    void setDelegate(JSC::JSObject *delegate)
    { d_ptr()->delegate = delegate; }

    QScriptActivationObjectData *d_ptr() const { return static_cast<QScriptActivationObjectData *>(d); }
};

} // namespace QScript

QT_END_NAMESPACE

#endif
