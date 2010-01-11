/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the autotests of the Qt Toolkit.
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

#ifndef PatternistSDK_XSDTSTestCase_H
#define PatternistSDK_XSDTSTestCase_H

#include <QDate>
#include <QString>
#include <QUrl>

#include "TestBaseLine.h"
#include "TestCase.h"

QT_BEGIN_HEADER

namespace QPatternistSDK
{
    /**
     * @short Represents a test case in a test suite in the XML Query Test Suite.
     *
     * TestCase is a memory representation of a test case, and maps
     * to the @c test-case element in the XQuery Test Suite test
     * case catalog.
     *
     * @ingroup PatternistSDK
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Q_PATTERNISTSDK_EXPORT XSDTSTestCase : public TestCase
    {
    public:
        enum TestType
        {
            SchemaTest,
            InstanceTest
        };

        XSDTSTestCase(const Scenario scen, TreeItem *parent, TestType testType);
        virtual ~XSDTSTestCase();

        /**
         * Executes the test, and returns the result. The returned list
         * will always contain exactly one TestResult.
         *
         * @p stage is ignored when running out-of-process.
         */
        virtual TestResult::List execute(const ExecutionStage stage,
                                         TestSuite *ts);
        /**
         * The identifier, the name of the test. For example, "Literals034".
         * The name of a test case must be unique.
         */
        virtual QString name() const;
        virtual QString creator() const;
        virtual QString description() const;
        /**
         * @returns the query inside the file, specified by testCasePath(). Loading
         * of the file is not cached in order to avoid complications.
         * @param ok is set to @c false if loading the query file fails
         */
        virtual QString sourceCode(bool &ok) const;
        virtual QUrl schemaUri() const;
        virtual QUrl instanceUri() const;
        virtual QUrl testCasePath() const {return QUrl();}
        virtual QDate lastModified() const;

        bool isXPath() const;

        /**
         * What kind of test case this is, what kind of scenario it takes part
         * of. For example, whether the test case should evaluate normally or fail.
         */
        Scenario scenario() const;

        void setCreator(const QString &creator);
        void setLastModified(const QDate &date);
        void setDescription(const QString &description);
        void setName(const QString &name);
        void setSchemaUri(const QUrl &uri);
        void setInstanceUri(const QUrl &uri);
        void setTestCasePath(const QUrl & /* uri */) {}
        void setContextItemSource(const QUrl &uri);
        void addBaseLine(TestBaseLine *lines);

        virtual TreeItem *parent() const;

        virtual QVariant data(const Qt::ItemDataRole role, int column) const;

        virtual QString title() const;
        virtual TestBaseLine::List baseLines() const;

        virtual int columnCount() const;

        virtual QUrl contextItemSource() const;
        void setParent(TreeItem *const parent);
        virtual QPatternist::ExternalVariableLoader::Ptr externalVariableLoader() const;
        virtual TestResult *testResult() const;
        virtual ResultSummary resultSummary() const;

    private:
        void executeSchemaTest(TestResult::Status &resultStatus, QString &serialized, QAbstractMessageHandler *handler);
        void executeInstanceTest(TestResult::Status &resultStatus, QString &serialized, QAbstractMessageHandler *handler);

        QString                                     m_name;
        QString                                     m_creator;
        QString                                     m_description;
        QUrl                                        m_schemaUri;
        QUrl                                        m_instanceUri;
        QDate                                       m_lastModified;
        const Scenario                              m_scenario;
        TreeItem *                                  m_parent;
        TestBaseLine::List                          m_baseLines;
        QUrl                                        m_contextItemSource;
        TestType                                    m_testType;
        QPointer<TestResult>                        m_result;
    };
}

QT_END_HEADER

#endif
// vim: et:ts=4:sw=4:sts=4
