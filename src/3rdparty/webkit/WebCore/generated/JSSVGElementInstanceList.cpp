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

#if ENABLE(SVG)

#include "JSSVGElementInstanceList.h"

#include "JSSVGElementInstance.h"
#include "SVGElementInstance.h"
#include "SVGElementInstanceList.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGElementInstanceList);

/* Hash table */

static const HashTableValue JSSVGElementInstanceListTableValues[2] =
{
    { "length", DontDelete|ReadOnly, (intptr_t)jsSVGElementInstanceListLength, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGElementInstanceListTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGElementInstanceListTableValues, 0 };
#else
    { 2, 1, JSSVGElementInstanceListTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSSVGElementInstanceListPrototypeTableValues[2] =
{
    { "item", DontDelete|Function, (intptr_t)jsSVGElementInstanceListPrototypeFunctionItem, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGElementInstanceListPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGElementInstanceListPrototypeTableValues, 0 };
#else
    { 2, 1, JSSVGElementInstanceListPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGElementInstanceListPrototype::s_info = { "SVGElementInstanceListPrototype", 0, &JSSVGElementInstanceListPrototypeTable, 0 };

JSObject* JSSVGElementInstanceListPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGElementInstanceList>(exec, globalObject);
}

bool JSSVGElementInstanceListPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSVGElementInstanceListPrototypeTable, this, propertyName, slot);
}

bool JSSVGElementInstanceListPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSVGElementInstanceListPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGElementInstanceList::s_info = { "SVGElementInstanceList", 0, &JSSVGElementInstanceListTable, 0 };

JSSVGElementInstanceList::JSSVGElementInstanceList(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElementInstanceList> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSSVGElementInstanceList::~JSSVGElementInstanceList()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSSVGElementInstanceList::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGElementInstanceListPrototype(JSSVGElementInstanceListPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSSVGElementInstanceList::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGElementInstanceList, Base>(exec, &JSSVGElementInstanceListTable, this, propertyName, slot);
}

bool JSSVGElementInstanceList::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGElementInstanceList, Base>(exec, &JSSVGElementInstanceListTable, this, propertyName, descriptor);
}

JSValue jsSVGElementInstanceListLength(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGElementInstanceList* castedThis = static_cast<JSSVGElementInstanceList*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGElementInstanceList* imp = static_cast<SVGElementInstanceList*>(castedThis->impl());
    return jsNumber(exec, imp->length());
}

JSValue JSC_HOST_CALL jsSVGElementInstanceListPrototypeFunctionItem(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGElementInstanceList::s_info))
        return throwError(exec, TypeError);
    JSSVGElementInstanceList* castedThisObj = static_cast<JSSVGElementInstanceList*>(asObject(thisValue));
    SVGElementInstanceList* imp = static_cast<SVGElementInstanceList*>(castedThisObj->impl());
    unsigned index = args.at(0).toInt32(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->item(index)));
    return result;
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SVGElementInstanceList* object)
{
    return getDOMObjectWrapper<JSSVGElementInstanceList>(exec, globalObject, object);
}
SVGElementInstanceList* toSVGElementInstanceList(JSC::JSValue value)
{
    return value.inherits(&JSSVGElementInstanceList::s_info) ? static_cast<JSSVGElementInstanceList*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(SVG)
