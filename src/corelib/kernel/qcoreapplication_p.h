/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
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

#ifndef QCOREAPPLICATION_P_H
#define QCOREAPPLICATION_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "QtCore/qcoreapplication.h"
#include "QtCore/qtranslator.h"
#include "private/qobject_p.h"

#ifdef Q_OS_SYMBIAN
#include <f32file.h>
#endif

QT_BEGIN_NAMESPACE

typedef QList<QTranslator*> QTranslatorList;

#if defined(Q_OS_SYMBIAN) && !defined(QT_NO_SYSTEMLOCALE)
class QEnvironmentChangeNotifier;
#endif
class QAbstractEventDispatcher;

class Q_CORE_EXPORT QCoreApplicationPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QCoreApplication)

public:
    QCoreApplicationPrivate(int &aargc,  char **aargv);
    ~QCoreApplicationPrivate();

    bool sendThroughApplicationEventFilters(QObject *, QEvent *);
    bool sendThroughObjectEventFilters(QObject *, QEvent *);
    bool notify_helper(QObject *, QEvent *);

    virtual QString appName() const;
    virtual void createEventDispatcher();
    static void removePostedEvent(QEvent *);
#ifdef Q_OS_WIN
    static void removePostedTimerEvent(QObject *object, int timerId);
#endif

#ifdef Q_OS_MAC
    static QString macMenuBarName();
#endif

    static QThread *theMainThread;
    static QThread *mainThread();
    static bool checkInstance(const char *method);
    static void sendPostedEvents(QObject *receiver, int event_type, QThreadData *data);

#if !defined (QT_NO_DEBUG) || defined (QT_MAC_FRAMEWORK_BUILD) || defined (Q_OS_SYMBIAN)
    void checkReceiverThread(QObject *receiver);
#endif
    int &argc;
    char **argv;
    void appendApplicationPathToLibraryPaths(void);

#ifndef QT_NO_TRANSLATION
    QTranslatorList translators;
#endif
    uint application_type;

    QCoreApplication::EventFilter eventFilter;

    bool in_exec;
    bool aboutToQuitEmitted;
    QString cachedApplicationDirPath;
    QString cachedApplicationFilePath;
#if defined(Q_OS_SYMBIAN) && !defined(QT_NO_SYSTEMLOCALE)
    QScopedPointer<QEnvironmentChangeNotifier> environmentChangeNotifier;
    void symbianInit();
#endif

    static bool isTranslatorInstalled(QTranslator *translator);

    static QAbstractEventDispatcher *eventDispatcher;
    static bool is_app_running;
    static bool is_app_closing;

    static uint attribs;
    static inline bool testAttribute(uint flag) { return attribs & (1 << flag); }
};

QT_END_NAMESPACE

#endif // QCOREAPPLICATION_P_H
