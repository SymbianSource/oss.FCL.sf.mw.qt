/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Assistant of the Qt Toolkit.
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

#ifndef QHELPSEARCHINDEXREADERCLUCENE_H
#define QHELPSEARCHINDEXREADERCLUCENE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists for the convenience
// of the help generator tools. This header file may change from version
// to version without notice, or even be removed.
//
// We mean it.
//

#include "qhelpsearchindexreader_p.h"

#include "fulltextsearch/qanalyzer_p.h"
#include "fulltextsearch/qquery_p.h"

QT_BEGIN_NAMESPACE

namespace fulltextsearch {
namespace clucene {

class QHelpSearchIndexReaderClucene : public QHelpSearchIndexReader
{
    Q_OBJECT

public:
    QHelpSearchIndexReaderClucene();
    ~QHelpSearchIndexReaderClucene();

private:
    void run();
    bool defaultQuery(const QString &term, QCLuceneBooleanQuery &booleanQuery,
        QCLuceneStandardAnalyzer &analyzer);
    bool buildQuery(QCLuceneBooleanQuery &booleanQuery, const QList<QHelpSearchQuery> &queryList,
        QCLuceneStandardAnalyzer &analyzer);
    bool buildTryHarderQuery(QCLuceneBooleanQuery &booleanQuery,
        const QList<QHelpSearchQuery> &queryList, QCLuceneStandardAnalyzer &analyzer);
    void boostSearchHits(const QHelpEngineCore &engine, QList<QHelpSearchEngine::SearchHit> &hitList,
        const QList<QHelpSearchQuery> &queryList);
};

}   // namespace clucene
}   // namespace fulltextsearch

QT_END_NAMESPACE

#endif  // QHELPSEARCHINDEXREADERCLUCENE_H
