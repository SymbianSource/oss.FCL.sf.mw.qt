
HEADERS   = autotest.h \
            database.h \
            dialog.h \
            mainwindow.h
RESOURCES = qtp_masterdetail.qrc
SOURCES   = autotest.cpp \
            dialog.cpp \
            main.cpp \
            mainwindow.cpp

QT += sql
QT += xml

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_masterdetail
sources.files = $$SOURCES *.h $$RESOURCES $$FORMS qtp_masterdetail.pro *.xml images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_masterdetail
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC07
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}
