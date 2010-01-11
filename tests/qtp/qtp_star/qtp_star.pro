TEMPLATE = app
TARGET = qtp_star
CONFIG += qt debug warn_on
QT += openvg
SOURCES = starwidget.cpp main.cpp
HEADERS = starwidget.h
LIBS += $$QMAKE_LIBS_OPENVG

symbian {
    TARGET.UID3 = 0xED83EC0B
    include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)
}
