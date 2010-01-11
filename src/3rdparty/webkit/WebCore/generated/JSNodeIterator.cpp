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
#include "JSNodeIterator.h"

#include "JSNode.h"
#include "JSNodeFilter.h"
#include "Node.h"
#include "NodeFilter.h"
#include "NodeIterator.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSNodeIterator);

/* Hash table */

static const HashTableValue JSNodeIteratorTableValues[8] =
{
    { "root", DontDelete|ReadOnly, (intptr_t)jsNodeIteratorRoot, (intptr_t)0 },
    { "whatToShow", DontDelete|ReadOnly, (intptr_t)jsNodeIteratorWhatToShow, (intptr_t)0 },
    { "filter", DontDelete|ReadOnly, (intptr_t)jsNodeIteratorFilter, (intptr_t)0 },
    { "expandEntityReferences", DontDelete|ReadOnly, (intptr_t)jsNodeIteratorExpandEntityReferences, (intptr_t)0 },
    { "referenceNode", DontDelete|ReadOnly, (intptr_t)jsNodeIteratorReferenceNode, (intptr_t)0 },
    { "pointerBeforeReferenceNode", DontDelete|ReadOnly, (intptr_t)jsNodeIteratorPointerBeforeReferenceNode, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsNodeIteratorConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSNodeIteratorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 255, JSNodeIteratorTableValues, 0 };
#else
    { 18, 15, JSNodeIteratorTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSNodeIteratorConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSNodeIteratorConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSNodeIteratorConstructorTableValues, 0 };
#else
    { 1, 0, JSNodeIteratorConstructorTableValues, 0 };
#endif

class JSNodeIteratorConstructor : public DOMConstructorObject {
public:
    JSNodeIteratorConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSNodeIteratorConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSNodeIteratorPrototype::self(exec, globalObject), None);
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

const ClassInfo JSNodeIteratorConstructor::s_info = { "NodeIteratorConstructor", 0, &JSNodeIteratorConstructorTable, 0 };

bool JSNodeIteratorConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSNodeIteratorConstructor, DOMObject>(exec, &JSNodeIteratorConstructorTable, this, propertyName, slot);
}

bool JSNodeIteratorConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSNodeIteratorConstructor, DOMObject>(exec, &JSNodeIteratorConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSNodeIteratorPrototypeTableValues[4] =
{
    { "nextNode", DontDelete|Function, (intptr_t)jsNodeIteratorPrototypeFunctionNextNode, (intptr_t)0 },
    { "previousNode", DontDelete|Function, (intptr_t)jsNodeIteratorPrototypeFunctionPreviousNode, (intptr_t)0 },
    { "detach", DontDelete|Function, (intptr_t)jsNodeIteratorPrototypeFunctionDetach, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSNodeIteratorPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSNodeIteratorPrototypeTableValues, 0 };
#else
    { 8, 7, JSNodeIteratorPrototypeTableValues, 0 };
#endif

const ClassInfo JSNodeIteratorPrototype::s_info = { "NodeIteratorPrototype", 0, &JSNodeIteratorPrototypeTable, 0 };

JSObject* JSNodeIteratorPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSNodeIterator>(exec, globalObject);
}

bool JSNodeIteratorPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSNodeIteratorPrototypeTable, this, propertyName, slot);
}

bool JSNodeIteratorPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSNodeIteratorPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSNodeIterator::s_info = { "NodeIterator", 0, &JSNodeIteratorTable, 0 };

JSNodeIterator::JSNodeIterator(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<NodeIterator> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSNodeIterator::~JSNodeIterator()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSNodeIterator::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSNodeIteratorPrototype(JSNodeIteratorPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSNodeIterator::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSNodeIterator, Base>(exec, &JSNodeIteratorTable, this, propertyName, slot);
}

bool JSNodeIterator::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSNodeIterator, Base>(exec, &JSNodeIteratorTable, this, propertyName, descriptor);
}

JSValue jsNodeIteratorRoot(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* castedThis = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    NodeIterator* imp = static_cast<NodeIterator*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->root()));
}

JSValue jsNodeIteratorWhatToShow(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* castedThis = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    NodeIterator* imp = static_cast<NodeIterator*>(castedThis->impl());
    return jsNumber(exec, imp->whatToShow());
}

JSValue jsNodeIteratorFilter(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* castedThis = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    NodeIterator* imp = static_cast<NodeIterator*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->filter()));
}

JSValue jsNodeIteratorExpandEntityReferences(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* castedThis = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    NodeIterator* imp = static_cast<NodeIterator*>(castedThis->impl());
    return jsBoolean(imp->expandEntityReferences());
}

JSValue jsNodeIteratorReferenceNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* castedThis = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    NodeIterator* imp = static_cast<NodeIterator*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->referenceNode()));
}

JSValue jsNodeIteratorPointerBeforeReferenceNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* castedThis = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    NodeIterator* imp = static_cast<NodeIterator*>(castedThis->impl());
    return jsBoolean(imp->pointerBeforeReferenceNode());
}

JSValue jsNodeIteratorConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNodeIterator* domObject = static_cast<JSNodeIterator*>(asObject(slot.slotBase()));
    return JSNodeIterator::getConstructor(exec, domObject->globalObject());
}
JSValue JSNodeIterator::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSNodeIteratorConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsNodeIteratorPrototypeFunctionNextNode(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNodeIterator::s_info))
        return throwError(exec, TypeError);
    JSNodeIterator* castedThisObj = static_cast<JSNodeIterator*>(asObject(thisValue));
    return castedThisObj->nextNode(exec, args);
}

JSValue JSC_HOST_CALL jsNodeIteratorPrototypeFunctionPreviousNode(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNodeIterator::s_info))
        return throwError(exec, TypeError);
    JSNodeIterator* castedThisObj = static_cast<JSNodeIterator*>(asObject(thisValue));
    return castedThisObj->previousNode(exec, args);
}

JSValue JSC_HOST_CALL jsNodeIteratorPrototypeFunctionDetach(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNodeIterator::s_info))
        return throwError(exec, TypeError);
    JSNodeIterator* castedThisObj = static_cast<JSNodeIterator*>(asObject(thisValue));
    NodeIterator* imp = static_cast<NodeIterator*>(castedThisObj->impl());

    imp->detach();
    return jsUndefined();
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, NodeIterator* object)
{
    return getDOMObjectWrapper<JSNodeIterator>(exec, globalObject, object);
}
NodeIterator* toNodeIterator(JSC::JSValue value)
{
    return value.inherits(&JSNodeIterator::s_info) ? static_cast<JSNodeIterator*>(asObject(value))->impl() : 0;
}

}
