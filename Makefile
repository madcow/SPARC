.POSIX:
.DELETE_ON_ERROR:
.SUFFIXES:

# Basic Makefile for development on Linux. This
# build setup will change before public release.
# TODO: Support Windows and MinGW.

CC       := gcc
LD       := $(CC)
CFLAGS   := -ansi -pedantic -Wall -Wextra -Werror
MDFLAGS   = -MM -MT $(@:.d=.o)
CPPFLAGS  = -I$(SRCDIR)
LDFLAGS  :=
LDLIBS   :=

VERBOSE  := false
AUTORUN  := true
SRCDIR   := src
BINDIR   := bin
TARGET   := bin/gas
TMPDIR   := bin/build
TESTD    := test -d
MKDIR    := mkdir -p
RM       := rm -rf

SOURCES  := $(shell find $(SRCDIR) -name "*.c")
OBJECTS  := $(SOURCES:%.c=$(TMPDIR)/%.o)
DEPENDS  := $(SOURCES:%.c=$(TMPDIR)/%.d)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS) $(DEPENDS)
	$(E) "[LD] $@"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(LD) -o $@ $(LDFLAGS) $(OBJECTS) $(LDLIBS)

$(TMPDIR)/%.o: %.c
	$(E) "[CC] $<"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(TMPDIR)/%.d: %.c
	$(Q) $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) $(CPPFLAGS) $(MDFLAGS) $< -MF $@

.PHONY: clean
clean:
	$(E) "[RM] $(TARGET)"
	$(Q) $(RM) $(TARGET)
	$(E) "[RM] $(TMPDIR)"
	$(Q) $(RM) $(TMPDIR)

.PHONY: check
check: $(TARGET)
	$(E) "[CK] $<"
	$(Q) ./$<

.PHONY: todo
todo:
	@echo "Comments marked TODO:"
	@grep -r --exclude-dir=".git" \
	         --exclude="Makefile" --exclude="*.swp" \
	         TODO | cut --complement -d':' -f2

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
