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

all: TLI_SAP_ATM_Client TLI_SAP_ATM_Server TLI_SAP_CPP_Client TLI_SAP_CPP_Server TLI_SAP_Db_Client TLI_SAP_Db_Server TLI_SAP_Ftp_Client TLI_SAP_Ftp_Server

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_ATM_Client $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_ATM_Server $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_CPP_Client $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_CPP_Server $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Db_Client $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Db_Server $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Ftp_Client $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Ftp_Server $(@)

.PHONY: TLI_SAP_ATM_Client
TLI_SAP_ATM_Client:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_ATM_Client all

.PHONY: TLI_SAP_ATM_Server
TLI_SAP_ATM_Server:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_ATM_Server all

.PHONY: TLI_SAP_CPP_Client
TLI_SAP_CPP_Client:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_CPP_Client all

.PHONY: TLI_SAP_CPP_Server
TLI_SAP_CPP_Server:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_CPP_Server all

.PHONY: TLI_SAP_Db_Client
TLI_SAP_Db_Client:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Db_Client all

.PHONY: TLI_SAP_Db_Server
TLI_SAP_Db_Server:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Db_Server all

.PHONY: TLI_SAP_Ftp_Client
TLI_SAP_Ftp_Client:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Ftp_Client all

.PHONY: TLI_SAP_Ftp_Server
TLI_SAP_Ftp_Server:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.TLI_SAP_Ftp_Server all

project_name_list:
	@echo TLI_SAP_ATM_Client
	@echo TLI_SAP_ATM_Server
	@echo TLI_SAP_CPP_Client
	@echo TLI_SAP_CPP_Server
	@echo TLI_SAP_Db_Client
	@echo TLI_SAP_Db_Server
	@echo TLI_SAP_Ftp_Client
	@echo TLI_SAP_Ftp_Server
