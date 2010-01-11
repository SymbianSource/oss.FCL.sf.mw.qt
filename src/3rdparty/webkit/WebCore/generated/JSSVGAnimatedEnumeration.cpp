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

#include "JSSVGAnimatedEnumeration.h"

#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGAnimatedEnumeration);

/* Hash table */

static const HashTableValue JSSVGAnimatedEnumerationTableValues[3] =
{
    { "baseVal", DontDelete, (intptr_t)jsSVGAnimatedEnumerationBaseVal, (intptr_t)setJSSVGAnimatedEnumerationBaseVal },
    { "animVal", DontDelete|ReadOnly, (intptr_t)jsSVGAnimatedEnumerationAnimVal, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedEnumerationTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1, JSSVGAnimatedEnumerationTableValues, 0 };
#else
    { 4, 3, JSSVGAnimatedEnumerationTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSSVGAnimatedEnumerationPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedEnumerationPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGAnimatedEnumerationPrototypeTableValues, 0 };
#else
    { 1, 0, JSSVGAnimatedEnumerationPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGAnimatedEnumerationPrototype::s_info = { "SVGAnimatedEnumerationPrototype", 0, &JSSVGAnimatedEnumerationPrototypeTable, 0 };

JSObject* JSSVGAnimatedEnumerationPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGAnimatedEnumeration>(exec, globalObject);
}

const ClassInfo JSSVGAnimatedEnumeration::s_info = { "SVGAnimatedEnumeration", 0, &JSSVGAnimatedEnumerationTable, 0 };

JSSVGAnimatedEnumeration::JSSVGAnimatedEnumeration(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGAnimatedEnumeration> impl, SVGElement* context)
    : DOMObjectWithSVGContext(structure, globalObject, context)
    , m_impl(impl)
{
}

JSSVGAnimatedEnumeration::~JSSVGAnimatedEnumeration()
{
    forgetDOMObject(*Heap::heap(this)->globalData(), impl());
}

JSObject* JSSVGAnimatedEnumeration::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGAnimatedEnumerationPrototype(JSSVGAnimatedEnumerationPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSSVGAnimatedEnumeration::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGAnimatedEnumeration, Base>(exec, &JSSVGAnimatedEnumerationTable, this, propertyName, slot);
}

bool JSSVGAnimatedEnumeration::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGAnimatedEnumeration, Base>(exec, &JSSVGAnimatedEnumerationTable, this, propertyName, descriptor);
}

JSValue jsSVGAnimatedEnumerationBaseVal(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGAnimatedEnumeration* castedThis = static_cast<JSSVGAnimatedEnumeration*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGAnimatedEnumeration* imp = static_cast<SVGAnimatedEnumeration*>(castedThis->impl());
    return jsNumber(exec, imp->baseVal());
}

JSValue jsSVGAnimatedEnumerationAnimVal(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGAnimatedEnumeration* castedThis = static_cast<JSSVGAnimatedEnumeration*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGAnimatedEnumeration* imp = static_cast<SVGAnimatedEnumeration*>(castedThis->impl());
    return jsNumber(exec, imp->animVal());
}

void JSSVGAnimatedEnumeration::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGAnimatedEnumeration, Base>(exec, propertyName, value, &JSSVGAnimatedEnumerationTable, this, slot);
}

void setJSSVGAnimatedEnumerationBaseVal(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGAnimatedEnumeration* imp = static_cast<SVGAnimatedEnumeration*>(static_cast<JSSVGAnimatedEnumeration*>(thisObject)->impl());
    imp->setBaseVal(value.toInt32(exec));
    if (static_cast<JSSVGAnimatedEnumeration*>(thisObject)->context())
        static_cast<JSSVGAnimatedEnumeration*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGAnimatedEnumeration*>(thisObject)->impl()->associatedAttributeName());
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SVGAnimatedEnumeration* object, SVGElement* context)
{
    return getDOMObjectWrapper<JSSVGAnimatedEnumeration>(exec, globalObject, object, context);
}
SVGAnimatedEnumeration* toSVGAnimatedEnumeration(JSC::JSValue value)
{
    return value.inherits(&JSSVGAnimatedEnumeration::s_info) ? static_cast<JSSVGAnimatedEnumeration*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(SVG)
