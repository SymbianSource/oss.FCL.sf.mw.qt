/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
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

#include <QXmlAttributes>
#include <QtDebug>

#include "qdebug_p.h"
#include "Global.h"
#include "XMLWriter.h"

#include "TestResult.h"

using namespace QPatternistSDK;
using namespace QPatternist;

QString TestResult::displayName(const TestResult::Status stat)
{
    switch(stat)
    {
        case Pass:
            return QLatin1String("pass");
        case Fail:
            return QLatin1String("fail");
        case NotTested:
            return QLatin1String("not tested");
        case Unknown:
            Q_ASSERT(false);
    }

    Q_ASSERT(false);
    return QString();
}

TestResult::Status TestResult::statusFromString(const QString &string)
{
    if(string == QLatin1String("pass"))
        return Pass;
    else if(string == QLatin1String("fail"))
        return Fail;
    else if(string == QLatin1String("not tested"))
        return NotTested;
    else
    {
        Q_ASSERT(false);
        return Fail;
    }
}

TestResult::TestResult(const QString &n,
                       const Status s,
                       ASTItem *tree,
                       const ErrorHandler::Message::List &ers,
                       const QPatternist::Item::List &itemsP,
                       const QString &serialized) : m_status(s),
                                                    m_messages(ers),
                                                    m_astTree(tree),
                                                    m_testName(n),
                                                    m_items(itemsP),
                                                    m_asSerialized(serialized)
{
    Q_ASSERT(!n.isEmpty());
    Q_ASSERT(s != 0);
}

TestResult::~TestResult()
{
    delete m_astTree;
}

void TestResult::toXML(XMLWriter &receiver) const
{
    QXmlAttributes atts;
    atts.append(QLatin1String("name"), QString(), QLatin1String("name"), m_testName);
    atts.append(QLatin1String("result"), QString(), QLatin1String("result"), displayName(m_status));

    if(!m_comment.isEmpty())
        atts.append(QLatin1String("comment"), QString(), QLatin1String("comment"), m_comment);

    receiver.startElement(QLatin1String("test-case"), atts);
    receiver.endElement(QLatin1String("test-case"));
}

void TestResult::setComment(const QString &comm)
{
    m_comment = comm;
}

TestResult::Status TestResult::status() const
{
    return m_status;
}

QString TestResult::comment() const
{
    return m_comment;
}

ASTItem *TestResult::astTree() const
{
    return m_astTree;
}

ErrorHandler::Message::List TestResult::messages() const
{
    return m_messages;
}

QPatternist::Item::List TestResult::items() const
{
    return m_items;
}

QString TestResult::asSerialized() const
{
    pDebug() << "asSerialized: " << m_asSerialized;
    return m_asSerialized;
}

// vim: et:ts=4:sw=4:sts=4

