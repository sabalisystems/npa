# --
# Copyright (c) 2012 by itopia.pl team.
# 
# src/knpa/Makefile
# Author: Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
# --

CXXFLAGS =
srcdir = .
top_srcdir = ../../../
DIST_SUBDIRS = $(SUBDIRS)

KNPA_SOURCES = knpa_mod.c
	
KNPA_HEADERS = log.h \
	errcode.h

KNPA_DISTFILES = $(KNPA_SOURCES) $(KNPA_HEADERS) Makefile

obj-m := knpa.o
knpa-objs := $(KNPA_SOURCES:%.c=%.o)

KERNEL_VER = $(shell uname -r)
KERNEL = /lib/modules/$(KERNEL_VER)/build

all:
	make $(CC) -C $(KERNEL) M=$(PWD) modules

clean:
	make $(CC) -C $(KERNEL) M=$(PWD) clean

distdir: $(KWARF_DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's|.|.|g'`; \
	list='$(KNPA_DISTFILES)'; for file in $$list; do \
	  case $$file in \
	    $(srcdir)/*) file=`echo "$$file" | sed "s|^$$srcdirstrip/||"`;; \
	    $(top_srcdir)/*) file=`echo "$$file" | sed "s|^$$topsrcdirstrip/|$(top_builddir)/|"`;; \
	  esac; \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  dir=`echo "$$file" | sed -e 's,/[^/]*$$,,'`; \
	  if test "$$dir" != "$$file" && test "$$dir" != "."; then \
	    dir="/$$dir"; \
	    mkdir "$(distdir)$$dir"; \
	  else \
	    dir=''; \
	  fi; \
	  if test -d $$d/$$file; then \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -pR $(srcdir)/$$file $(distdir)$$dir || exit 1; \
	    fi; \
	    cp -pR $$d/$$file $(distdir)$$dir || exit 1; \
	  else \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file \
	    || exit 1; \
	  fi; \
	done
	
.PHONY: all install clean distdir
