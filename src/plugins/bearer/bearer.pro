TEMPLATE = subdirs

contains(QT_CONFIG, dbus) {
    contains(QT_CONFIG, icd) {
        SUBDIRS += icd
    } else {
        SUBDIRS += generic
        !mac:SUBDIRS += connman networkmanager 
    }
}

#win32:SUBDIRS += nla
win32:SUBDIRS += generic
win32:!wince*:SUBDIRS += nativewifi
macx:contains(QT_CONFIG, corewlan):SUBDIRS += corewlan
macx:SUBDIRS += generic
symbian:SUBDIRS += symbian

isEmpty(SUBDIRS):SUBDIRS += generic
