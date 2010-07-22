/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
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

import Qt 4.7

Flipable {
    id: flipable
    property int angle: 0

    width: 40;  height: 40
    transform: Rotation { origin.x: 20; origin.y: 20; axis.x: 1; axis.z: 0; angle: flipable.angle }

    front: Image {
        source: "pics/front.png"; width: 40; height: 40

        Image {
            anchors.centerIn: parent
            source: "pics/flag.png"; opacity: modelData.hasFlag

            Behavior on opacity { NumberAnimation {} }
        }
    }

    back: Image {
        source: "pics/back.png"
        width: 40; height: 40

        Text {
            anchors.centerIn: parent
            text: modelData.hint; color: "white"; font.bold: true
            opacity: !modelData.hasMine && modelData.hint > 0
        }

        Image {
            anchors.centerIn: parent
            source: "pics/bomb.png"; opacity: modelData.hasMine
        }

        Explosion { id: expl }
    }

    states: State {
        name: "back"; when: modelData.flipped
        PropertyChanges { target: flipable; angle: 180 }
    }

    property real pauseDur: 250
    transitions: Transition {
        SequentialAnimation {
            ScriptAction {
                script: {
                    var ret = Math.abs(flipable.x - field.clickx)
                        + Math.abs(flipable.y - field.clicky);
                    if (modelData.hasMine && modelData.flipped)
                        pauseDur = ret * 3
                    else
                        pauseDur = ret
                }
            }
            PauseAnimation {
                duration: pauseDur
            }
            RotationAnimation { easing.type: Easing.InOutQuad }
            ScriptAction { script: if (modelData.hasMine && modelData.flipped) { expl.explode = true } }
        }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            field.clickx = flipable.x
            field.clicky = flipable.y
            var row = Math.floor(index / 9)
            var col = index - (Math.floor(index / 9) * 9)
            if (mouse.button == undefined || mouse.button == Qt.RightButton) {
                flag(row, col)
            } else {
                flip(row, col)
            }
        }
        onPressAndHold: {
            field.clickx = flipable.x
            field.clicky = flipable.y
            var row = Math.floor(index / 9)
            var col = index - (Math.floor(index / 9) * 9)
            flag(row, col)
        }
    }
}
