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

#if ENABLE(XPATH)

#include "JSXPathEvaluator.h"

#include "JSCustomXPathNSResolver.h"
#include "JSNode.h"
#include "JSXPathExpression.h"
#include "JSXPathNSResolver.h"
#include "JSXPathResult.h"
#include "PlatformString.h"
#include "XPathEvaluator.h"
#include "XPathExpression.h"
#include "XPathNSResolver.h"
#include "XPathResult.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSXPathEvaluator);

/* Hash table */

static const HashTableValue JSXPathEvaluatorTableValues[2] =
{
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsXPathEvaluatorConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXPathEvaluatorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSXPathEvaluatorTableValues, 0 };
#else
    { 2, 1, JSXPathEvaluatorTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSXPathEvaluatorConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXPathEvaluatorConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSXPathEvaluatorConstructorTableValues, 0 };
#else
    { 1, 0, JSXPathEvaluatorConstructorTableValues, 0 };
#endif

class JSXPathEvaluatorConstructor : public DOMConstructorObject {
public:
    JSXPathEvaluatorConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSXPathEvaluatorConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSXPathEvaluatorPrototype::self(exec, globalObject), None);
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
    static JSObject* constructXPathEvaluator(ExecState* exec, JSObject* constructor, const ArgList&)
    {
        return asObject(toJS(exec, static_cast<JSXPathEvaluatorConstructor*>(constructor)->globalObject(), XPathEvaluator::create()));
    }
    virtual ConstructType getConstructData(ConstructData& constructData)
    {
        constructData.native.function = constructXPathEvaluator;
        return ConstructTypeHost;
    }
};

const ClassInfo JSXPathEvaluatorConstructor::s_info = { "XPathEvaluatorConstructor", 0, &JSXPathEvaluatorConstructorTable, 0 };

bool JSXPathEvaluatorConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSXPathEvaluatorConstructor, DOMObject>(exec, &JSXPathEvaluatorConstructorTable, this, propertyName, slot);
}

bool JSXPathEvaluatorConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSXPathEvaluatorConstructor, DOMObject>(exec, &JSXPathEvaluatorConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSXPathEvaluatorPrototypeTableValues[4] =
{
    { "createExpression", DontDelete|Function, (intptr_t)jsXPathEvaluatorPrototypeFunctionCreateExpression, (intptr_t)2 },
    { "createNSResolver", DontDelete|Function, (intptr_t)jsXPathEvaluatorPrototypeFunctionCreateNSResolver, (intptr_t)1 },
    { "evaluate", DontDelete|Function, (intptr_t)jsXPathEvaluatorPrototypeFunctionEvaluate, (intptr_t)5 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXPathEvaluatorPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSXPathEvaluatorPrototypeTableValues, 0 };
#else
    { 8, 7, JSXPathEvaluatorPrototypeTableValues, 0 };
#endif

const ClassInfo JSXPathEvaluatorPrototype::s_info = { "XPathEvaluatorPrototype", 0, &JSXPathEvaluatorPrototypeTable, 0 };

JSObject* JSXPathEvaluatorPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSXPathEvaluator>(exec, globalObject);
}

bool JSXPathEvaluatorPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSXPathEvaluatorPrototypeTable, this, propertyName, slot);
}

bool JSXPathEvaluatorPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSXPathEvaluatorPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSXPathEvaluator::s_info = { "XPathEvaluator", 0, &JSXPathEvaluatorTable, 0 };

JSXPathEvaluator::JSXPathEvaluator(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<XPathEvaluator> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSXPathEvaluator::~JSXPathEvaluator()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSXPathEvaluator::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSXPathEvaluatorPrototype(JSXPathEvaluatorPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSXPathEvaluator::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSXPathEvaluator, Base>(exec, &JSXPathEvaluatorTable, this, propertyName, slot);
}

bool JSXPathEvaluator::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSXPathEvaluator, Base>(exec, &JSXPathEvaluatorTable, this, propertyName, descriptor);
}

JSValue jsXPathEvaluatorConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSXPathEvaluator* domObject = static_cast<JSXPathEvaluator*>(asObject(slot.slotBase()));
    return JSXPathEvaluator::getConstructor(exec, domObject->globalObject());
}
JSValue JSXPathEvaluator::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSXPathEvaluatorConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsXPathEvaluatorPrototypeFunctionCreateExpression(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXPathEvaluator::s_info))
        return throwError(exec, TypeError);
    JSXPathEvaluator* castedThisObj = static_cast<JSXPathEvaluator*>(asObject(thisValue));
    XPathEvaluator* imp = static_cast<XPathEvaluator*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    const UString& expression = args.at(0).toString(exec);
    RefPtr<XPathNSResolver> customResolver;
    XPathNSResolver* resolver = toXPathNSResolver(args.at(1));
    if (!resolver) {
        customResolver = JSCustomXPathNSResolver::create(exec, args.at(1));
        if (exec->hadException())
            return jsUndefined();
        resolver = customResolver.get();
    }


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->createExpression(expression, resolver, ec)));
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsXPathEvaluatorPrototypeFunctionCreateNSResolver(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXPathEvaluator::s_info))
        return throwError(exec, TypeError);
    JSXPathEvaluator* castedThisObj = static_cast<JSXPathEvaluator*>(asObject(thisValue));
    XPathEvaluator* imp = static_cast<XPathEvaluator*>(castedThisObj->impl());
    Node* nodeResolver = toNode(args.at(0));


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->createNSResolver(nodeResolver)));
    return result;
}

JSValue JSC_HOST_CALL jsXPathEvaluatorPrototypeFunctionEvaluate(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXPathEvaluator::s_info))
        return throwError(exec, TypeError);
    JSXPathEvaluator* castedThisObj = static_cast<JSXPathEvaluator*>(asObject(thisValue));
    XPathEvaluator* imp = static_cast<XPathEvaluator*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    const UString& expression = args.at(0).toString(exec);
    Node* contextNode = toNode(args.at(1));
    RefPtr<XPathNSResolver> customResolver;
    XPathNSResolver* resolver = toXPathNSResolver(args.at(2));
    if (!resolver) {
        customResolver = JSCustomXPathNSResolver::create(exec, args.at(2));
        if (exec->hadException())
            return jsUndefined();
        resolver = customResolver.get();
    }
    unsigned short type = args.at(3).toInt32(exec);
    XPathResult* inResult = toXPathResult(args.at(4));


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->evaluate(expression, contextNode, resolver, type, inResult, ec)));
    setDOMException(exec, ec);
    return result;
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, XPathEvaluator* object)
{
    return getDOMObjectWrapper<JSXPathEvaluator>(exec, globalObject, object);
}
XPathEvaluator* toXPathEvaluator(JSC::JSValue value)
{
    return value.inherits(&JSXPathEvaluator::s_info) ? static_cast<JSXPathEvaluator*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(XPATH)
