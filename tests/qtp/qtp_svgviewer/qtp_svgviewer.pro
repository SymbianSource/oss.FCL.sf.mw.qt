
HEADERS       = autotest.h \
                mainwindow.h \
                svgview.h
RESOURCES     = qtp_svgviewer.qrc
SOURCES       = autotest.cpp \
                main.cpp \
                mainwindow.cpp \
                svgview.cpp
QT           += svg xml

contains(QT_CONFIG, opengl): QT += opengl

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_svgviewer
sources.files = $$SOURCES $$HEADERS $$RESOURCES qtp_svgviewer.pro files
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_svgviewer
INSTALLS += target sources

wince*: {
    addFiles.sources = files\*.svg
    addFiles.path = \My Documents
    DEPLOYMENT += addFiles
}

symbian: {
    TARGET.UID3 = 0xED83EC0C
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    addFiles.sources = files\*.svg
    addFiles.path = .
    DEPLOYMENT += addFiles
    RSS_RULES ="group_name=\"QtTests\";" 
}
