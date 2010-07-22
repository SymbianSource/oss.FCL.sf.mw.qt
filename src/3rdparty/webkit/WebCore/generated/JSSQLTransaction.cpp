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

#if ENABLE(DATABASE)

#include "JSSQLTransaction.h"

#include "SQLTransaction.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSQLTransaction);

/* Hash table for prototype */

static const HashTableValue JSSQLTransactionPrototypeTableValues[2] =
{
    { "executeSql", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSQLTransactionPrototypeFunctionExecuteSql), (intptr_t)4 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSQLTransactionPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSQLTransactionPrototypeTableValues, 0 };
#else
    { 2, 1, JSSQLTransactionPrototypeTableValues, 0 };
#endif

const ClassInfo JSSQLTransactionPrototype::s_info = { "SQLTransactionPrototype", 0, &JSSQLTransactionPrototypeTable, 0 };

JSObject* JSSQLTransactionPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSQLTransaction>(exec, globalObject);
}

bool JSSQLTransactionPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSQLTransactionPrototypeTable, this, propertyName, slot);
}

bool JSSQLTransactionPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSQLTransactionPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSQLTransaction::s_info = { "SQLTransaction", 0, 0, 0 };

JSSQLTransaction::JSSQLTransaction(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SQLTransaction> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSSQLTransaction::~JSSQLTransaction()
{
    forgetDOMObject(this, impl());
}

JSObject* JSSQLTransaction::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSQLTransactionPrototype(JSSQLTransactionPrototype::createStructure(globalObject->objectPrototype()));
}

JSValue JSC_HOST_CALL jsSQLTransactionPrototypeFunctionExecuteSql(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSQLTransaction::s_info))
        return throwError(exec, TypeError);
    JSSQLTransaction* castedThisObj = static_cast<JSSQLTransaction*>(asObject(thisValue));
    return castedThisObj->executeSql(exec, args);
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SQLTransaction* object)
{
    return getDOMObjectWrapper<JSSQLTransaction>(exec, globalObject, object);
}
SQLTransaction* toSQLTransaction(JSC::JSValue value)
{
    return value.inherits(&JSSQLTransaction::s_info) ? static_cast<JSSQLTransaction*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(DATABASE)
