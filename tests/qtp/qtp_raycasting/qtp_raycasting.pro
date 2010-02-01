
TEMPLATE = app
HEADERS       = autotest.h \
                raycasting.h 
SOURCES = autotest.cpp \
          raycasting.cpp \
          main.cpp
RESOURCES += qtp_raycasting.qrc

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

symbian {
    TARGET.UID3 = 0xED83EC0A
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}

target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_raycasting
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_raycasting
INSTALLS += target sources
