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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QBitmap>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/data/monkey_on_64x64.png");

    QImage mask(16, 16, QImage::Format_MonoLSB);
    QImage bw(16, 16, QImage::Format_MonoLSB);
    mask.fill(0);
    bw.fill(0);
    for (int x = 0; x < 16; x++) {
        bw.setPixel(x, x, 1);
        bw.setPixel(x, 15 - x, 1);
        mask.setPixel(x, x, 1);
        mask.setPixel(x, 15 - x, 1);
        if (x > 0 && x < 15) {
            mask.setPixel(x - 1, x, 1);
            mask.setPixel(x + 1, x, 1);
            mask.setPixel(x - 1, 15 - x, 1);
            mask.setPixel(x + 1, 15 - x, 1);
        }
    }

    ccurs = QCursor(pix);
    bcurs = QCursor(QBitmap::fromImage(bw), QBitmap::fromImage(mask));
    ui->label->setCursor(ccurs);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(toggleOverrideCursor()));
    timer->start(2000);

    override = 0;
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::toggleOverrideCursor()
{
    switch (override) {
    case 0:
        QApplication::setOverrideCursor(Qt::BusyCursor);
        break;
    case 1:
        QApplication::restoreOverrideCursor();
        break;
    case 2:
        ui->label->grabMouse(Qt::ForbiddenCursor);
        break;
    case 3:
    case 5:
        ui->label->releaseMouse();
        break;
    case 4:
        ui->label->grabMouse();
        break;
    case 6:
        ui->label->setCursor(bcurs);
        break;
    case 7:
        ui->label->setCursor(ccurs);
        break;
    }
    override = (override + 1) % 8;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    QPoint off(0, 0);
    switch (event->key()) {
    case Qt::Key_Up:
        off.setY(-4);
        break;
    case Qt::Key_Down:
        off.setY(4);
        break;
    case Qt::Key_Left:
        off.setX(-4);
        break;
    case Qt::Key_Right:
        off.setX(4);
        break;
    default:
        return QMainWindow::keyPressEvent(event);
    }
    off += QCursor::pos();
    QCursor::setPos(off);
}
