/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef PatternistSDK_TreeItem_H
#define PatternistSDK_TreeItem_H

#include <QObject>

#include "Global.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QVariant;
template<typename T> class QList;
template<typename T> class QPointer;

namespace QPatternistSDK
{
    /**
     * @short TreeItem is a node in a hierachial structure and is used together
     * with TreeModel.
     *
     * TreeItem is abstract base class. Instances of sub-classes of TreeItem
     * can be used with TreeModel in order to use hierarchial data in Qt's
     * model/view framework.
     *
     * TreeItem is a QObject in order to be able to be used with QPointer.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @see TreeModel
     * @ingroup PatternistSDK
     */
    class Q_PATTERNISTSDK_EXPORT TreeItem : public QObject
    {
        Q_OBJECT
    public:
        typedef QList<QPointer<TreeItem> > List;

        virtual ~TreeItem() {}
        virtual void appendChild(TreeItem *item) = 0;
        virtual TreeItem *child(const unsigned int row) const = 0;
        virtual unsigned int childCount() const = 0;
        virtual TreeItem *parent() const = 0;

        virtual TreeItem::List children() const = 0;
        virtual int columnCount() const = 0;

        /**
         * Determines the position among the children of
         * this TreeItem's parent. This is done by introspecting the result
         * of children().
         */
        int row() const;

        virtual QVariant data(const Qt::ItemDataRole role, int column) const = 0;

    Q_SIGNALS:
        /**
         * Emitted whenever this item changed. This is used for keeping
         * views in synchronization with the item model which houses
         * this item.
         *
         * @param item the item which changed. That is, this TreeItem.
         */
        void changed(TreeItem *item);
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
// vim: et:ts=4:sw=4:sts=4
