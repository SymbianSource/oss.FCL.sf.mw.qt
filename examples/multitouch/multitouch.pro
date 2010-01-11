TEMPLATE = subdirs
SUBDIRS = pinchzoom fingerpaint knobs dials

# install
target.path = $$[QT_INSTALL_EXAMPLES]/multitouch
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS multitouch.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/multitouch
INSTALLS += target sources
