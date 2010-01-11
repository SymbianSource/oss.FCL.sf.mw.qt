HEADERS       = ftpwindow.h
SOURCES       = ftpwindow.cpp \
                main.cpp
RESOURCES    += qtp_ftp.qrc
QT           += network

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_qftp
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_qftp
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC09
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    HEADERS +=  sym_iap_util.h
    INCLUDEPATH += $$APP_LAYER_SYSTEMINCLUDE
    TARGET.CAPABILITY="NetworkServices ReadUserData WriteUserData"
    LIBS+=-lesock -lcommdb -linsock # For IAP selection
}
