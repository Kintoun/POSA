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

all: Misc_Test_Dump Misc_Test_Get_Opt Misc_Test_Profile_Timer Misc_Test_Read_Buffer Misc_Test_Set Misc_Test_Sstring Misc_Test_Timestamp Misc_Test_Trace

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Dump $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Get_Opt $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Profile_Timer $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Read_Buffer $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Set $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Sstring $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Timestamp $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Trace $(@)

.PHONY: Misc_Test_Dump
Misc_Test_Dump:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Dump all

.PHONY: Misc_Test_Get_Opt
Misc_Test_Get_Opt:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Get_Opt all

.PHONY: Misc_Test_Profile_Timer
Misc_Test_Profile_Timer:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Profile_Timer all

.PHONY: Misc_Test_Read_Buffer
Misc_Test_Read_Buffer:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Read_Buffer all

.PHONY: Misc_Test_Set
Misc_Test_Set:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Set all

.PHONY: Misc_Test_Sstring
Misc_Test_Sstring:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Sstring all

.PHONY: Misc_Test_Timestamp
Misc_Test_Timestamp:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Timestamp all

.PHONY: Misc_Test_Trace
Misc_Test_Trace:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Misc_Test_Trace all

project_name_list:
	@echo Misc_Test_Dump
	@echo Misc_Test_Get_Opt
	@echo Misc_Test_Profile_Timer
	@echo Misc_Test_Read_Buffer
	@echo Misc_Test_Set
	@echo Misc_Test_Sstring
	@echo Misc_Test_Timestamp
	@echo Misc_Test_Trace
