/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the tools applications of the Qt Toolkit.
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

#include <qstring.h>
#include <qt_windows.h>

QT_BEGIN_NAMESPACE


enum Compiler {
    CC_UNKNOWN = 0,
    CC_BORLAND = 0x01,
    CC_MINGW   = 0x02,
    CC_INTEL   = 0x03,
    CC_MSVC4   = 0x40,
    CC_MSVC5   = 0x50,
    CC_MSVC6   = 0x60,
    CC_NET2002 = 0x70,
    CC_NET2003 = 0x71,
    CC_NET2005 = 0x80,
    CC_NET2008 = 0x90
};

struct CompilerInfo;
class Environment
{
public:
    static Compiler detectCompiler();
    static QString detectQMakeSpec();
    static bool detectExecutable(const QString &executable);

    static int execute(QStringList arguments, const QStringList &additionalEnv, const QStringList &removeEnv);
    static bool cpdir(const QString &srcDir, const QString &destDir);
    static bool rmdir(const QString &name);

    static QString symbianEpocRoot();

private:
    static Compiler detectedCompiler;

    static CompilerInfo *compilerInfo(Compiler compiler);
};


QT_END_NAMESPACE
