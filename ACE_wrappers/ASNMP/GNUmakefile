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

all: asnmp_lib asnmp_agent asnmp_example_get asnmp_example_get_async asnmp_example_next asnmp_example_set asnmp_example_trap asnmp_example_walk asnmp_tests_Address_Test asnmp_tests_Counter64_Test asnmp_tests_Counter_Test asnmp_tests_Gauge_Test asnmp_tests_Integer_Test asnmp_tests_Octet_Test asnmp_tests_Oid_Test asnmp_tests_Target_Test asnmp_tests_Varbind_Test

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@cd asnmp && $(MAKE) -f GNUmakefile.asnmp_lib $(@)
	$(KEEP_GOING)@cd agent && $(MAKE) -f GNUmakefile.asnmp_agent $(@)
	$(KEEP_GOING)@cd examples/get && $(MAKE) -f GNUmakefile.asnmp_example_get $(@)
	$(KEEP_GOING)@cd examples/get && $(MAKE) -f GNUmakefile.asnmp_example_get_async $(@)
	$(KEEP_GOING)@cd examples/next && $(MAKE) -f GNUmakefile.asnmp_example_next $(@)
	$(KEEP_GOING)@cd examples/set && $(MAKE) -f GNUmakefile.asnmp_example_set $(@)
	$(KEEP_GOING)@cd examples/trap && $(MAKE) -f GNUmakefile.asnmp_example_trap $(@)
	$(KEEP_GOING)@cd examples/walk && $(MAKE) -f GNUmakefile.asnmp_example_walk $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Address_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Counter64_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Counter_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Gauge_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Integer_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Octet_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Oid_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Target_Test $(@)
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Varbind_Test $(@)

.PHONY: asnmp_lib
asnmp_lib:
	$(KEEP_GOING)@cd asnmp && $(MAKE) -f GNUmakefile.asnmp_lib all

.PHONY: asnmp_agent
asnmp_agent: asnmp_lib
	$(KEEP_GOING)@cd agent && $(MAKE) -f GNUmakefile.asnmp_agent all

.PHONY: asnmp_example_get
asnmp_example_get: asnmp_lib
	$(KEEP_GOING)@cd examples/get && $(MAKE) -f GNUmakefile.asnmp_example_get all

.PHONY: asnmp_example_get_async
asnmp_example_get_async: asnmp_lib
	$(KEEP_GOING)@cd examples/get && $(MAKE) -f GNUmakefile.asnmp_example_get_async all

.PHONY: asnmp_example_next
asnmp_example_next: asnmp_lib
	$(KEEP_GOING)@cd examples/next && $(MAKE) -f GNUmakefile.asnmp_example_next all

.PHONY: asnmp_example_set
asnmp_example_set: asnmp_lib
	$(KEEP_GOING)@cd examples/set && $(MAKE) -f GNUmakefile.asnmp_example_set all

.PHONY: asnmp_example_trap
asnmp_example_trap: asnmp_lib
	$(KEEP_GOING)@cd examples/trap && $(MAKE) -f GNUmakefile.asnmp_example_trap all

.PHONY: asnmp_example_walk
asnmp_example_walk: asnmp_lib
	$(KEEP_GOING)@cd examples/walk && $(MAKE) -f GNUmakefile.asnmp_example_walk all

.PHONY: asnmp_tests_Address_Test
asnmp_tests_Address_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Address_Test all

.PHONY: asnmp_tests_Counter64_Test
asnmp_tests_Counter64_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Counter64_Test all

.PHONY: asnmp_tests_Counter_Test
asnmp_tests_Counter_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Counter_Test all

.PHONY: asnmp_tests_Gauge_Test
asnmp_tests_Gauge_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Gauge_Test all

.PHONY: asnmp_tests_Integer_Test
asnmp_tests_Integer_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Integer_Test all

.PHONY: asnmp_tests_Octet_Test
asnmp_tests_Octet_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Octet_Test all

.PHONY: asnmp_tests_Oid_Test
asnmp_tests_Oid_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Oid_Test all

.PHONY: asnmp_tests_Target_Test
asnmp_tests_Target_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Target_Test all

.PHONY: asnmp_tests_Varbind_Test
asnmp_tests_Varbind_Test: asnmp_lib
	$(KEEP_GOING)@cd tests && $(MAKE) -f GNUmakefile.asnmp_tests_Varbind_Test all

project_name_list:
	@echo asnmp_agent
	@echo asnmp_lib
	@echo asnmp_example_get
	@echo asnmp_example_get_async
	@echo asnmp_example_next
	@echo asnmp_example_set
	@echo asnmp_example_trap
	@echo asnmp_example_walk
	@echo asnmp_tests_Address_Test
	@echo asnmp_tests_Counter64_Test
	@echo asnmp_tests_Counter_Test
	@echo asnmp_tests_Gauge_Test
	@echo asnmp_tests_Integer_Test
	@echo asnmp_tests_Octet_Test
	@echo asnmp_tests_Oid_Test
	@echo asnmp_tests_Target_Test
	@echo asnmp_tests_Varbind_Test
