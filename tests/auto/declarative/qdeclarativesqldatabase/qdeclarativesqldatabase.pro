load(qttest_p4)
contains(QT_CONFIG,declarative): QT += declarative
QT += sql script
macx:CONFIG -= app_bundle

SOURCES += tst_qdeclarativesqldatabase.cpp

# Define SRCDIR equal to test's source directory
symbian: {
    DEFINES += SRCDIR=\".\"
    importFiles.sources = data
    importFiles.path = 
    DEPLOYMENT = importFiles
} else {
    DEFINES += SRCDIR=\\\"$$PWD\\\"
}

CONFIG += parallel_test

