import Qt 4.7

XmlListModel {
    source: "model.xml"
    query: "/Pets/Pet"
    XmlRole { objectName: "role"; name: "name"; query: "name/string()" }
    XmlRole { name: "type"; query: "type/string()" }
    XmlRole { name: "age"; query: "age/number()" }
    XmlRole { name: "size"; query: "size/string()" }
}
