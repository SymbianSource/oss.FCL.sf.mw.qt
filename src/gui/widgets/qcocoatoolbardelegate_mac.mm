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

#import <private/qcocoatoolbardelegate_mac_p.h>
#ifdef QT_MAC_USE_COCOA
#include <private/qmainwindowlayout_p.h>
#include <private/qt_mac_p.h>
#include <private/qt_cocoa_helpers_mac_p.h>
#include <private/qcocoaview_mac_p.h>
#include <private/qwidget_p.h>
#include <qtoolbar.h>
#include <qlayout.h>
#include <qdebug.h>

QT_BEGIN_NAMESPACE
extern QWidgetPrivate *qt_widget_private(QWidget *widget);
QT_END_NAMESPACE

QT_FORWARD_DECLARE_CLASS(QMainWindowLayout);
QT_FORWARD_DECLARE_CLASS(QToolBar);
QT_FORWARD_DECLARE_CLASS(QCFString);

@implementation QT_MANGLE_NAMESPACE(QCocoaToolBarDelegate)

- (id)initWithMainWindowLayout:(QMainWindowLayout *)layout
{
    self = [super init];
    if (self) {
        mainWindowLayout = layout;
    }
    return self;
}

- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar *)toolbar
{
    Q_UNUSED(toolbar);
    return [NSArray arrayWithObject:@"com.trolltech.qt.nstoolbar-qtoolbar"];
}

- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar *)toolbar
{
    return [self toolbarAllowedItemIdentifiers:toolbar];
}

- (void)toolbarDidRemoveItem:(NSNotification *)notification
{
    NSToolbarItem *item = [[notification userInfo] valueForKey:@"item"];
    mainWindowLayout->unifiedToolbarHash.remove(item);
    for (int i = 0; i < mainWindowLayout->toolbarItemsCopy.size(); ++i) {
        if (mainWindowLayout->toolbarItemsCopy.at(i) == item) {
            // I know about it, so release it.
            mainWindowLayout->toolbarItemsCopy.removeAt(i);
            mainWindowLayout->qtoolbarsInUnifiedToolbarList.removeAt(i);
            [item release];
            break;
        }
    }
}

- (NSToolbarItem *)toolbar:(NSToolbar *)nstoolbar itemForItemIdentifier:(NSString *)itemIdentifier
    willBeInsertedIntoToolbar:(BOOL)flag
{
    Q_UNUSED(flag);
    Q_UNUSED(nstoolbar);
    QToolBar *tb = mainWindowLayout->cocoaItemIDToToolbarHash.value(
            QT_PREPEND_NAMESPACE(qt_mac_NSStringToQString)(itemIdentifier));
    NSToolbarItem *item = nil;
    if (tb) {
        item = [[NSToolbarItem alloc] initWithItemIdentifier:itemIdentifier];
        mainWindowLayout->unifiedToolbarHash.insert(item, tb);
    }
    return item;
}

- (void)toolbarWillAddItem:(NSNotification *)notification
{
    NSToolbarItem *item = [[notification userInfo] valueForKey:@"item"];
    QToolBar *tb = mainWindowLayout->cocoaItemIDToToolbarHash.value(
            QT_PREPEND_NAMESPACE(qt_mac_NSStringToQString)([item itemIdentifier]));
    if (!tb)
        return; // I can't really do anything about this.
    [item retain];
    [item setView:QT_PREPEND_NAMESPACE(qt_mac_nativeview_for)(tb)];

    NSArray *items = [[qt_mac_window_for(mainWindowLayout->layoutState.mainWindow->window()) toolbar] items];
    int someIndex = 0;
    for (NSToolbarItem *i in items) {
        if (i == item)
            break;
        ++someIndex;
    }
    mainWindowLayout->toolbarItemsCopy.insert(someIndex, item);

    // This is synchronization code that was needed in Carbon, but may not be needed anymore here.
    QToolBar *toolbar = mainWindowLayout->unifiedToolbarHash.value(item);
    if (toolbar) {
        int toolbarIndex = mainWindowLayout->qtoolbarsInUnifiedToolbarList.indexOf(toolbar);
        if (someIndex != toolbarIndex) {
            // Dang, we must be out of sync, rebuild it from the "toolbarItemsCopy"
            mainWindowLayout->qtoolbarsInUnifiedToolbarList.clear();
            for (int i = 0; i < mainWindowLayout->toolbarItemsCopy.size(); ++i) {
                // This will either append the correct toolbar or an
                // null toolbar. This is fine because this list
                // is really only kept to make sure that things are but in the right order.
                mainWindowLayout->qtoolbarsInUnifiedToolbarList.append(
                                  mainWindowLayout->unifiedToolbarHash.value(mainWindowLayout->
                                                                        toolbarItemsCopy.at(i)));
            }
        }
        toolbar->update();
    }
}

@end
#endif // QT_MAC_USE_COCOA
