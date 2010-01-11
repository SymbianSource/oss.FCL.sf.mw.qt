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


#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QUrl>

#include "TestFundament.h"

/*!
   This constructor is protected, such
   that inheritance is necessary.
 */
TestFundament::TestFundament()
{
}

QString TestFundament::offset()
{
#if defined(Q_OS_WIN) && !defined(Q_OS_WINCE)
    /* On Windows, the executable is placed in a release/ or debug/ folder. */
    return QLatin1String("../");
#elif defined(Q_OS_MAC)
    return QLatin1String("../../../");
#else
    return QString();
#endif
}

QString TestFundament::relativeInputFile(const QString &file)
{
    return QDir::cleanPath(offset() + file);
}

QUrl TestFundament::inputFileAsURI(const QString &file)
{
    return QUrl::fromLocalFile(inputFile(file));
}

QString TestFundament::inputFile(const QString &file)
{
    if(QDir::isAbsolutePath(file))
        return file;
    else
    {
        return QDir::cleanPath(QCoreApplication::applicationDirPath()
                               + QLatin1Char('/')
                               + offset()
                               + file);
    }
}

