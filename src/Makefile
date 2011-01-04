

prefix=/usr/bin
PREFIX=$(prefix)

INSTALL=install
LN=ln -s -f
CFLAGS=-O0 -DNDEBUG -g
CXXFLAGS=$(CFLAGS)

all: bf str2bf bfstrip sbfi bfprof

bf: bf.c

sbfi: sbfi.c

bf2c: bf2c.c

bfstrip: bfstrip.c

bfprof: bfprof.c

str2bf: str2bf.cpp

check: bf str2bf
	echo `./str2bf THROW THE DAMN BALL`'[-]' | ./bf ; echo
	./bf ../examples/yapi.bf
	./bf ../examples/wc.bf bf.c

install: all
	$(INSTALL) bf $(PREFIX)
	$(INSTALL) sbfi $(PREFIX)
	$(LN) $(PREFIX)/bf $(PREFIX)/bf8
	$(LN) $(PREFIX)/bf $(PREFIX)/bf2c
#	$(INSTALL) bf2c $(PREFIX)
	$(INSTALL) str2bf $(PREFIX)
	$(INSTALL) bfprof $(PREFIX)
	$(INSTALL) bfstrip $(PREFIX)
	$(INSTALL) bfcl $(PREFIX)
#	$(INSTALL) ../examples/bfcl.bf $(PREFIX)/bfcl

uninstall:
	$(RM) $(PREFIX)/bf
	$(RM) $(PREFIX)/sbfi
	$(RM) $(PREFIX)/bf8
	$(RM) $(PREFIX)/bf2c
	$(RM) $(PREFIX)/str2bf
	$(RM) $(PREFIX)/bfprof
	
clean:
	$(RM) *.o bf bf2c str2bf bfstrip *~
