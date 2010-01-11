#
# Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
# All rights reserved.
# This component and the accompanying materials are made available
# under the terms of the License "Symbian Foundation License v1.0"
# which accompanies this distribution, and is available
# at the URL "http://www.symbianfoundation.org/legal/sfl-v10.html".
#
# Initial Contributors:
# Nokia Corporation - initial contribution.
#
# Contributors:
# 
# Description: makefile_templates, actual build configuration export makefile
# 
 
MAKEFILE = /sf/mw/qt/group/cmaker/config/export.mk


$(call push,MAKEFILE_STACK,$(MAKEFILE))
 

TEMPLATEMAKEFILES =	/sf/mw/qt/group/qtconfig.meta /epoc32/tools/makefile_templates/qt/


template_makefiles :: template_makefiles_config
         

$(call addfiles, $(TEMPLATEMAKEFILES), template_makefiles_config) 


$(call popout,MAKEFILE_STACK)

