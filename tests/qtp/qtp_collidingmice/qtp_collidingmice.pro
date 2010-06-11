HEADERS += \
	autotest.h \
	mouse.h
SOURCES += \
	autotest.cpp \
	main.cpp \
        mouse.cpp

RESOURCES += \
	mice.qrc

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_PREFIX]/tests/qtp/collidingmice
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS collidingmice.pro images
sources.path = $$[QT_INSTALL_PREFIX]/tests/qtp/collidingmice
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC05
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}
