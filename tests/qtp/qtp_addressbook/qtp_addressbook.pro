
SOURCES   = adddialog.cpp \
            addresswidget.cpp \
            main.cpp \
            autotest.cpp \
            mainwindow.cpp \
            newaddresstab.cpp \
            tablemodel.cpp
HEADERS   = adddialog.h \
            addresswidget.h \
            autotest.h \
            mainwindow.h \
            newaddresstab.h \
            tablemodel.h

CONFIG += qt warn_on console depend_includepath

qtAddLibrary(QtTest)

# install
target.path = $$[QT_INSTALL_EXAMPLES]/itemviews/addressbook
sources.files = $$SOURCES $$HEADERS $$RESOURCES addressbook.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/itemviews/addressbook
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xED83EC01
    TARGET.CAPABILITY="ALL -TCB"
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    RSS_RULES ="group_name=\"QtTests\";" 
}
