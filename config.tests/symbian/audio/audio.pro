TARGET = audio
SOURCES = audio.cpp

QT=

INCLUDEPATH += $${EPOCROOT}epoc32/include/mmf/server
INCLUDEPATH += $${EPOCROOT}epoc32/include/mmf/common

LIBS += -lmmfdevsound
