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

#include "JSSVGPathSegArcAbs.h"

#include "SVGPathSegArc.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGPathSegArcAbs);

/* Hash table */

static const HashTableValue JSSVGPathSegArcAbsTableValues[8] =
{
    { "x", DontDelete, (intptr_t)jsSVGPathSegArcAbsX, (intptr_t)setJSSVGPathSegArcAbsX },
    { "y", DontDelete, (intptr_t)jsSVGPathSegArcAbsY, (intptr_t)setJSSVGPathSegArcAbsY },
    { "r1", DontDelete, (intptr_t)jsSVGPathSegArcAbsR1, (intptr_t)setJSSVGPathSegArcAbsR1 },
    { "r2", DontDelete, (intptr_t)jsSVGPathSegArcAbsR2, (intptr_t)setJSSVGPathSegArcAbsR2 },
    { "angle", DontDelete, (intptr_t)jsSVGPathSegArcAbsAngle, (intptr_t)setJSSVGPathSegArcAbsAngle },
    { "largeArcFlag", DontDelete, (intptr_t)jsSVGPathSegArcAbsLargeArcFlag, (intptr_t)setJSSVGPathSegArcAbsLargeArcFlag },
    { "sweepFlag", DontDelete, (intptr_t)jsSVGPathSegArcAbsSweepFlag, (intptr_t)setJSSVGPathSegArcAbsSweepFlag },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegArcAbsTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSSVGPathSegArcAbsTableValues, 0 };
#else
    { 16, 15, JSSVGPathSegArcAbsTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSSVGPathSegArcAbsPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegArcAbsPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGPathSegArcAbsPrototypeTableValues, 0 };
#else
    { 1, 0, JSSVGPathSegArcAbsPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGPathSegArcAbsPrototype::s_info = { "SVGPathSegArcAbsPrototype", 0, &JSSVGPathSegArcAbsPrototypeTable, 0 };

JSObject* JSSVGPathSegArcAbsPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGPathSegArcAbs>(exec, globalObject);
}

const ClassInfo JSSVGPathSegArcAbs::s_info = { "SVGPathSegArcAbs", &JSSVGPathSeg::s_info, &JSSVGPathSegArcAbsTable, 0 };

JSSVGPathSegArcAbs::JSSVGPathSegArcAbs(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGPathSegArcAbs> impl, SVGElement* context)
    : JSSVGPathSeg(structure, globalObject, impl, context)
{
}

JSObject* JSSVGPathSegArcAbs::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGPathSegArcAbsPrototype(JSSVGPathSegArcAbsPrototype::createStructure(JSSVGPathSegPrototype::self(exec, globalObject)));
}

bool JSSVGPathSegArcAbs::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGPathSegArcAbs, Base>(exec, &JSSVGPathSegArcAbsTable, this, propertyName, slot);
}

bool JSSVGPathSegArcAbs::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGPathSegArcAbs, Base>(exec, &JSSVGPathSegArcAbsTable, this, propertyName, descriptor);
}

JSValue jsSVGPathSegArcAbsX(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsNumber(exec, imp->x());
}

JSValue jsSVGPathSegArcAbsY(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsNumber(exec, imp->y());
}

JSValue jsSVGPathSegArcAbsR1(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsNumber(exec, imp->r1());
}

JSValue jsSVGPathSegArcAbsR2(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsNumber(exec, imp->r2());
}

JSValue jsSVGPathSegArcAbsAngle(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsNumber(exec, imp->angle());
}

JSValue jsSVGPathSegArcAbsLargeArcFlag(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsBoolean(imp->largeArcFlag());
}

JSValue jsSVGPathSegArcAbsSweepFlag(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGPathSegArcAbs* castedThis = static_cast<JSSVGPathSegArcAbs*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(castedThis->impl());
    return jsBoolean(imp->sweepFlag());
}

void JSSVGPathSegArcAbs::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGPathSegArcAbs, Base>(exec, propertyName, value, &JSSVGPathSegArcAbsTable, this, slot);
}

void setJSSVGPathSegArcAbsX(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setX(value.toFloat(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}

void setJSSVGPathSegArcAbsY(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setY(value.toFloat(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}

void setJSSVGPathSegArcAbsR1(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setR1(value.toFloat(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}

void setJSSVGPathSegArcAbsR2(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setR2(value.toFloat(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}

void setJSSVGPathSegArcAbsAngle(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setAngle(value.toFloat(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}

void setJSSVGPathSegArcAbsLargeArcFlag(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setLargeArcFlag(value.toBoolean(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}

void setJSSVGPathSegArcAbsSweepFlag(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGPathSegArcAbs* imp = static_cast<SVGPathSegArcAbs*>(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl());
    imp->setSweepFlag(value.toBoolean(exec));
    if (static_cast<JSSVGPathSegArcAbs*>(thisObject)->context())
        static_cast<JSSVGPathSegArcAbs*>(thisObject)->context()->svgAttributeChanged(static_cast<JSSVGPathSegArcAbs*>(thisObject)->impl()->associatedAttributeName());
}


}

#endif // ENABLE(SVG)
