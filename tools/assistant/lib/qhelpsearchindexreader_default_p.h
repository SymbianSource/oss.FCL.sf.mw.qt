/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef QHELPSEARCHINDEXREADERDEFAULT_H
#define QHELPSEARCHINDEXREADERDEFAULT_H

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

#include "qhelpsearchindex_default_p.h"
#include "qhelpsearchindexreader_p.h"

#include <QtCore/QHash>
#include <QtCore/QPair>

QT_BEGIN_NAMESPACE

struct Entry;
struct PosEntry;

namespace qt {
    namespace fulltextsearch {
        namespace std {

class Reader
{
    typedef QList<QStringList> DocumentList;
    typedef QHash<QString, Entry*> EntryTable;
    typedef QPair<EntryTable, DocumentList> Index;
    typedef QHash<QString, Index> IndexTable;

public:
    Reader();
    ~Reader();

    bool readIndex();
    bool initCheck() const;
    void setIndexPath(const QString &path);
    void filterFilesForAttributes(const QStringList &attributes);
    void setIndexFile(const QString &namespaceName, const QString &attributes);
    bool splitSearchTerm(const QString &searchTerm, QStringList *terms,
        QStringList *termSeq, QStringList *seqWords);

    void searchInIndex(const QStringList &terms);
    QVector<DocumentInfo> hits();
    bool searchForPattern(const QStringList &patterns,
        const QStringList &words, const QByteArray &data);

private:
    QVector<Document> setupDummyTerm(const QStringList &terms, const EntryTable &entryTable);
    QStringList getWildcardTerms(const QString &term, const EntryTable &entryTable);
    void buildMiniIndex(const QString &string);
    void reset();
    void cleanupIndex(EntryTable &entryTable);

private:
    uint wordNum;
    QString indexPath;
    QString indexFile;
    QString documentFile;

    IndexTable indexTable;
    QList<TermInfo> termList;
    IndexTable searchIndexTable;
    QHash<QString, PosEntry*> miniIndex;
};


class QHelpSearchIndexReaderDefault : public QHelpSearchIndexReader
{
    Q_OBJECT

public:
    QHelpSearchIndexReaderDefault();
    ~QHelpSearchIndexReaderDefault();

private:
    void run();

private:
    Reader m_reader;
};

        }   // namespace std
    }   // namespace fulltextsearch
}   // namespace qt

QT_END_NAMESPACE

#endif  // QHELPSEARCHINDEXREADERDEFAULT_H
