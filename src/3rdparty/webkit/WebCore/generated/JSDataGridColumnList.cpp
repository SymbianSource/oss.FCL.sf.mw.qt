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

#if ENABLE(DATAGRID)

#include "JSDataGridColumnList.h"

#include "AtomicString.h"
#include "DataGridColumn.h"
#include "DataGridColumnList.h"
#include "ExceptionCode.h"
#include "JSDataGridColumn.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSDataGridColumnList);

/* Hash table */

static const HashTableValue JSDataGridColumnListTableValues[5] =
{
    { "length", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDataGridColumnListLength), (intptr_t)0 },
    { "sortColumn", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDataGridColumnListSortColumn), (intptr_t)0 },
    { "primaryColumn", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDataGridColumnListPrimaryColumn), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDataGridColumnListConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSDataGridColumnListTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSDataGridColumnListTableValues, 0 };
#else
    { 10, 7, JSDataGridColumnListTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSDataGridColumnListConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSDataGridColumnListConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSDataGridColumnListConstructorTableValues, 0 };
#else
    { 1, 0, JSDataGridColumnListConstructorTableValues, 0 };
#endif

class JSDataGridColumnListConstructor : public DOMConstructorObject {
public:
    JSDataGridColumnListConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSDataGridColumnListConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSDataGridColumnListPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSDataGridColumnListConstructor::s_info = { "DataGridColumnListConstructor", 0, &JSDataGridColumnListConstructorTable, 0 };

bool JSDataGridColumnListConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDataGridColumnListConstructor, DOMObject>(exec, &JSDataGridColumnListConstructorTable, this, propertyName, slot);
}

bool JSDataGridColumnListConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDataGridColumnListConstructor, DOMObject>(exec, &JSDataGridColumnListConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSDataGridColumnListPrototypeTableValues[6] =
{
    { "item", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsDataGridColumnListPrototypeFunctionItem), (intptr_t)1 },
    { "add", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsDataGridColumnListPrototypeFunctionAdd), (intptr_t)5 },
    { "remove", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsDataGridColumnListPrototypeFunctionRemove), (intptr_t)1 },
    { "move", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsDataGridColumnListPrototypeFunctionMove), (intptr_t)2 },
    { "clear", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsDataGridColumnListPrototypeFunctionClear), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSDataGridColumnListPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 31, JSDataGridColumnListPrototypeTableValues, 0 };
#else
    { 17, 15, JSDataGridColumnListPrototypeTableValues, 0 };
#endif

const ClassInfo JSDataGridColumnListPrototype::s_info = { "DataGridColumnListPrototype", 0, &JSDataGridColumnListPrototypeTable, 0 };

JSObject* JSDataGridColumnListPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSDataGridColumnList>(exec, globalObject);
}

bool JSDataGridColumnListPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSDataGridColumnListPrototypeTable, this, propertyName, slot);
}

bool JSDataGridColumnListPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSDataGridColumnListPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSDataGridColumnList::s_info = { "DataGridColumnList", 0, &JSDataGridColumnListTable, 0 };

JSDataGridColumnList::JSDataGridColumnList(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<DataGridColumnList> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSDataGridColumnList::~JSDataGridColumnList()
{
    forgetDOMObject(this, impl());
}

JSObject* JSDataGridColumnList::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSDataGridColumnListPrototype(JSDataGridColumnListPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSDataGridColumnList::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    const HashEntry* entry = JSDataGridColumnListTable.entry(exec, propertyName);
    if (entry) {
        slot.setCustom(this, entry->propertyGetter());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<DataGridColumnList*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    if (canGetItemsForName(exec, static_cast<DataGridColumnList*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    return getStaticValueSlot<JSDataGridColumnList, Base>(exec, &JSDataGridColumnListTable, this, propertyName, slot);
}

bool JSDataGridColumnList::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    const HashEntry* entry = JSDataGridColumnListTable.entry(exec, propertyName);
    if (entry) {
        PropertySlot slot;
        slot.setCustom(this, entry->propertyGetter());
        descriptor.setDescriptor(slot.getValue(exec, propertyName), entry->attributes());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<DataGridColumnList*>(impl())->length()) {
        PropertySlot slot;
        slot.setCustomIndex(this, index, indexGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), DontDelete | ReadOnly);
        return true;
    }
    if (canGetItemsForName(exec, static_cast<DataGridColumnList*>(impl()), propertyName)) {
        PropertySlot slot;
        slot.setCustom(this, nameGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), ReadOnly | DontDelete | DontEnum);
        return true;
    }
    return getStaticValueDescriptor<JSDataGridColumnList, Base>(exec, &JSDataGridColumnListTable, this, propertyName, descriptor);
}

bool JSDataGridColumnList::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<DataGridColumnList*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue jsDataGridColumnListLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDataGridColumnList* castedThis = static_cast<JSDataGridColumnList*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->length());
    return result;
}

JSValue jsDataGridColumnListSortColumn(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDataGridColumnList* castedThis = static_cast<JSDataGridColumnList*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->sortColumn()));
    return result;
}

JSValue jsDataGridColumnListPrimaryColumn(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDataGridColumnList* castedThis = static_cast<JSDataGridColumnList*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->primaryColumn()));
    return result;
}

JSValue jsDataGridColumnListConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDataGridColumnList* domObject = static_cast<JSDataGridColumnList*>(asObject(slotBase));
    return JSDataGridColumnList::getConstructor(exec, domObject->globalObject());
}
void JSDataGridColumnList::getOwnPropertyNames(ExecState* exec, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    for (unsigned i = 0; i < static_cast<DataGridColumnList*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getOwnPropertyNames(exec, propertyNames, mode);
}

JSValue JSDataGridColumnList::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSDataGridColumnListConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsDataGridColumnListPrototypeFunctionItem(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDataGridColumnList::s_info))
        return throwError(exec, TypeError);
    JSDataGridColumnList* castedThisObj = static_cast<JSDataGridColumnList*>(asObject(thisValue));
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThisObj->impl());
    int index = args.at(0).toInt32(exec);
    if (index < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->item(index)));
    return result;
}

JSValue JSC_HOST_CALL jsDataGridColumnListPrototypeFunctionAdd(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDataGridColumnList::s_info))
        return throwError(exec, TypeError);
    JSDataGridColumnList* castedThisObj = static_cast<JSDataGridColumnList*>(asObject(thisValue));
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThisObj->impl());
    const UString& id = args.at(0).toString(exec);
    const UString& label = args.at(1).toString(exec);
    const UString& type = args.at(2).toString(exec);
    bool primary = args.at(3).toBoolean(exec);
    unsigned short sortable = args.at(4).toInt32(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->add(id, label, type, primary, sortable)));
    return result;
}

JSValue JSC_HOST_CALL jsDataGridColumnListPrototypeFunctionRemove(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDataGridColumnList::s_info))
        return throwError(exec, TypeError);
    JSDataGridColumnList* castedThisObj = static_cast<JSDataGridColumnList*>(asObject(thisValue));
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThisObj->impl());
    DataGridColumn* column = toDataGridColumn(args.at(0));

    imp->remove(column);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDataGridColumnListPrototypeFunctionMove(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDataGridColumnList::s_info))
        return throwError(exec, TypeError);
    JSDataGridColumnList* castedThisObj = static_cast<JSDataGridColumnList*>(asObject(thisValue));
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThisObj->impl());
    DataGridColumn* column = toDataGridColumn(args.at(0));
    unsigned index = args.at(1).toInt32(exec);

    imp->move(column, index);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDataGridColumnListPrototypeFunctionClear(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDataGridColumnList::s_info))
        return throwError(exec, TypeError);
    JSDataGridColumnList* castedThisObj = static_cast<JSDataGridColumnList*>(asObject(thisValue));
    DataGridColumnList* imp = static_cast<DataGridColumnList*>(castedThisObj->impl());

    imp->clear();
    return jsUndefined();
}


JSValue JSDataGridColumnList::indexGetter(ExecState* exec, JSValue slotBase, unsigned index)
{
    JSDataGridColumnList* thisObj = static_cast<JSDataGridColumnList*>(asObject(slotBase));
    return toJS(exec, thisObj->globalObject(), static_cast<DataGridColumnList*>(thisObj->impl())->item(index));
}
JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, DataGridColumnList* object)
{
    return getDOMObjectWrapper<JSDataGridColumnList>(exec, globalObject, object);
}
DataGridColumnList* toDataGridColumnList(JSC::JSValue value)
{
    return value.inherits(&JSDataGridColumnList::s_info) ? static_cast<JSDataGridColumnList*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(DATAGRID)
