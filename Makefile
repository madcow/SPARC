.POSIX:
.DELETE_ON_ERROR:
.SUFFIXES:

# Basic Makefile for development on Linux. This
# build setup will change before public release.
# TODO: Fix redundancies for unit test targets.
# TODO: Don't intermingle core headers with unit tests.
# TODO: Static file list instead of shell-find.
# TODO: Improve POSIX compatiblity?
# TODO: Support Windows and MinGW.

# ====================================================
# Settings
# ====================================================

CC       = gcc
LD       = $(CC)
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Werror
CPPFLAGS = -I$(SRCDIR) -I$(TESTDIR)
MDFLAGS  = -MM -MT $(@:.d=.o)
LDLIBS   =
LDFLAGS  =

VERBOSE := false
AUTORUN := true
SRCDIR  := src
BINDIR  := bin
TESTDIR := tests
TARGET  := bin/gas
CHECKS  := bin/gas-check
TMPDIR  := bin/build
TESTD   := test -d
MKDIR   := mkdir -p
RM      := rm -rf

# ====================================================
# Core files
# ====================================================

SOURCES := $(shell find $(SRCDIR) -name "*.c")
OBJECTS := $(SOURCES:%.c=$(TMPDIR)/%.o)
DEPENDS := $(SOURCES:%.c=$(TMPDIR)/%.d)

# ====================================================
# Unit tests
# ====================================================

LDTEST  := $(LDLIBS)
LDTEST  += $(shell pkg-config --cflags --libs check)
TESTS   := $(shell find $(TESTDIR) -name "*.c")
TESTS   += $(filter-out $(SRCDIR)/main.c, $(SOURCES))
TESTOBJ := $(TESTS:%.c=$(TMPDIR)/tests/%.o)
TESTDEP := $(TESTS:%.c=$(TMPDIR)/tests/%.d)

.PHONY: all
all: $(TARGET)

.PHONY: check
check: $(CHECKS)
	$(E) "[CK] $(CHECKS)"
	$(Q) ./$(CHECKS)

# ====================================================
# Final linker steps
# ====================================================

$(TARGET): $(OBJECTS) $(DEPENDS)
	$(E) "[LD] $@"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(LD) -o $@ $(LDFLAGS) $(OBJECTS) $(LDLIBS)

$(CHECKS): $(TESTOBJ) $(TESTDEP)
	$(E) "[LD] $@"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(LD) -o $@ $(LDFLAGS) $(TESTOBJ) $(LDTEST)

# ====================================================
# Compile core
# ====================================================

$(TMPDIR)/%.o: %.c
	$(E) "[CC] $<"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(TMPDIR)/%.d: %.c
	$(Q) $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) $(CPPFLAGS) $(MDFLAGS) $< -MF $@

# ====================================================
# Compile unit tests
# ====================================================

$(TMPDIR)/tests/%.o: %.c
	$(E) "[CC] $<"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(TMPDIR)/tests/%.d: %.c
	$(Q) $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) $(CPPFLAGS) $(MDFLAGS) $< -MF $@

.PHONY: clean
clean:
	$(E) "[RM] $(TARGET)"
	$(Q) $(RM) $(TARGET)
	$(E) "[RM] $(CHECKS)"
	$(Q) $(RM) $(CHECKS)
	$(E) "[RM] $(TMPDIR)"
	$(Q) $(RM) $(TMPDIR)

.PHONY: todo
todo:
	@echo "Comments marked TODO:"
	@grep -r --exclude-dir=".git" \
	         --exclude="Makefile" --exclude="*.swp" \
	         TODO | cut --complement -d':' -f2 | \
	         column -ts ":"

# The VERBOSE setting will supress
# all command output and replace it
# with pretty messages instead

ifneq ($(VERBOSE), false)
E = @true
else
E = @echo
Q = @
endif

# The AUTORUN setting will run the
# binary when the build is complete
# Used only for debugging purposes

ifneq ($(AUTORUN), false)
.DEFAULT_GOAL := check
endif

# Include header dependecies found
# with the preprocessor to ensure
# changes trigger recompilation

include $(wildcard $(DEPENDS))
include $(wildcard $(TESTDEP))
