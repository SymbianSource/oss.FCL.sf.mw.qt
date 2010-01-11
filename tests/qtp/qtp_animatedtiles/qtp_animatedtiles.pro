SOURCES = main.cpp
RESOURCES = qtp_animatedtiles.qrc

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_animatedtiles
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS qtp_animatedtiles.pro images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_animatedtiles
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC03
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}
