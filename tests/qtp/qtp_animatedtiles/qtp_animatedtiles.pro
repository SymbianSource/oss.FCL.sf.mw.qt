
SOURCES = main.cpp mainwindow.cpp autotest.cpp
HEADERS = mainwindow.h autotest.h

RESOURCES = qtp_animatedtiles.qrc

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_animatedtiles
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS qtp_animatedtiles.pro images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_animatedtiles
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC03
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}
