# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# $Id: GNUACEWorkspaceCreator.pm 94635 2011-10-06 12:59:23Z johnnyw $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/build/tmp/stage-1107/ACE_wrappers/bin/mwc.pl -type gnuace -exclude "TAO/TAO_*.mwc,TAO/CIAO/CIAO_*.mwc" -workers 12 -recurse -hierarchy -relative ACE_ROOT=/home/build/tmp/stage-1107/ACE_wrappers -relative TAO_ROOT=/home/build/tmp/stage-1107/ACE_wrappers/TAO -relative CIAO_ROOT=/home/build/tmp/stage-1107/ACE_wrappers/TAO/CIAO -relative DANCE_ROOT=/home/build/tmp/stage-1107/ACE_wrappers/TAO/DAnCE
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: Naming_Multiple_Contexts Naming_Non_Existent Naming_Open Naming_Writers

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Multiple_Contexts $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Non_Existent $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Open $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Writers $(@)

.PHONY: Naming_Multiple_Contexts
Naming_Multiple_Contexts:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Multiple_Contexts all

.PHONY: Naming_Non_Existent
Naming_Non_Existent:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Non_Existent all

.PHONY: Naming_Open
Naming_Open:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Open all

.PHONY: Naming_Writers
Naming_Writers:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Naming_Writers all

project_name_list:
	@echo Naming_Multiple_Contexts
	@echo Naming_Non_Existent
	@echo Naming_Open
	@echo Naming_Writers
