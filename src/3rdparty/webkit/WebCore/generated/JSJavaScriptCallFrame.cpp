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

#if ENABLE(JAVASCRIPT_DEBUGGER)

#include "JSJavaScriptCallFrame.h"

#include "JSJavaScriptCallFrame.h"
#include "JavaScriptCallFrame.h"
#include "KURL.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSJavaScriptCallFrame);

/* Hash table */

static const HashTableValue JSJavaScriptCallFrameTableValues[8] =
{
    { "caller", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameCaller, (intptr_t)0 },
    { "sourceID", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameSourceID, (intptr_t)0 },
    { "line", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameLine, (intptr_t)0 },
    { "scopeChain", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameScopeChain, (intptr_t)0 },
    { "thisObject", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameThisObject, (intptr_t)0 },
    { "functionName", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameFunctionName, (intptr_t)0 },
    { "type", DontDelete|ReadOnly, (intptr_t)jsJavaScriptCallFrameType, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSJavaScriptCallFrameTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 63, JSJavaScriptCallFrameTableValues, 0 };
#else
    { 17, 15, JSJavaScriptCallFrameTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSJavaScriptCallFramePrototypeTableValues[2] =
{
    { "evaluate", DontDelete|Function, (intptr_t)jsJavaScriptCallFramePrototypeFunctionEvaluate, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSJavaScriptCallFramePrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSJavaScriptCallFramePrototypeTableValues, 0 };
#else
    { 2, 1, JSJavaScriptCallFramePrototypeTableValues, 0 };
#endif

const ClassInfo JSJavaScriptCallFramePrototype::s_info = { "JavaScriptCallFramePrototype", 0, &JSJavaScriptCallFramePrototypeTable, 0 };

JSObject* JSJavaScriptCallFramePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSJavaScriptCallFrame>(exec, globalObject);
}

bool JSJavaScriptCallFramePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSJavaScriptCallFramePrototypeTable, this, propertyName, slot);
}

bool JSJavaScriptCallFramePrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSJavaScriptCallFramePrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSJavaScriptCallFrame::s_info = { "JavaScriptCallFrame", 0, &JSJavaScriptCallFrameTable, 0 };

JSJavaScriptCallFrame::JSJavaScriptCallFrame(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<JavaScriptCallFrame> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSJavaScriptCallFrame::~JSJavaScriptCallFrame()
{
    forgetDOMObject(this, impl());
}

JSObject* JSJavaScriptCallFrame::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSJavaScriptCallFramePrototype(JSJavaScriptCallFramePrototype::createStructure(globalObject->objectPrototype()));
}

bool JSJavaScriptCallFrame::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSJavaScriptCallFrame, Base>(exec, &JSJavaScriptCallFrameTable, this, propertyName, slot);
}

bool JSJavaScriptCallFrame::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSJavaScriptCallFrame, Base>(exec, &JSJavaScriptCallFrameTable, this, propertyName, descriptor);
}

JSValue jsJavaScriptCallFrameCaller(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->caller()));
}

JSValue jsJavaScriptCallFrameSourceID(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(castedThis->impl());
    return jsNumber(exec, imp->sourceID());
}

JSValue jsJavaScriptCallFrameLine(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(castedThis->impl());
    return jsNumber(exec, imp->line());
}

JSValue jsJavaScriptCallFrameScopeChain(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    return castedThis->scopeChain(exec);
}

JSValue jsJavaScriptCallFrameThisObject(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    return castedThis->thisObject(exec);
}

JSValue jsJavaScriptCallFrameFunctionName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(castedThis->impl());
    return jsString(exec, imp->functionName());
}

JSValue jsJavaScriptCallFrameType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSJavaScriptCallFrame* castedThis = static_cast<JSJavaScriptCallFrame*>(asObject(slot.slotBase()));
    return castedThis->type(exec);
}

JSValue JSC_HOST_CALL jsJavaScriptCallFramePrototypeFunctionEvaluate(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSJavaScriptCallFrame::s_info))
        return throwError(exec, TypeError);
    JSJavaScriptCallFrame* castedThisObj = static_cast<JSJavaScriptCallFrame*>(asObject(thisValue));
    return castedThisObj->evaluate(exec, args);
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, JavaScriptCallFrame* object)
{
    return getDOMObjectWrapper<JSJavaScriptCallFrame>(exec, globalObject, object);
}
JavaScriptCallFrame* toJavaScriptCallFrame(JSC::JSValue value)
{
    return value.inherits(&JSJavaScriptCallFrame::s_info) ? static_cast<JSJavaScriptCallFrame*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(JAVASCRIPT_DEBUGGER)
