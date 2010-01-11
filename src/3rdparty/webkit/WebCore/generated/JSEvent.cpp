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
#include "JSEvent.h"

#include "Event.h"
#include "EventTarget.h"
#include "JSEventTarget.h"
#include "KURL.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSEvent);

/* Hash table */

static const HashTableValue JSEventTableValues[13] =
{
    { "type", DontDelete|ReadOnly, (intptr_t)jsEventType, (intptr_t)0 },
    { "target", DontDelete|ReadOnly, (intptr_t)jsEventTarget, (intptr_t)0 },
    { "currentTarget", DontDelete|ReadOnly, (intptr_t)jsEventCurrentTarget, (intptr_t)0 },
    { "eventPhase", DontDelete|ReadOnly, (intptr_t)jsEventEventPhase, (intptr_t)0 },
    { "bubbles", DontDelete|ReadOnly, (intptr_t)jsEventBubbles, (intptr_t)0 },
    { "cancelable", DontDelete|ReadOnly, (intptr_t)jsEventCancelable, (intptr_t)0 },
    { "timeStamp", DontDelete|ReadOnly, (intptr_t)jsEventTimeStamp, (intptr_t)0 },
    { "srcElement", DontDelete|ReadOnly, (intptr_t)jsEventSrcElement, (intptr_t)0 },
    { "returnValue", DontDelete, (intptr_t)jsEventReturnValue, (intptr_t)setJSEventReturnValue },
    { "cancelBubble", DontDelete, (intptr_t)jsEventCancelBubble, (intptr_t)setJSEventCancelBubble },
    { "clipboardData", DontDelete|ReadOnly, (intptr_t)jsEventClipboardData, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsEventConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSEventTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSEventTableValues, 0 };
#else
    { 35, 31, JSEventTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSEventConstructorTableValues[20] =
{
    { "CAPTURING_PHASE", DontDelete|ReadOnly, (intptr_t)jsEventCAPTURING_PHASE, (intptr_t)0 },
    { "AT_TARGET", DontDelete|ReadOnly, (intptr_t)jsEventAT_TARGET, (intptr_t)0 },
    { "BUBBLING_PHASE", DontDelete|ReadOnly, (intptr_t)jsEventBUBBLING_PHASE, (intptr_t)0 },
    { "MOUSEDOWN", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEDOWN, (intptr_t)0 },
    { "MOUSEUP", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEUP, (intptr_t)0 },
    { "MOUSEOVER", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEOVER, (intptr_t)0 },
    { "MOUSEOUT", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEOUT, (intptr_t)0 },
    { "MOUSEMOVE", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEMOVE, (intptr_t)0 },
    { "MOUSEDRAG", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEDRAG, (intptr_t)0 },
    { "CLICK", DontDelete|ReadOnly, (intptr_t)jsEventCLICK, (intptr_t)0 },
    { "DBLCLICK", DontDelete|ReadOnly, (intptr_t)jsEventDBLCLICK, (intptr_t)0 },
    { "KEYDOWN", DontDelete|ReadOnly, (intptr_t)jsEventKEYDOWN, (intptr_t)0 },
    { "KEYUP", DontDelete|ReadOnly, (intptr_t)jsEventKEYUP, (intptr_t)0 },
    { "KEYPRESS", DontDelete|ReadOnly, (intptr_t)jsEventKEYPRESS, (intptr_t)0 },
    { "DRAGDROP", DontDelete|ReadOnly, (intptr_t)jsEventDRAGDROP, (intptr_t)0 },
    { "FOCUS", DontDelete|ReadOnly, (intptr_t)jsEventFOCUS, (intptr_t)0 },
    { "BLUR", DontDelete|ReadOnly, (intptr_t)jsEventBLUR, (intptr_t)0 },
    { "SELECT", DontDelete|ReadOnly, (intptr_t)jsEventSELECT, (intptr_t)0 },
    { "CHANGE", DontDelete|ReadOnly, (intptr_t)jsEventCHANGE, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSEventConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 8191, JSEventConstructorTableValues, 0 };
#else
    { 68, 63, JSEventConstructorTableValues, 0 };
#endif

class JSEventConstructor : public DOMConstructorObject {
public:
    JSEventConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSEventConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSEventPrototype::self(exec, globalObject), None);
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

const ClassInfo JSEventConstructor::s_info = { "EventConstructor", 0, &JSEventConstructorTable, 0 };

bool JSEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSEventConstructor, DOMObject>(exec, &JSEventConstructorTable, this, propertyName, slot);
}

bool JSEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSEventConstructor, DOMObject>(exec, &JSEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSEventPrototypeTableValues[23] =
{
    { "CAPTURING_PHASE", DontDelete|ReadOnly, (intptr_t)jsEventCAPTURING_PHASE, (intptr_t)0 },
    { "AT_TARGET", DontDelete|ReadOnly, (intptr_t)jsEventAT_TARGET, (intptr_t)0 },
    { "BUBBLING_PHASE", DontDelete|ReadOnly, (intptr_t)jsEventBUBBLING_PHASE, (intptr_t)0 },
    { "MOUSEDOWN", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEDOWN, (intptr_t)0 },
    { "MOUSEUP", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEUP, (intptr_t)0 },
    { "MOUSEOVER", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEOVER, (intptr_t)0 },
    { "MOUSEOUT", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEOUT, (intptr_t)0 },
    { "MOUSEMOVE", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEMOVE, (intptr_t)0 },
    { "MOUSEDRAG", DontDelete|ReadOnly, (intptr_t)jsEventMOUSEDRAG, (intptr_t)0 },
    { "CLICK", DontDelete|ReadOnly, (intptr_t)jsEventCLICK, (intptr_t)0 },
    { "DBLCLICK", DontDelete|ReadOnly, (intptr_t)jsEventDBLCLICK, (intptr_t)0 },
    { "KEYDOWN", DontDelete|ReadOnly, (intptr_t)jsEventKEYDOWN, (intptr_t)0 },
    { "KEYUP", DontDelete|ReadOnly, (intptr_t)jsEventKEYUP, (intptr_t)0 },
    { "KEYPRESS", DontDelete|ReadOnly, (intptr_t)jsEventKEYPRESS, (intptr_t)0 },
    { "DRAGDROP", DontDelete|ReadOnly, (intptr_t)jsEventDRAGDROP, (intptr_t)0 },
    { "FOCUS", DontDelete|ReadOnly, (intptr_t)jsEventFOCUS, (intptr_t)0 },
    { "BLUR", DontDelete|ReadOnly, (intptr_t)jsEventBLUR, (intptr_t)0 },
    { "SELECT", DontDelete|ReadOnly, (intptr_t)jsEventSELECT, (intptr_t)0 },
    { "CHANGE", DontDelete|ReadOnly, (intptr_t)jsEventCHANGE, (intptr_t)0 },
    { "stopPropagation", DontDelete|Function, (intptr_t)jsEventPrototypeFunctionStopPropagation, (intptr_t)0 },
    { "preventDefault", DontDelete|Function, (intptr_t)jsEventPrototypeFunctionPreventDefault, (intptr_t)0 },
    { "initEvent", DontDelete|Function, (intptr_t)jsEventPrototypeFunctionInitEvent, (intptr_t)3 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSEventPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 8191, JSEventPrototypeTableValues, 0 };
#else
    { 68, 63, JSEventPrototypeTableValues, 0 };
#endif

static const HashTable* getJSEventPrototypeTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSEventPrototypeTable);
}
const ClassInfo JSEventPrototype::s_info = { "EventPrototype", 0, 0, getJSEventPrototypeTable };

JSObject* JSEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSEvent>(exec, globalObject);
}

bool JSEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSEventPrototype, JSObject>(exec, getJSEventPrototypeTable(exec), this, propertyName, slot);
}

bool JSEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticPropertyDescriptor<JSEventPrototype, JSObject>(exec, getJSEventPrototypeTable(exec), this, propertyName, descriptor);
}

static const HashTable* getJSEventTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSEventTable);
}
const ClassInfo JSEvent::s_info = { "Event", 0, 0, getJSEventTable };

JSEvent::JSEvent(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<Event> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSEvent::~JSEvent()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSEventPrototype(JSEventPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSEvent, Base>(exec, getJSEventTable(exec), this, propertyName, slot);
}

bool JSEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSEvent, Base>(exec, getJSEventTable(exec), this, propertyName, descriptor);
}

JSValue jsEventType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsString(exec, imp->type());
}

JSValue jsEventTarget(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->target()));
}

JSValue jsEventCurrentTarget(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->currentTarget()));
}

JSValue jsEventEventPhase(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsNumber(exec, imp->eventPhase());
}

JSValue jsEventBubbles(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsBoolean(imp->bubbles());
}

JSValue jsEventCancelable(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsBoolean(imp->cancelable());
}

JSValue jsEventTimeStamp(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsNumber(exec, imp->timeStamp());
}

JSValue jsEventSrcElement(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->srcElement()));
}

JSValue jsEventReturnValue(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsBoolean(imp->returnValue());
}

JSValue jsEventCancelBubble(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Event* imp = static_cast<Event*>(castedThis->impl());
    return jsBoolean(imp->cancelBubble());
}

JSValue jsEventClipboardData(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* castedThis = static_cast<JSEvent*>(asObject(slot.slotBase()));
    return castedThis->clipboardData(exec);
}

JSValue jsEventConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSEvent* domObject = static_cast<JSEvent*>(asObject(slot.slotBase()));
    return JSEvent::getConstructor(exec, domObject->globalObject());
}
void JSEvent::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSEvent, Base>(exec, propertyName, value, getJSEventTable(exec), this, slot);
}

void setJSEventReturnValue(ExecState* exec, JSObject* thisObject, JSValue value)
{
    Event* imp = static_cast<Event*>(static_cast<JSEvent*>(thisObject)->impl());
    imp->setReturnValue(value.toBoolean(exec));
}

void setJSEventCancelBubble(ExecState* exec, JSObject* thisObject, JSValue value)
{
    Event* imp = static_cast<Event*>(static_cast<JSEvent*>(thisObject)->impl());
    imp->setCancelBubble(value.toBoolean(exec));
}

JSValue JSEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsEventPrototypeFunctionStopPropagation(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSEvent::s_info))
        return throwError(exec, TypeError);
    JSEvent* castedThisObj = static_cast<JSEvent*>(asObject(thisValue));
    Event* imp = static_cast<Event*>(castedThisObj->impl());

    imp->stopPropagation();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsEventPrototypeFunctionPreventDefault(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSEvent::s_info))
        return throwError(exec, TypeError);
    JSEvent* castedThisObj = static_cast<JSEvent*>(asObject(thisValue));
    Event* imp = static_cast<Event*>(castedThisObj->impl());

    imp->preventDefault();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsEventPrototypeFunctionInitEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSEvent::s_info))
        return throwError(exec, TypeError);
    JSEvent* castedThisObj = static_cast<JSEvent*>(asObject(thisValue));
    Event* imp = static_cast<Event*>(castedThisObj->impl());
    const UString& eventTypeArg = args.at(0).toString(exec);
    bool canBubbleArg = args.at(1).toBoolean(exec);
    bool cancelableArg = args.at(2).toBoolean(exec);

    imp->initEvent(eventTypeArg, canBubbleArg, cancelableArg);
    return jsUndefined();
}

// Constant getters

JSValue jsEventCAPTURING_PHASE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsEventAT_TARGET(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsEventBUBBLING_PHASE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(3));
}

JSValue jsEventMOUSEDOWN(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsEventMOUSEUP(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsEventMOUSEOVER(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(4));
}

JSValue jsEventMOUSEOUT(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(8));
}

JSValue jsEventMOUSEMOVE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(16));
}

JSValue jsEventMOUSEDRAG(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(32));
}

JSValue jsEventCLICK(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(64));
}

JSValue jsEventDBLCLICK(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(128));
}

JSValue jsEventKEYDOWN(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(256));
}

JSValue jsEventKEYUP(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(512));
}

JSValue jsEventKEYPRESS(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1024));
}

JSValue jsEventDRAGDROP(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2048));
}

JSValue jsEventFOCUS(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(4096));
}

JSValue jsEventBLUR(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(8192));
}

JSValue jsEventSELECT(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(16384));
}

JSValue jsEventCHANGE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(32768));
}

Event* toEvent(JSC::JSValue value)
{
    return value.inherits(&JSEvent::s_info) ? static_cast<JSEvent*>(asObject(value))->impl() : 0;
}

}
