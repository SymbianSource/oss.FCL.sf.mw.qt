import Qt 4.7
Rectangle {
    width: 400
    height: 400
    Rectangle {
        id: rect
        objectName: "MyRect"
        width: 100; height: 100; color: "green"
        Behavior on x {
            objectName: "MyBehavior"
            NumberAnimation {id: na1; duration: 200 }
            NumberAnimation {id: na2; duration: 1000 }
        }
    }
    MouseArea {
        id: clicker
        anchors.fill: parent
    }
    states: State {
        name: "moved"
        when: clicker.pressed
        PropertyChanges {
            target: rect
            x: 200
        }
    }
}
