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

#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneResizeEvent>
#include <QPainter>
#include <QRectF>

#include "backgrounditem.h"
#include "theme.h"

BackgroundItem::BackgroundItem(const QString &filename, QGraphicsWidget *parent)
    : GvbWidget(parent),
      m_background(),
      m_fileName(filename)
{
    setContentsMargins(0,0,0,0);

    connect(Theme::p(), SIGNAL(themeChanged()), this, SLOT(themeChange()));
}

BackgroundItem::~BackgroundItem()
{
    
}

void BackgroundItem::resizeEvent(QGraphicsSceneResizeEvent *event)
{
    GvbWidget::resizeEvent(event);
    m_background = Theme::p()->pixmap(m_fileName, size().toSize());
}

void BackgroundItem::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
{
    Q_UNUSED(widget)
    painter->setCompositionMode(QPainter::CompositionMode_Source);
    painter->drawPixmap(option->exposedRect, m_background, option->exposedRect);
}

void BackgroundItem::themeChange()
{
    m_background = Theme::p()->pixmap(m_fileName, size().toSize());
    update();
}

