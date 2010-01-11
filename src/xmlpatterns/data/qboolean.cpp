/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qatomictype_p.h"
#include "qbuiltintypes_p.h"
#include "qcommonvalues_p.h"
#include "qdynamiccontext_p.h"
#include "qpatternistlocale_p.h"
#include "qvalidationerror_p.h"

#include "qboolean_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool Boolean::evaluateEBV(const Item::Iterator::Ptr &it,
                          const QExplicitlySharedDataPointer<DynamicContext> &context)
{
    return evaluateEBV(it->next(), it, context);
}

bool Boolean::evaluateEBV(const Item &first,
                          const Item::Iterator::Ptr &it,
                          const QExplicitlySharedDataPointer<DynamicContext> &context)
{
    Q_ASSERT(it);
    Q_ASSERT(context);

    if(!first)
        return false;
    else if(first.isNode())
        return true;

    const Item second(it->next());

    if(second)
    {
        Q_ASSERT(context);
        context->error(QtXmlPatterns::tr("Effective Boolean Value cannot be calculated for a sequence "
                                         "containing two or more atomic values."),
                          ReportContext::FORG0006,
                          QSourceLocation());
        return false;
    }
    else
        return first.as<AtomicValue>()->evaluateEBV(context);
}

bool Boolean::evaluateEBV(const Item &item,
                          const QExplicitlySharedDataPointer<DynamicContext> &context)
{
    if(!item)
        return false;
    else if(item.isNode())
        return true;
    else
        return item.as<AtomicValue>()->evaluateEBV(context);
}

Boolean::Boolean(const bool value) : m_value(value)
{
}

QString Boolean::stringValue() const
{
    return m_value
            ? CommonValues::TrueString->stringValue()
            : CommonValues::FalseString->stringValue();
}

bool Boolean::evaluateEBV(const QExplicitlySharedDataPointer<DynamicContext> &) const
{
    return m_value;
}

Boolean::Ptr Boolean::fromValue(const bool value)
{
    return value ? CommonValues::BooleanTrue : CommonValues::BooleanFalse;
}

AtomicValue::Ptr Boolean::fromLexical(const QString &lexical)
{
    const QString val(lexical.trimmed()); /* Apply the whitespace facet. */

    if(val == QLatin1String("true") || val == QChar(QLatin1Char('1')))
        return CommonValues::BooleanTrue;
    else if(val == QLatin1String("false") || val == QChar(QLatin1Char('0')))
        return CommonValues::BooleanFalse;
    else
        return ValidationError::createError();
}

ItemType::Ptr Boolean::type() const
{
    return BuiltinTypes::xsBoolean;
}

QT_END_NAMESPACE
