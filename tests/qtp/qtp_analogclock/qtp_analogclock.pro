
HEADERS       = analogclock.h autotest.h
SOURCES       = analogclock.cpp \
                autotest.cpp \
                main.cpp

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/analogclock
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS analogclock.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/widgets/analogclock
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC02
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
    }
