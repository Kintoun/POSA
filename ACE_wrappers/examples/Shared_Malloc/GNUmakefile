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

all: Shared_Malloc Shared_Malloc_Multiple Shared_Malloc_Persistence Shared_Malloc_Posind

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc_Multiple $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc_Persistence $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc_Posind $(@)

.PHONY: Shared_Malloc
Shared_Malloc:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc all

.PHONY: Shared_Malloc_Multiple
Shared_Malloc_Multiple: Shared_Malloc
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc_Multiple all

.PHONY: Shared_Malloc_Persistence
Shared_Malloc_Persistence:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc_Persistence all

.PHONY: Shared_Malloc_Posind
Shared_Malloc_Posind: Shared_Malloc
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Malloc_Posind all

project_name_list:
	@echo Shared_Malloc
	@echo Shared_Malloc_Multiple
	@echo Shared_Malloc_Persistence
	@echo Shared_Malloc_Posind
