/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSRangeException.h"

#include "KURL.h"
#include "RangeException.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSRangeException);

/* Hash table */

static const HashTableValue JSRangeExceptionTableValues[5] =
{
    { "code", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionCode, (intptr_t)0 },
    { "name", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionName, (intptr_t)0 },
    { "message", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionMessage, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsRangeExceptionConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSRangeExceptionTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSRangeExceptionTableValues, 0 };
#else
    { 10, 7, JSRangeExceptionTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSRangeExceptionConstructorTableValues[3] =
{
    { "BAD_BOUNDARYPOINTS_ERR", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionBAD_BOUNDARYPOINTS_ERR, (intptr_t)0 },
    { "INVALID_NODE_TYPE_ERR", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionINVALID_NODE_TYPE_ERR, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSRangeExceptionConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1, JSRangeExceptionConstructorTableValues, 0 };
#else
    { 4, 3, JSRangeExceptionConstructorTableValues, 0 };
#endif

class JSRangeExceptionConstructor : public DOMConstructorObject {
public:
    JSRangeExceptionConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSRangeExceptionConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSRangeExceptionPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSRangeExceptionConstructor::s_info = { "RangeExceptionConstructor", 0, &JSRangeExceptionConstructorTable, 0 };

bool JSRangeExceptionConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSRangeExceptionConstructor, DOMObject>(exec, &JSRangeExceptionConstructorTable, this, propertyName, slot);
}

bool JSRangeExceptionConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSRangeExceptionConstructor, DOMObject>(exec, &JSRangeExceptionConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSRangeExceptionPrototypeTableValues[4] =
{
    { "BAD_BOUNDARYPOINTS_ERR", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionBAD_BOUNDARYPOINTS_ERR, (intptr_t)0 },
    { "INVALID_NODE_TYPE_ERR", DontDelete|ReadOnly, (intptr_t)jsRangeExceptionINVALID_NODE_TYPE_ERR, (intptr_t)0 },
    { "toString", DontDelete|DontEnum|Function, (intptr_t)jsRangeExceptionPrototypeFunctionToString, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSRangeExceptionPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSRangeExceptionPrototypeTableValues, 0 };
#else
    { 8, 7, JSRangeExceptionPrototypeTableValues, 0 };
#endif

const ClassInfo JSRangeExceptionPrototype::s_info = { "RangeExceptionPrototype", 0, &JSRangeExceptionPrototypeTable, 0 };

JSObject* JSRangeExceptionPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSRangeException>(exec, globalObject);
}

bool JSRangeExceptionPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSRangeExceptionPrototype, JSObject>(exec, &JSRangeExceptionPrototypeTable, this, propertyName, slot);
}

bool JSRangeExceptionPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticPropertyDescriptor<JSRangeExceptionPrototype, JSObject>(exec, &JSRangeExceptionPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSRangeException::s_info = { "RangeException", 0, &JSRangeExceptionTable, 0 };

JSRangeException::JSRangeException(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<RangeException> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSRangeException::~JSRangeException()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSRangeException::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSRangeExceptionPrototype(JSRangeExceptionPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSRangeException::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSRangeException, Base>(exec, &JSRangeExceptionTable, this, propertyName, slot);
}

bool JSRangeException::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSRangeException, Base>(exec, &JSRangeExceptionTable, this, propertyName, descriptor);
}

JSValue jsRangeExceptionCode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSRangeException* castedThis = static_cast<JSRangeException*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    RangeException* imp = static_cast<RangeException*>(castedThis->impl());
    return jsNumber(exec, imp->code());
}

JSValue jsRangeExceptionName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSRangeException* castedThis = static_cast<JSRangeException*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    RangeException* imp = static_cast<RangeException*>(castedThis->impl());
    return jsString(exec, imp->name());
}

JSValue jsRangeExceptionMessage(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSRangeException* castedThis = static_cast<JSRangeException*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    RangeException* imp = static_cast<RangeException*>(castedThis->impl());
    return jsString(exec, imp->message());
}

JSValue jsRangeExceptionConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSRangeException* domObject = static_cast<JSRangeException*>(asObject(slot.slotBase()));
    return JSRangeException::getConstructor(exec, domObject->globalObject());
}
JSValue JSRangeException::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSRangeExceptionConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsRangeExceptionPrototypeFunctionToString(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSRangeException::s_info))
        return throwError(exec, TypeError);
    JSRangeException* castedThisObj = static_cast<JSRangeException*>(asObject(thisValue));
    RangeException* imp = static_cast<RangeException*>(castedThisObj->impl());


    JSC::JSValue result = jsString(exec, imp->toString());
    return result;
}

// Constant getters

JSValue jsRangeExceptionBAD_BOUNDARYPOINTS_ERR(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsRangeExceptionINVALID_NODE_TYPE_ERR(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, RangeException* object)
{
    return getDOMObjectWrapper<JSRangeException>(exec, globalObject, object);
}
RangeException* toRangeException(JSC::JSValue value)
{
    return value.inherits(&JSRangeException::s_info) ? static_cast<JSRangeException*>(asObject(value))->impl() : 0;
}

}
