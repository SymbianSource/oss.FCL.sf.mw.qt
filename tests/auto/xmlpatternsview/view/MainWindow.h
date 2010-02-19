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

#ifndef PatternistSDK_MainWindow_H
#define PatternistSDK_MainWindow_H

#include <QtDebug>
#include <QUrl>

#include "ui_ui_MainWindow.h"
#include "DebugExpressionFactory.h"
#include "TestSuite.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternistSDK
{
    class FunctionSignaturesView;
    class TestCase;
    class TestCaseView;
    class TestResultView;
    class TreeModel;
    class UserTestCase;

    /**
     * @short The main window of the PatternistSDKView application.
     *
     * MainWindow is heavily influenced by Qt's examples covering recent files,
     * main window usage, QSettings, and other central parts.
     *
     * @ingroup PatternistSDK
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class MainWindow : public QMainWindow,
                       private Ui_MainWindow
    {
        Q_OBJECT
    public:
        MainWindow();
        virtual ~MainWindow();

        /**
         * Takes care of saving QSettings.
         */
        virtual void closeEvent(QCloseEvent *event);

    Q_SIGNALS:
        /**
         * Emitted whenever a test case is selected. The test case
         * selected is @p tc. If something that wasn't a test case
         * was selected, such as a test group or that a new test suite was
         * opened, @p tc is @c null.
         */
        void testCaseSelected(TestCase *const tc);

    private Q_SLOTS:
        /**
         * The Open action calls this slot. It is responsible
         * for opening a test suite catalog file.
         */
        void on_actionOpen_triggered();

        void on_actionOpenXSLTSCatalog_triggered();

        void on_actionOpenXSDTSCatalog_triggered();

        /**
         * Executes the selected test case or test group.
         */
        void on_actionExecute_triggered();

        /**
         * @param file the name of the catalog to open.
         * @param reportError whether the user should be notified about a loading error. If @c true,
         * an informative message box will be displayed, if any errors occurred.
         */
        void openCatalog(const QUrl &file, const bool reportError,
                         const TestSuite::SuiteType suitType);

        void openRecentFile();

        void on_testSuiteView_clicked(const QModelIndex &index);

        void on_sourceTab_currentChanged(int index);
        void on_sourceInput_textChanged();

        /**
         * Restarts the program by executing restartApplication.sh loaded as a QResource file,
         * combined with shutting down this instance.
         */
        void on_actionRestart_triggered();

        void writeSettings();

    private:
        /**
         * Saves typing a long line.
         *
         * @returns the source model the index in the proxy @p proxyIndex corresponds to.
         */
        inline QModelIndex sourceIndex(const QModelIndex &proxyIndex) const;

        /**
         * Saves typing a long line.
         *
         * @returns the source model for the test suite view, by walking through the
         * proxy model.
         */
        inline TreeModel *sourceModel() const;

        void setupMenu();
        void setupActions();
        void readSettings();
        void setCurrentFile(const QUrl &fileName);
        void updateRecentFileActions();

        UserTestCase *const         m_userTC;

        enum {MaximumRecentFiles = 5};
        QAction *                   m_recentFileActs[MaximumRecentFiles];

        /**
         * The current selected test case.
         */
        TestCase *                  m_currentTC;
        QUrl                        m_previousOpenedCatalog;
        TestCaseView *              testCaseView;
        TestResultView *            testResultView;
        FunctionSignaturesView *    functionView;
        TestSuite::SuiteType        m_currentSuiteType;
    };
}
QT_END_NAMESPACE

QT_END_HEADER

#endif
// vim: et:ts=4:sw=4:sts=4
