QT += network \
    webkit
HEADERS += \
    src/autotest.h \
    src/httpserver.h \
    src/BrowserWindow.h \
    src/BrowserView.h \
    src/TitleBar.h \
    src/HomeView.h \
    src/AddressBar.h \
    src/BookmarksView.h \
    src/flickcharm.h \
    src/ZoomStrip.h \
    src/ControlStrip.h
SOURCES += \
    src/autotest.cpp \
    src/httpserver.cpp \
    src/Main.cpp \
    src/BrowserWindow.cpp \
    src/BrowserView.cpp \
    src/TitleBar.cpp \
    src/HomeView.cpp \
    src/AddressBar.cpp \
    src/BookmarksView.cpp \
    src/flickcharm.cpp \
    src/ZoomStrip.cpp \
    src/ControlStrip.cpp
RESOURCES += src/anomaly.qrc

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

symbian {
    TARGET.UID3 = 0xED83EC04
    include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)
    HEADERS += $$QT_SOURCE_TREE/examples/network/qftp/sym_iap_util.h
    LIBS += -lesock -linsock -lconnmon
    TARGET.CAPABILITY = NetworkServices
    TARGET.EPOCHEAPSIZE = 0x20000 0x2000000
}

target.path = $$[QT_INSTALL_DEMOS]/embedded/qtp_anomaly
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro src/images
sources.path = $$[QT_INSTALL_DEMOS]/embedded/qtp_anomaly
INSTALLS += target sources
