load(qttest_p4)
QT = core gui script
SOURCES  += tst_qscriptvalue.cpp
HEADERS  += tst_qscriptvalue.h

# Generated by testgen
SOURCES  += \
    tst_qscriptvalue_generated_init.cpp \
    tst_qscriptvalue_generated_cast.cpp \
    tst_qscriptvalue_generated_comparison.cpp \
    tst_qscriptvalue_generated_isXXX.cpp \
    tst_qscriptvalue_generated_toXXX.cpp

win32-msvc* {
    # With -O2, MSVC takes up to 24 minutes to compile this test!
    QMAKE_CXXFLAGS_RELEASE -= -O1 -O2
    QMAKE_CXXFLAGS_RELEASE += -Od
}
