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

all: Malloc Mem_Map PI_Malloc Pool_Growth Shared_Memory_Hash_Map

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Malloc $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Mem_Map $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.PI_Malloc $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Pool_Growth $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Memory_Hash_Map $(@)

.PHONY: Malloc
Malloc:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Malloc all

.PHONY: Mem_Map
Mem_Map:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Mem_Map all

.PHONY: PI_Malloc
PI_Malloc:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.PI_Malloc all

.PHONY: Pool_Growth
Pool_Growth:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Pool_Growth all

.PHONY: Shared_Memory_Hash_Map
Shared_Memory_Hash_Map:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Shared_Memory_Hash_Map all

project_name_list:
	@echo Malloc
	@echo Mem_Map
	@echo PI_Malloc
	@echo Pool_Growth
	@echo Shared_Memory_Hash_Map
