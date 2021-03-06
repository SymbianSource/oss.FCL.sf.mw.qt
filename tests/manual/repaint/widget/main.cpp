/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
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

#include <QtGui>
#include "../shared/shared.h"

class Child : public StaticWidget
{
Q_OBJECT
public:
    Child(QWidget *parent)
    :StaticWidget(parent)
    {
        hue = 0;
    }
};

QWidget *c;

class TopLevel : public StaticWidget
{
Q_OBJECT
public:
    TopLevel()
    {
        resizeButton  = new QPushButton("resize", this);
        connect(resizeButton, SIGNAL(clicked()), SLOT(buttonResizeClicked()));

        movebutton  = new QPushButton("move", this);
        connect(movebutton, SIGNAL(clicked()), SLOT(buttonMoveClicked()));
        movebutton->move(70, 0);

        moveResizebutton  = new QPushButton("move + resize", this);
        connect(moveResizebutton, SIGNAL(clicked()), SLOT(buttonMoveResizeClicked()));
        moveResizebutton->move(150, 0);

        scrollbutton  = new QPushButton("scroll", this);
        connect(scrollbutton, SIGNAL(clicked()), SLOT(buttonScrollClicked()));
        scrollbutton->move(280, 0);
    }

public slots:
    void buttonResizeClicked()
    {
        c->resize(c->size() + QSize(15, 15));
        qDebug() << "child new size" << c->size();
    }

    void buttonMoveClicked()
    {
        c->move(c->pos() + QPoint(15, 15));
        qDebug() << "child moved" << c->pos();
    }

    void buttonMoveResizeClicked()
    {
        QRect g = c->geometry();
        g.adjust(15,15,30,30);
        c->setGeometry(g);
        qDebug() << "child moved" << c->pos() << "rezied" << c->size();
    }


    void buttonScrollClicked()
    {
        c->scroll(10, 10);
    }

protected:
    QPushButton * resizeButton;
    QPushButton * movebutton;
    QPushButton * moveResizebutton;
    QPushButton * scrollbutton;    
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    
    TopLevel bc;
    bc.resize(500, 500);

    c = new Child(&bc);
    c->move(100, 100);
    c->resize(100, 100);
    
    QWidget *gc  = new StaticWidget(c);
    gc->move(20, 20);
    gc->resize(50,50);
    

    bc.show();
    return app.exec();
}

#include "main.moc"

