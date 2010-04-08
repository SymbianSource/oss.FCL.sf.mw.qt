TEMPLATE = subdirs
SUBDIRS = \
        uimodels\GraphicsViewBenchmark \
        corelib \
        gui \
        network \
        script \
        svg
contains(QT_CONFIG, opengl): SUBDIRS += opengl
