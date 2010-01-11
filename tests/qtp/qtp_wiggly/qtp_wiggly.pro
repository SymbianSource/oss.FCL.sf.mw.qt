HEADERS       = wigglywidget.h \
                dialog.h
SOURCES       = wigglywidget.cpp \
                dialog.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/wiggly
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS qtp_wiggly.pro
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/wiggly
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC0D
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}
