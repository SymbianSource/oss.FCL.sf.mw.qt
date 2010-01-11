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

#if ENABLE(WORKERS)

#include "JSWorkerContext.h"

#include "Event.h"
#include "EventListener.h"
#include "JSEvent.h"
#include "JSEventListener.h"
#include "JSEventSource.h"
#include "JSMessageChannel.h"
#include "JSMessageEvent.h"
#include "JSWorkerContext.h"
#include "JSWorkerLocation.h"
#include "JSWorkerNavigator.h"
#include "JSXMLHttpRequest.h"
#include "RegisteredEventListener.h"
#include "WorkerContext.h"
#include "WorkerLocation.h"
#include "WorkerNavigator.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSWorkerContext);

/* Hash table */

static const HashTableValue JSWorkerContextTableValues[10] =
{
    { "self", DontDelete, (intptr_t)jsWorkerContextSelf, (intptr_t)setJSWorkerContextSelf },
    { "location", DontDelete, (intptr_t)jsWorkerContextLocation, (intptr_t)setJSWorkerContextLocation },
    { "onerror", DontDelete, (intptr_t)jsWorkerContextOnerror, (intptr_t)setJSWorkerContextOnerror },
    { "navigator", DontDelete, (intptr_t)jsWorkerContextNavigator, (intptr_t)setJSWorkerContextNavigator },
    { "MessageEvent", DontDelete, (intptr_t)jsWorkerContextMessageEventConstructor, (intptr_t)setJSWorkerContextMessageEventConstructor },
    { "WorkerLocation", DontDelete, (intptr_t)jsWorkerContextWorkerLocationConstructor, (intptr_t)setJSWorkerContextWorkerLocationConstructor },
    { "MessageChannel", DontDelete, (intptr_t)jsWorkerContextMessageChannelConstructor, (intptr_t)setJSWorkerContextMessageChannelConstructor },
    { "EventSource", DontDelete, (intptr_t)jsWorkerContextEventSourceConstructor, (intptr_t)setJSWorkerContextEventSourceConstructor },
    { "XMLHttpRequest", DontDelete, (intptr_t)jsWorkerContextXMLHttpRequestConstructor, (intptr_t)setJSWorkerContextXMLHttpRequestConstructor },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWorkerContextTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSWorkerContextTableValues, 0 };
#else
    { 34, 31, JSWorkerContextTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSWorkerContextPrototypeTableValues[10] =
{
    { "close", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionClose, (intptr_t)0 },
    { "importScripts", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionImportScripts, (intptr_t)0 },
    { "setTimeout", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionSetTimeout, (intptr_t)2 },
    { "clearTimeout", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionClearTimeout, (intptr_t)1 },
    { "setInterval", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionSetInterval, (intptr_t)2 },
    { "clearInterval", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionClearInterval, (intptr_t)1 },
    { "addEventListener", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionAddEventListener, (intptr_t)3 },
    { "removeEventListener", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionRemoveEventListener, (intptr_t)3 },
    { "dispatchEvent", DontDelete|Function, (intptr_t)jsWorkerContextPrototypeFunctionDispatchEvent, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWorkerContextPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1023, JSWorkerContextPrototypeTableValues, 0 };
#else
    { 34, 31, JSWorkerContextPrototypeTableValues, 0 };
#endif

static const HashTable* getJSWorkerContextPrototypeTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSWorkerContextPrototypeTable);
}
const ClassInfo JSWorkerContextPrototype::s_info = { "WorkerContextPrototype", 0, 0, getJSWorkerContextPrototypeTable };

void* JSWorkerContextPrototype::operator new(size_t size, JSGlobalData* globalData)
{
    return globalData->heap.allocate(size);
}

bool JSWorkerContextPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, getJSWorkerContextPrototypeTable(exec), this, propertyName, slot);
}

bool JSWorkerContextPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, getJSWorkerContextPrototypeTable(exec), this, propertyName, descriptor);
}

static const HashTable* getJSWorkerContextTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSWorkerContextTable);
}
const ClassInfo JSWorkerContext::s_info = { "WorkerContext", &JSWorkerContextBase::s_info, 0, getJSWorkerContextTable };

JSWorkerContext::JSWorkerContext(NonNullPassRefPtr<Structure> structure, PassRefPtr<WorkerContext> impl)
    : JSWorkerContextBase(structure, impl)
{
}

JSWorkerContext::~JSWorkerContext()
{
    impl()->invalidateEventListeners();
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

bool JSWorkerContext::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    if (getOwnPropertySlotDelegate(exec, propertyName, slot))
        return true;
    return getStaticValueSlot<JSWorkerContext, Base>(exec, getJSWorkerContextTable(exec), this, propertyName, slot);
}

bool JSWorkerContext::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    if (getOwnPropertyDescriptorDelegate(exec, propertyName, descriptor))
        return true;
    return getStaticValueDescriptor<JSWorkerContext, Base>(exec, getJSWorkerContextTable(exec), this, propertyName, descriptor);
}

JSValue jsWorkerContextSelf(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->self()));
}

JSValue jsWorkerContextLocation(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->location()));
}

JSValue jsWorkerContextOnerror(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThis->impl());
    if (EventListener* listener = imp->onerror()) {
        if (JSObject* jsFunction = listener->jsFunction(imp))
            return jsFunction;
    }
    return jsNull();
}

JSValue jsWorkerContextNavigator(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->navigator()));
}

JSValue jsWorkerContextMessageEventConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    return JSMessageEvent::getConstructor(exec, castedThis);
}

JSValue jsWorkerContextWorkerLocationConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    return JSWorkerLocation::getConstructor(exec, castedThis);
}

JSValue jsWorkerContextMessageChannelConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    return castedThis->messageChannel(exec);
}

JSValue jsWorkerContextEventSourceConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    return castedThis->eventSource(exec);
}

JSValue jsWorkerContextXMLHttpRequestConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWorkerContext* castedThis = static_cast<JSWorkerContext*>(asObject(slot.slotBase()));
    return castedThis->xmlHttpRequest(exec);
}

void JSWorkerContext::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSWorkerContext, Base>(exec, propertyName, value, getJSWorkerContextTable(exec), this, slot);
}

void setJSWorkerContextSelf(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in object
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "self"), value);
}

void setJSWorkerContextLocation(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in object
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "location"), value);
}

void setJSWorkerContextOnerror(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    WorkerContext* imp = static_cast<WorkerContext*>(static_cast<JSWorkerContext*>(thisObject)->impl());
    JSDOMGlobalObject* globalObject = static_cast<JSWorkerContext*>(thisObject);
    imp->setOnerror(globalObject->createJSAttributeEventListener(value));
}

void setJSWorkerContextNavigator(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in object
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "navigator"), value);
}

void setJSWorkerContextMessageEventConstructor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in constructor
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "MessageEvent"), value);
}

void setJSWorkerContextWorkerLocationConstructor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in constructor
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "WorkerLocation"), value);
}

void setJSWorkerContextMessageChannelConstructor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in constructor
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "MessageChannel"), value);
}

void setJSWorkerContextEventSourceConstructor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in constructor
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "EventSource"), value);
}

void setJSWorkerContextXMLHttpRequestConstructor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    // Shadowing a built-in constructor
    static_cast<JSWorkerContext*>(thisObject)->putDirect(Identifier(exec, "XMLHttpRequest"), value);
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionClose(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThisObj->impl());

    imp->close();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionImportScripts(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    return castedThisObj->importScripts(exec, args);
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionSetTimeout(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    return castedThisObj->setTimeout(exec, args);
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionClearTimeout(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThisObj->impl());
    int handle = args.at(0).toInt32(exec);

    imp->clearTimeout(handle);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionSetInterval(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    return castedThisObj->setInterval(exec, args);
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionClearInterval(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThisObj->impl());
    int handle = args.at(0).toInt32(exec);

    imp->clearInterval(handle);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionAddEventListener(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    return castedThisObj->addEventListener(exec, args);
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionRemoveEventListener(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    return castedThisObj->removeEventListener(exec, args);
}

JSValue JSC_HOST_CALL jsWorkerContextPrototypeFunctionDispatchEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    JSWorkerContext* castedThisObj = toJSWorkerContext(thisValue.toThisObject(exec));
    if (!castedThisObj)
        return throwError(exec, TypeError);
    WorkerContext* imp = static_cast<WorkerContext*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Event* evt = toEvent(args.at(0));


    JSC::JSValue result = jsBoolean(imp->dispatchEvent(evt, ec));
    setDOMException(exec, ec);
    return result;
}


}

#endif // ENABLE(WORKERS)
