/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef TESTFUNCTIONRESULT_H
#define TESTFUNCTIONRESULT_H

#include <QStringList>

#include "benchmark.h"
#include "benchmarks.h"

class TestFunctionResult : public QObject
{
    Q_OBJECT
public:

    TestFunctionResult();
    ~TestFunctionResult();

public slots:
    Benchmark *createBenchmark();

    int benchmarkCount(const QString &tag);
    Benchmark* getBenchmark(const QString &tag, const int index);

    void addError(const QString &error);

    Benchmarks* benchmarks();

    QStringList& errors();

    QString name() const;
    void setName(const QString &name);

private:
    Q_DISABLE_COPY(TestFunctionResult)
    QString mName;
    Benchmarks mBenchmarks;
    QStringList mErrors;
};



#endif // TESTFUNCTIONRESULT_H
