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

#ifndef LISTITEMCONTAINER_H
#define LISTITEMCONTAINER_H

#include <QGraphicsWidget>
#include <QColor>

#include "abstractitemcontainer.h"

class QGraphicsLinearLayout;
class AbstractViewItem;
class ListItemCache;
class ListItem;
class ItemRecyclingList;

class ListItemContainer : public AbstractItemContainer
{
    Q_OBJECT

public:
    ListItemContainer(int bufferSize, ItemRecyclingList *view, QGraphicsWidget *parent=0);
    virtual ~ListItemContainer();

    virtual void setTwoColumns(const bool twoColumns);

#if (QT_VERSION >= 0x040600)
    bool listItemCaching() const;
    void setListItemCaching(const bool enabled);
    virtual void setListItemCaching(const bool enabled, const int index);
#endif

protected:

   virtual void addItemToVisibleLayout(int index, AbstractViewItem *item);
   virtual void removeItemFromVisibleLayout(AbstractViewItem *item);

   virtual void adjustVisibleContainerSize(const QSizeF &size);
   virtual int maxItemCountInItemBuffer() const;

private:
    Q_DISABLE_COPY(ListItemContainer)

    ItemRecyclingList *m_view;
    QGraphicsLinearLayout *m_layout;
#if (QT_VERSION >= 0x040600)
    void setListItemCaching(const bool enabled, ListItem *listItem);
    bool m_listItemCaching;
#endif
};


#endif // LISTITEMCONTAINER_H
