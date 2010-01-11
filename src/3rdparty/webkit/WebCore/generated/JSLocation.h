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

#ifndef JSLocation_h
#define JSLocation_h

#include "DOMObjectWithSVGContext.h"
#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class Location;

class JSLocation : public DOMObjectWithGlobalPointer {
    typedef DOMObjectWithGlobalPointer Base;
public:
    JSLocation(NonNullPassRefPtr<JSC::Structure>, JSDOMGlobalObject*, PassRefPtr<Location>);
    virtual ~JSLocation();
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    bool getOwnPropertySlotDelegate(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    bool getOwnPropertyDescriptorDelegate(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    bool putDelegate(JSC::ExecState*, const JSC::Identifier&, JSC::JSValue, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags));
    }

    virtual bool deleteProperty(JSC::ExecState*, const JSC::Identifier&);
    virtual void getOwnPropertyNames(JSC::ExecState*, JSC::PropertyNameArray&);
    virtual void defineGetter(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSObject* getterFunction, unsigned attributes);

    // Custom attributes
    void setHref(JSC::ExecState*, JSC::JSValue);
    void setProtocol(JSC::ExecState*, JSC::JSValue);
    void setHost(JSC::ExecState*, JSC::JSValue);
    void setHostname(JSC::ExecState*, JSC::JSValue);
    void setPort(JSC::ExecState*, JSC::JSValue);
    void setPathname(JSC::ExecState*, JSC::JSValue);
    void setSearch(JSC::ExecState*, JSC::JSValue);
    void setHash(JSC::ExecState*, JSC::JSValue);

    // Custom functions
    JSC::JSValue assign(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue replace(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue reload(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue toString(JSC::ExecState*, const JSC::ArgList&);
    Location* impl() const { return m_impl.get(); }

private:
    RefPtr<Location> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetPropertyNames | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, Location*);
Location* toLocation(JSC::JSValue);

class JSLocationPrototype : public JSC::JSObject {
    typedef JSC::JSObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags));
    }
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    bool putDelegate(JSC::ExecState*, const JSC::Identifier&, JSC::JSValue, JSC::PutPropertySlot&);
    virtual void defineGetter(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSObject* getterFunction, unsigned attributes);
    JSLocationPrototype(NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::JSValue JSC_HOST_CALL jsLocationPrototypeFunctionAssign(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsLocationPrototypeFunctionReplace(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsLocationPrototypeFunctionReload(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsLocationPrototypeFunctionToString(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
// Attributes

JSC::JSValue jsLocationHref(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationHref(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationProtocol(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationProtocol(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationHost(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationHost(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationHostname(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationHostname(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationPort(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationPort(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationPathname(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationPathname(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationSearch(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationSearch(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsLocationHash(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSLocationHash(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);

} // namespace WebCore

#endif
