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

#if ENABLE(XSLT)

#include "JSXSLTProcessor.h"

#include "Document.h"
#include "DocumentFragment.h"
#include "NodeFilter.h"
#include "XSLTProcessor.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSXSLTProcessor);

/* Hash table for prototype */

static const HashTableValue JSXSLTProcessorPrototypeTableValues[9] =
{
    { "importStylesheet", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionImportStylesheet, (intptr_t)1 },
    { "transformToFragment", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionTransformToFragment, (intptr_t)2 },
    { "transformToDocument", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionTransformToDocument, (intptr_t)1 },
    { "setParameter", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionSetParameter, (intptr_t)3 },
    { "getParameter", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionGetParameter, (intptr_t)2 },
    { "removeParameter", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionRemoveParameter, (intptr_t)2 },
    { "clearParameters", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionClearParameters, (intptr_t)0 },
    { "reset", DontDelete|Function, (intptr_t)jsXSLTProcessorPrototypeFunctionReset, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXSLTProcessorPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 63, JSXSLTProcessorPrototypeTableValues, 0 };
#else
    { 17, 15, JSXSLTProcessorPrototypeTableValues, 0 };
#endif

const ClassInfo JSXSLTProcessorPrototype::s_info = { "XSLTProcessorPrototype", 0, &JSXSLTProcessorPrototypeTable, 0 };

JSObject* JSXSLTProcessorPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSXSLTProcessor>(exec, globalObject);
}

bool JSXSLTProcessorPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSXSLTProcessorPrototypeTable, this, propertyName, slot);
}

bool JSXSLTProcessorPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSXSLTProcessorPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSXSLTProcessor::s_info = { "XSLTProcessor", 0, 0, 0 };

JSXSLTProcessor::JSXSLTProcessor(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<XSLTProcessor> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSXSLTProcessor::~JSXSLTProcessor()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSXSLTProcessor::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSXSLTProcessorPrototype(JSXSLTProcessorPrototype::createStructure(globalObject->objectPrototype()));
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionImportStylesheet(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    return castedThisObj->importStylesheet(exec, args);
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionTransformToFragment(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    return castedThisObj->transformToFragment(exec, args);
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionTransformToDocument(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    return castedThisObj->transformToDocument(exec, args);
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionSetParameter(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    return castedThisObj->setParameter(exec, args);
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionGetParameter(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    return castedThisObj->getParameter(exec, args);
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionRemoveParameter(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    return castedThisObj->removeParameter(exec, args);
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionClearParameters(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    XSLTProcessor* imp = static_cast<XSLTProcessor*>(castedThisObj->impl());

    imp->clearParameters();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionReset(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXSLTProcessor::s_info))
        return throwError(exec, TypeError);
    JSXSLTProcessor* castedThisObj = static_cast<JSXSLTProcessor*>(asObject(thisValue));
    XSLTProcessor* imp = static_cast<XSLTProcessor*>(castedThisObj->impl());

    imp->reset();
    return jsUndefined();
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, XSLTProcessor* object)
{
    return getDOMObjectWrapper<JSXSLTProcessor>(exec, globalObject, object);
}
XSLTProcessor* toXSLTProcessor(JSC::JSValue value)
{
    return value.inherits(&JSXSLTProcessor::s_info) ? static_cast<JSXSLTProcessor*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(XSLT)
