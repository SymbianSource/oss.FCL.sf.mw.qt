#
# Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies).
# All rights reserved.
#
# Description:  
#

# All paths used in this file end with the path delimiter '/'

include $(EPOCROOT)epoc32/tools/shell/$(notdir $(basename $(SHELL))).mk

COPY := $(call ecopy)

EPOC_ROOT := $(subst \,/,$(EPOCROOT))
QT_ROOT := $(subst group,,$(subst \,/,$(EXTENSION_ROOT)))
INSTALLPATH := epoc32/tools/qt/

# Determine which platform we are building on
ifeq ($(OSTYPE),unix)
CONF_PLATFORM := linux-g++-32
DOTEXE :=
else
CONF_PLATFORM := win32-g++-symbian
DOTEXE := .exe
endif

# This variable is needed to do the 'cd' on Windows
CONFIGURE_ROOT := $(subst group,,$(EXTENSION_ROOT))

TARGETDIR := $(EPOC_ROOT)$(INSTALLPATH)
SOURCEDIR := $(QT_ROOT)bin/
TARGET_TOOLS := $(TARGETDIR)qmake$(DOTEXE) $(TARGETDIR)moc$(DOTEXE) $(TARGETDIR)rcc$(DOTEXE) $(TARGETDIR)uic$(DOTEXE)
SOURCE_TOOLS := $(SOURCEDIR)qmake$(DOTEXE) $(SOURCEDIR)moc$(DOTEXE) $(SOURCEDIR)rcc$(DOTEXE) $(SOURCEDIR)uic$(DOTEXE)

XPLATFORM:=symbian-abld

$(TARGETDIR):
	$(call makepath,$(TARGETDIR))

$(SOURCEDIR)qmake$(DOTEXE): $(QT_ROOT)configure$(DOTEXE)
	echo Configuring Qt for build on $(CONF_PLATFORM) with $(XPLATFORM) as build setup
	cd $(CONFIGURE_ROOT) && $(QT_ROOT)configure$(DOTEXE) -platform $(CONF_PLATFORM) -xplatform $(XPLATFORM) $(OPTIONS)
	$(COPY) $(QT_ROOT).qmake.cache $(EPOC_ROOT)$(INSTALLPATH)qmake.cache
	$(COPY) $(EPOC_ROOT)epoc32/gcc_mingw/bin/mingwm10.dll $(EPOC_ROOT)$(INSTALLPATH)mingwm10.dll
	$(COPY) $(EPOC_ROOT)epoc32/gcc_mingw/bin/mingwm10.dll $(QT_ROOT)bin/mingwm10.dll
	
$(TARGET_TOOLS): $(SOURCE_TOOLS)
	$(COPY) $(SOURCEDIR)$(notdir $@) $@
	
do_nothing:
	
MAKMAKE : do_nothing

BLD : $(TARGETDIR) $(TARGET_TOOLS)

FINAL : do_nothing

CLEAN :
	perl $(EPOCROOT)epoc32/tools/ermdir.pl $(TARGETDIR)
	perl -e "foreach(split(/ /, \"$(SOURCE_TOOLS)\")) {unlink \"$$_\";}"

RELEASABLES :  do_nothing 

SAVESPACE : BLD

FREEZE : do_nothing

LIB : do_nothing

CLEANLIB : do_nothing

RESOURCE : do_nothing



