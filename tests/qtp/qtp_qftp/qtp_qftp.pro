HEADERS = autotest.h \
    ftpwindow.h \
    ftpserver.h
SOURCES = autotest.cpp \
    ftpwindow.cpp \
    main.cpp \
    ftpserver.cpp

RESOURCES += qtp_ftp.qrc
QT += network
CONFIG += qt \
    warn_on \
    console \
    depend_includepath
qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_qftp
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    *.pro \
    images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_qftp
INSTALLS += target \
    sources
symbian { 
    TARGET.UID3 = 0xED83EC09
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    HEADERS += sym_iap_util.h
    INCLUDEPATH += $$APP_LAYER_SYSTEMINCLUDE
    TARGET.CAPABILITY = "NetworkServices ReadUserData WriteUserData"
    LIBS += -lesock \
        -lcommdb \
        -linsock # For IAP selection
}
