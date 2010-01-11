QT      +=  webkit network
HEADERS =   previewer.h \
            mainwindow.h
SOURCES =   main.cpp \
            previewer.cpp \
            mainwindow.cpp
FORMS   =   previewer.ui

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_previewer
sources.files = $$SOURCES $$HEADERS $$FORMS $$RESOURCES *.pro images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_previewer
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC08
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    INCLUDEPATH +=tmp $$QMAKE_INCDIR_QT/QtXmlPatterns
}
