TEMPLATE = app
SOURCES = raycasting.cpp
RESOURCES += qtp_raycasting.qrc

symbian {
    TARGET.UID3 = 0xED83EC0A
    include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)
}

target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_raycasting
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/qtp_raycasting
INSTALLS += target sources
