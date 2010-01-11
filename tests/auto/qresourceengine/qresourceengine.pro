######################################################################
# Automatically generated by qmake (2.00a) ma 2. mai 16:14:33 2005
######################################################################

load(qttest_p4)
load(resources)

# Input
SOURCES += tst_qresourceengine.cpp
RESOURCES += testqrc/test.qrc

symbian-sbsv2 {
    runtime_resource.target = $$PWD/runtime_resource.rcc
} else {
    runtime_resource.target = runtime_resource.rcc
}
runtime_resource.depends = $$PWD/testqrc/test.qrc
runtime_resource.commands = $$QMAKE_RCC -root /runtime_resource/ -binary $${runtime_resource.depends} -o $${runtime_resource.target}
QMAKE_EXTRA_TARGETS = runtime_resource
PRE_TARGETDEPS += $${runtime_resource.target}

QT = core
wince*|symbian*:{
    deploy.sources += runtime_resource.rcc parentdir.txt
    test.sources = testqrc/*
    test.path = testqrc
    alias.sources = testqrc/aliasdir/*
    alias.path = testqrc/aliasdir
    other.sources = testqrc/otherdir/*
    other.path = testqrc/otherdir
    search1.sources = testqrc/searchpath1/*
    search1.path = testqrc/searchpath1
    search2.sources = testqrc/searchpath2/*
    search2.path = testqrc/searchpath2
    sub.sources = testqrc/subdir/*
    sub.path = testqrc/subdir
    testsub.sources = testqrc/test/*
    testsub.path = testqrc/test
    testsub2.sources = testqrc/test/test/*
    testsub2.path = testqrc/test/test
    DEPLOYMENT = deploy test alias other search1 search2 sub testsub testsub2
    !symbian:DEFINES += SRCDIR=\\\"\\\"
} else {
   DEFINES += SRCDIR=\\\"$$PWD/\\\"
}
