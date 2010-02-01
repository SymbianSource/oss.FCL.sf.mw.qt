
HEADERS       = autotest.h \
                wigglywidget.h \
                dialog.h
SOURCES       = autotest.cpp \
                wigglywidget.cpp \
                dialog.cpp \
                main.cpp

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/wiggly
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS qtp_wiggly.pro
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/wiggly
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC0D
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}
