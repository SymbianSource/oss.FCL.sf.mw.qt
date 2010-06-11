/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
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

#include <QtGui>

#include "dialog.h"
#include "wigglywidget.h"

//! [0]
Dialog::Dialog(QWidget *parent, bool smallScreen)
    : QDialog(parent)
{
    WigglyWidget *wigglyWidget = new WigglyWidget;
    QLineEdit *lineEdit = new QLineEdit;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(wigglyWidget);
    layout->addWidget(lineEdit);
    setLayout(layout);

#ifdef QT_SOFTKEYS_ENABLED
    QAction *exitAction = new QAction(tr("Exit"), this);
    exitAction->setSoftKeyRole(QAction::NegativeSoftKey);
    connect (exitAction, SIGNAL(triggered()),this, SLOT(close()));
    addAction (exitAction);

    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowSoftkeysVisibleHint;
    setWindowFlags(flags);
#endif

    connect(lineEdit, SIGNAL(textChanged(QString)),
            wigglyWidget, SLOT(setText(QString)));
    if (!smallScreen){
        lineEdit->setText(tr("Hello world!"));
    }
    else{
        lineEdit->setText(tr("Hello!"));
    }
    setWindowTitle(tr("Wiggly"));
    resize(360, 145);
}
//! [0]
