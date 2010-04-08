/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the documentation of the Qt Toolkit.
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

#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <phonon/backendcapabilities.h>
#include <phonon/effect.h>
#include <phonon/effectwidget.h>

int main(int argv, char **args)
{
    QApplication app(argv, args);
    app.setApplicationName("Audio effect tester");

    Phonon::MediaObject *mediaObject = new Phonon::MediaObject;
    mediaObject->setCurrentSource(QString("/home/gvatteka/Music/Lumme-Badloop.ogg"));

    Phonon::AudioOutput *audioOutput =
        new Phonon::AudioOutput(Phonon::MusicCategory);

//! [0]
    QList<Phonon::EffectDescription> effectDescriptions =
            Phonon::BackendCapabilities::availableAudioEffects();
    Phonon::EffectDescription effectDescription = effectDescriptions.at(4);

    Phonon::Path path = Phonon::createPath(mediaObject, audioOutput);

//! [1]
    Phonon::Effect *effect = new Phonon::Effect(effectDescription);
    path.insertEffect(effect);
//! [0]

    Phonon::EffectWidget *effectWidget = new Phonon::EffectWidget(effect);
    effectWidget->show();
//! [1]

    mediaObject->play();

    effectWidget->setWindowTitle("Effect Name: " + effectDescription.name());

    app.exec();
}