
PACKAGE=bftools
VERSION=0.1
TARBALL=$(PACKAGE)-$(VERSION).tar.bz2
prefix=/usr/bin

MAKE=make
MKDIR=mkdir
CP=cp -f -R
TAR=tar cvjf

all:
	$(MAKE) -C src all

clean:
	$(MAKE) -C src clean
	$(RM) -r $(PACKAGE)-$(VERSION) $(TARBALL)

install:
	$(MAKE) -C src install prefix=$(prefix)

uninstall:
	$(MAKE) -C src uninstall prefix=$(prefix)

check:
	$(MAKE) -C src check

dist:
	$(MKDIR) $(PACKAGE)-$(VERSION)
	$(CP) src $(PACKAGE)-$(VERSION)
	$(CP) examples $(PACKAGE)-$(VERSION)
	$(CP) Makefile $(PACKAGE)-$(VERSION)
	$(TAR) $(TARBALL) $(PACKAGE)-$(VERSION)
	
