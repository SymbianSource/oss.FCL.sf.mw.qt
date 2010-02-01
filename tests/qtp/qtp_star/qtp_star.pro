TEMPLATE = app
TARGET = qtp_star
CONFIG += qt debug warn_on qtestlib console depend_includepath
QT += openvg
SOURCES = starwidget.cpp startest.cpp main.cpp
HEADERS = starwidget.h startest.h
LIBS += $$QMAKE_LIBS_OPENVG

qtAddLibrary(QtTest)

symbian {
    TARGET.UID3 = 0xED83EC0B
    TARGET.CAPABILITY="ALL -TCB"
    // TARGET.CAPABILITY="TCB"
    include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}
