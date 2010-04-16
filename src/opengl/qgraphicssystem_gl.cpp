/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtOpenGL module of the Qt Toolkit.
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

#include "qgraphicssystem_gl_p.h"

#include "private/qpixmap_raster_p.h"
#include "private/qpixmapdata_gl_p.h"
#include "private/qwindowsurface_gl_p.h"
#include "private/qgl_p.h"
#include <private/qwindowsurface_raster_p.h>

#if defined(Q_WS_X11) && defined(QT_OPENGL_ES)
#include "private/qpixmapdata_x11gl_p.h"
#include "private/qwindowsurface_x11gl_p.h"
#endif

QT_BEGIN_NAMESPACE

extern QGLWidget *qt_gl_getShareWidget();

QPixmapData *QGLGraphicsSystem::createPixmapData(QPixmapData::PixelType type) const
{
#if defined(Q_WS_X11) && defined(QT_OPENGL_ES)
    if (type == QPixmapData::PixmapType && QX11GLPixmapData::hasX11GLPixmaps())
        return new QX11GLPixmapData();
#endif

    return new QGLPixmapData(type);
}

QWindowSurface *QGLGraphicsSystem::createWindowSurface(QWidget *widget) const
{
#ifdef Q_WS_WIN
    // On Windows the QGLWindowSurface class can't handle
    // drop shadows and native effects, e.g. fading a menu in/out using
    // top level window opacity.
    if (widget->windowType() == Qt::Popup)
        return new QRasterWindowSurface(widget);
#endif

#if defined(Q_WS_X11) && defined(QT_OPENGL_ES)
    if (QX11GLPixmapData::hasX11GLPixmaps())
        return new QX11GLWindowSurface(widget);
#endif

    return new QGLWindowSurface(widget);
}

QT_END_NAMESPACE

