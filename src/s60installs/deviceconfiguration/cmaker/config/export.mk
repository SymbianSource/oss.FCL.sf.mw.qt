#
# Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies). 
# All rights reserved.
# 
# Description: makefile_templates, actual build configuration export makefile
# 
 
MAKEFILE = /sf/mw/qt/src/s60installs/deviceconfiguration/cmaker/config/export.mk


$(call push,MAKEFILE_STACK,$(MAKEFILE))
 

TEMPLATEMAKEFILES =	/sf/mw/qt/src/s60installs/deviceconfiguration/qtconfig.meta /epoc32/tools/makefile_templates/qt/


template_makefiles :: template_makefiles_config
         

$(call addfiles, $(TEMPLATEMAKEFILES), template_makefiles_config) 


$(call popout,MAKEFILE_STACK)

