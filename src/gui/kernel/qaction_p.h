/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
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

#ifndef QACTION_P_H
#define QACTION_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "QtGui/qaction.h"
#include "QtGui/qmenu.h"
#include "private/qgraphicswidget_p.h"
#include "private/qobject_p.h"

QT_BEGIN_NAMESPACE

#ifndef QT_NO_ACTION

#ifdef QT3_SUPPORT
class QMenuItemEmitter;
#endif

class QShortcutMap;

class Q_AUTOTEST_EXPORT QActionPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QAction)
public:
    QActionPrivate();
    ~QActionPrivate();

    bool showStatusText(QWidget *w, const QString &str);

    QPointer<QActionGroup> group;
    QString text;
    QString iconText;
    QIcon icon;
    QString tooltip;
    QString statustip;
    QString whatsthis;
#ifndef QT_NO_SHORTCUT
    QKeySequence shortcut;
    QList<QKeySequence> alternateShortcuts;
#endif
    QVariant userData;
#ifndef QT_NO_SHORTCUT
    int shortcutId;
    QList<int> alternateShortcutIds;
    Qt::ShortcutContext shortcutContext;
    uint autorepeat : 1;
#endif
    QFont font;
    QPointer<QMenu> menu;
    uint enabled : 1, forceDisabled : 1;
    uint visible : 1, forceInvisible : 1;
    uint checkable : 1;
    uint checked : 1;
    uint separator : 1;
    uint fontSet : 1;
    QAction::MenuRole menuRole;
    QAction::SoftKeyRole softKeyRole;
    QAction::Priority priority;
    int iconVisibleInMenu : 3;  // Only has values -1, 0, and 1
    QList<QWidget *> widgets;
#ifndef QT_NO_GRAPHICSVIEW
    QList<QGraphicsWidget *> graphicsWidgets;
#endif
#ifndef QT_NO_SHORTCUT
    void redoGrab(QShortcutMap &map);
    void redoGrabAlternate(QShortcutMap &map);
    void setShortcutEnabled(bool enable, QShortcutMap &map);

    static QShortcutMap *globalMap;
#endif // QT_NO_SHORTCUT

#ifdef QT3_SUPPORT //for menubar/menu compat
    QMenuItemEmitter *act_signal;
    int id, param;
#endif
    void sendDataChanged();
};

#endif // QT_NO_ACTION

QT_END_NAMESPACE

#endif // QACTION_P_H
