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

#ifndef JSHTMLDataGridCellElement_h
#define JSHTMLDataGridCellElement_h

#if ENABLE(DATAGRID)

#include "JSHTMLElement.h"

namespace WebCore {

class HTMLDataGridCellElement;

class JSHTMLDataGridCellElement : public JSHTMLElement {
    typedef JSHTMLElement Base;
public:
    JSHTMLDataGridCellElement(NonNullPassRefPtr<JSC::Structure>, JSDOMGlobalObject*, PassRefPtr<HTMLDataGridCellElement>);
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};


class JSHTMLDataGridCellElementPrototype : public JSC::JSObject {
    typedef JSC::JSObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }
    JSHTMLDataGridCellElementPrototype(NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsHTMLDataGridCellElementLabel(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSHTMLDataGridCellElementLabel(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsHTMLDataGridCellElementFocused(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSHTMLDataGridCellElementFocused(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsHTMLDataGridCellElementChecked(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSHTMLDataGridCellElementChecked(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsHTMLDataGridCellElementIndeterminate(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSHTMLDataGridCellElementIndeterminate(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsHTMLDataGridCellElementProgress(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSHTMLDataGridCellElementProgress(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsHTMLDataGridCellElementConstructor(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif // ENABLE(DATAGRID)

#endif
