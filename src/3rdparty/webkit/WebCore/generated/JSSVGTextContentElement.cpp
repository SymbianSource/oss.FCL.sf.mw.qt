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

#include "JSSVGTextContentElement.h"

#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "CSSValue.h"
#include "ExceptionCode.h"
#include "FloatPoint.h"
#include "JSCSSStyleDeclaration.h"
#include "JSCSSValue.h"
#include "JSSVGAnimatedBoolean.h"
#include "JSSVGAnimatedEnumeration.h"
#include "JSSVGAnimatedLength.h"
#include "JSSVGAnimatedString.h"
#include "JSSVGPoint.h"
#include "JSSVGRect.h"
#include "JSSVGStringList.h"
#include "KURL.h"
#include "SVGStringList.h"
#include "SVGTextContentElement.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGTextContentElement);

/* Hash table */

static const HashTableValue JSSVGTextContentElementTableValues[12] =
{
    { "textLength", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementTextLength, (intptr_t)0 },
    { "lengthAdjust", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLengthAdjust, (intptr_t)0 },
    { "requiredFeatures", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementRequiredFeatures, (intptr_t)0 },
    { "requiredExtensions", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementRequiredExtensions, (intptr_t)0 },
    { "systemLanguage", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementSystemLanguage, (intptr_t)0 },
    { "xmllang", DontDelete, (intptr_t)jsSVGTextContentElementXmllang, (intptr_t)setJSSVGTextContentElementXmllang },
    { "xmlspace", DontDelete, (intptr_t)jsSVGTextContentElementXmlspace, (intptr_t)setJSSVGTextContentElementXmlspace },
    { "externalResourcesRequired", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementExternalResourcesRequired, (intptr_t)0 },
    { "className", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementClassName, (intptr_t)0 },
    { "style", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementStyle, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsSVGTextContentElementConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextContentElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSSVGTextContentElementTableValues, 0 };
#else
    { 34, 31, JSSVGTextContentElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGTextContentElementConstructorTableValues[4] =
{
    { "LENGTHADJUST_UNKNOWN", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLENGTHADJUST_UNKNOWN, (intptr_t)0 },
    { "LENGTHADJUST_SPACING", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLENGTHADJUST_SPACING, (intptr_t)0 },
    { "LENGTHADJUST_SPACINGANDGLYPHS", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLENGTHADJUST_SPACINGANDGLYPHS, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextContentElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSSVGTextContentElementConstructorTableValues, 0 };
#else
    { 8, 7, JSSVGTextContentElementConstructorTableValues, 0 };
#endif

class JSSVGTextContentElementConstructor : public DOMConstructorObject {
public:
    JSSVGTextContentElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGTextContentElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGTextContentElementPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGTextContentElementConstructor::s_info = { "SVGTextContentElementConstructor", 0, &JSSVGTextContentElementConstructorTable, 0 };

bool JSSVGTextContentElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGTextContentElementConstructor, DOMObject>(exec, &JSSVGTextContentElementConstructorTable, this, propertyName, slot);
}

bool JSSVGTextContentElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGTextContentElementConstructor, DOMObject>(exec, &JSSVGTextContentElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGTextContentElementPrototypeTableValues[15] =
{
    { "LENGTHADJUST_UNKNOWN", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLENGTHADJUST_UNKNOWN, (intptr_t)0 },
    { "LENGTHADJUST_SPACING", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLENGTHADJUST_SPACING, (intptr_t)0 },
    { "LENGTHADJUST_SPACINGANDGLYPHS", DontDelete|ReadOnly, (intptr_t)jsSVGTextContentElementLENGTHADJUST_SPACINGANDGLYPHS, (intptr_t)0 },
    { "getNumberOfChars", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetNumberOfChars, (intptr_t)0 },
    { "getComputedTextLength", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetComputedTextLength, (intptr_t)0 },
    { "getSubStringLength", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetSubStringLength, (intptr_t)2 },
    { "getStartPositionOfChar", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetStartPositionOfChar, (intptr_t)1 },
    { "getEndPositionOfChar", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetEndPositionOfChar, (intptr_t)1 },
    { "getExtentOfChar", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetExtentOfChar, (intptr_t)1 },
    { "getRotationOfChar", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetRotationOfChar, (intptr_t)1 },
    { "getCharNumAtPosition", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetCharNumAtPosition, (intptr_t)1 },
    { "selectSubString", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionSelectSubString, (intptr_t)2 },
    { "hasExtension", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionHasExtension, (intptr_t)1 },
    { "getPresentationAttribute", DontDelete|Function, (intptr_t)jsSVGTextContentElementPrototypeFunctionGetPresentationAttribute, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextContentElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSSVGTextContentElementPrototypeTableValues, 0 };
#else
    { 34, 31, JSSVGTextContentElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGTextContentElementPrototype::s_info = { "SVGTextContentElementPrototype", 0, &JSSVGTextContentElementPrototypeTable, 0 };

JSObject* JSSVGTextContentElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGTextContentElement>(exec, globalObject);
}

bool JSSVGTextContentElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSSVGTextContentElementPrototype, JSObject>(exec, &JSSVGTextContentElementPrototypeTable, this, propertyName, slot);
}

bool JSSVGTextContentElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticPropertyDescriptor<JSSVGTextContentElementPrototype, JSObject>(exec, &JSSVGTextContentElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGTextContentElement::s_info = { "SVGTextContentElement", &JSSVGElement::s_info, &JSSVGTextContentElementTable, 0 };

JSSVGTextContentElement::JSSVGTextContentElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGTextContentElement> impl)
    : JSSVGElement(structure, globalObject, impl)
{
}

JSObject* JSSVGTextContentElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGTextContentElementPrototype(JSSVGTextContentElementPrototype::createStructure(JSSVGElementPrototype::self(exec, globalObject)));
}

bool JSSVGTextContentElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGTextContentElement, Base>(exec, &JSSVGTextContentElementTable, this, propertyName, slot);
}

bool JSSVGTextContentElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGTextContentElement, Base>(exec, &JSSVGTextContentElementTable, this, propertyName, descriptor);
}

JSValue jsSVGTextContentElementTextLength(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->textLengthAnimated();
    return toJS(exec, castedThis->globalObject(), obj.get(), imp);
}

JSValue jsSVGTextContentElementLengthAdjust(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    RefPtr<SVGAnimatedEnumeration> obj = imp->lengthAdjustAnimated();
    return toJS(exec, castedThis->globalObject(), obj.get(), imp);
}

JSValue jsSVGTextContentElementRequiredFeatures(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->requiredFeatures()), imp);
}

JSValue jsSVGTextContentElementRequiredExtensions(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->requiredExtensions()), imp);
}

JSValue jsSVGTextContentElementSystemLanguage(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->systemLanguage()), imp);
}

JSValue jsSVGTextContentElementXmllang(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    return jsString(exec, imp->xmllang());
}

JSValue jsSVGTextContentElementXmlspace(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    return jsString(exec, imp->xmlspace());
}

JSValue jsSVGTextContentElementExternalResourcesRequired(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    RefPtr<SVGAnimatedBoolean> obj = imp->externalResourcesRequiredAnimated();
    return toJS(exec, castedThis->globalObject(), obj.get(), imp);
}

JSValue jsSVGTextContentElementClassName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    RefPtr<SVGAnimatedString> obj = imp->classNameAnimated();
    return toJS(exec, castedThis->globalObject(), obj.get(), imp);
}

JSValue jsSVGTextContentElementStyle(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* castedThis = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->style()));
}

JSValue jsSVGTextContentElementConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGTextContentElement* domObject = static_cast<JSSVGTextContentElement*>(asObject(slot.slotBase()));
    return JSSVGTextContentElement::getConstructor(exec, domObject->globalObject());
}
void JSSVGTextContentElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGTextContentElement, Base>(exec, propertyName, value, &JSSVGTextContentElementTable, this, slot);
}

void setJSSVGTextContentElementXmllang(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(static_cast<JSSVGTextContentElement*>(thisObject)->impl());
    imp->setXmllang(value.toString(exec));
}

void setJSSVGTextContentElementXmlspace(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(static_cast<JSSVGTextContentElement*>(thisObject)->impl());
    imp->setXmlspace(value.toString(exec));
}

JSValue JSSVGTextContentElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGTextContentElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetNumberOfChars(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());


    JSC::JSValue result = jsNumber(exec, imp->getNumberOfChars());
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetComputedTextLength(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());


    JSC::JSValue result = jsNumber(exec, imp->getComputedTextLength());
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetSubStringLength(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    int length = args.at(1).toInt32(exec);
    if (length < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = jsNumber(exec, imp->getSubStringLength(offset, length, ec));
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetStartPositionOfChar(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<FloatPoint>::create(imp->getStartPositionOfChar(offset, ec)).get(), imp);
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetEndPositionOfChar(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<FloatPoint>::create(imp->getEndPositionOfChar(offset, ec)).get(), imp);
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetExtentOfChar(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<FloatRect>::create(imp->getExtentOfChar(offset, ec)).get(), imp);
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetRotationOfChar(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = jsNumber(exec, imp->getRotationOfChar(offset, ec));
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetCharNumAtPosition(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    FloatPoint point = toSVGPoint(args.at(0));


    JSC::JSValue result = jsNumber(exec, imp->getCharNumAtPosition(point));
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionSelectSubString(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    int length = args.at(1).toInt32(exec);
    if (length < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }

    imp->selectSubString(offset, length, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionHasExtension(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    const UString& extension = args.at(0).toString(exec);


    JSC::JSValue result = jsBoolean(imp->hasExtension(extension));
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextContentElementPrototypeFunctionGetPresentationAttribute(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextContentElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextContentElement* castedThisObj = static_cast<JSSVGTextContentElement*>(asObject(thisValue));
    SVGTextContentElement* imp = static_cast<SVGTextContentElement*>(castedThisObj->impl());
    const UString& name = args.at(0).toString(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->getPresentationAttribute(name)));
    return result;
}

// Constant getters

JSValue jsSVGTextContentElementLENGTHADJUST_UNKNOWN(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0));
}

JSValue jsSVGTextContentElementLENGTHADJUST_SPACING(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsSVGTextContentElementLENGTHADJUST_SPACINGANDGLYPHS(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}


}

#endif // ENABLE(SVG)
