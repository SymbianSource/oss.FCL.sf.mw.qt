HEADERS += \
	mouse.h
SOURCES += \
	main.cpp \
        mouse.cpp

RESOURCES += \
	mice.qrc

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/collidingmice
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS collidingmice.pro images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/collidingmice
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC05
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}
