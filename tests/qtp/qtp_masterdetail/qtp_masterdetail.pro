HEADERS   = database.h \
            dialog.h \
            mainwindow.h
RESOURCES = qtp_masterdetail.qrc
SOURCES   = dialog.cpp \
            main.cpp \
            mainwindow.cpp

QT += sql
QT += xml

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_masterdetail
sources.files = $$SOURCES *.h $$RESOURCES $$FORMS qtp_masterdetail.pro *.xml images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_masterdetail
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC07
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}

