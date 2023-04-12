#unused PROJECTS: client_ms1 gpios88
PROJECTS=client_cc client_cs2sl client_cs2eth client_cceth client_inject client_injectipc client_log client_logms2 client_logeth client_lok client_ms2 client_cc client_slcan client_srcp client_tty client_zentrale drehscheibe
DEBUG_PROJECTS=debug_client_zentrale
CFLAGS=-Wall
TRACE=1
INCLUDE_PATH=include
LIB_PATH=lib
LDFLAGS=
DESTDIR=/usr/local/bin

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: $(PROJECTS) libs common

all: $(PROJECTS) libs

debug: $(DEBUG_PROJECTS)

common: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_cs2sl: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_cs2eth: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_cceth: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_inject: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_injectipc: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_log: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_logeth: libs client_cs2sl
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_logms2: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_lok: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_ms1: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_ms2: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_cc: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_slcan: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_srcp: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_tty: libs common
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_gpios88: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

client_zentrale: libs
	make -C $@ CFLAGS="$(CFLAGS)" DIR=release INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

drehscheibe: libs
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) TRACE=$(TRACE)

debug_client_zentrale: libs
	make -C client_zentrale debug CFLAGS="$(CFLAGS)" LOCALFLAGS="-ggdb -DDEBUG" DIR=debug INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) DIR="debug" TRACE=$(TRACE)

.PHONY: doku

doku:
	make -C libs doku

libs:
	if [ ! -d include ] ; then mkdir include ; fi
	if [ ! -d lib ] ; then mkdir lib ; fi
	make -C $@ CFLAGS="$(CFLAGS)" INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

install: install_apps
	install -m 644 -o root -D etc/mrsystem /etc/mrsystem
	install -m 644 -o root -D etc/mrstart /etc/mrstart
	install -m 755 -D etc/init.d/mrsystem /etc/init.d/mrsystem
	install -m 755 -D /etc/mrupdate /var/www/mrupdate
	update-rc.d mrsystem defaults

install_apps:
	for PRJ in $(PROJECTS) ; do make -C $$PRJ install ; RET=$$? ; done ; return $$RET

install_web:
	install -m 644 -D www/ICE-Train.png /var/www/ICE-Train.png
	install -m 644 -D www/index.htm /var/www/index.htm
	install -m 644 -D www/mrsystem.css /var/www/mrsystem.css
	install -m 644 -D www/Doku/index.htm /var/www/Doku/index.htm
	install -m 644 -D www/config/gleisbilder/karben.cs2 /var/www/config/gleisbilder/karben.cs2
	install -m 644 -D www/config/fahrstrassen.cs2 /var/www/config/fahrstrassen.cs2
	install -m 644 -D www/config/gleisbild.cs2 /var/www/config/gleisbild.cs2
	install -m 644 -D www/config/lokomotive.cs2 /var/www/config/lokomotive.cs2
	install -m 644 -D www/config/magnetartikel.cs2 /var/www/config/magnetartikel.cs2
	install -m 644 -D www/icons/DHG300.png /var/www/icons/DHG300.png
	install -m 644 -D www/sysconf/linux.cfg /var/www/sysconf/linux.cfg
	install -m 644 -D www/sysconf/linux.def /var/www/sysconf/linux.def
	install -m 644 -D www/sysconf/linux.hlp /var/www/sysconf/linux.hlp
	install -m 644 -D www/sysconf/mrsystem.cfg /var/www/sysconf/mrsystem.cfg
	install -m 644 -D www/sysconf/mrsystem.def /var/www/sysconf/mrsystem.def
	install -m 644 -D www/sysconf/mrsystem.hlp /var/www/sysconf/mrsystem.hlp
	install -m 644 -D www/sysconf/uci.css /var/www/sysconf/uci.css
	install -m 644 -D www/sysconf/uci.php /var/www/sysconf/uci.php
	install -m 755 -D www/sysconf/valchanged.sh /var/www/sysconf/valchanged.sh
	install -m 644 -D doku/components.png /var/www/Doku/mrsystem/components.png
	find doku -name "*.htm" -exec install -m 644 -D "{}" /var/www/Doku/mrsystem ";"
	make -C libs install_web

clean_apps:
	for PRJ in $(PROJECTS) ; do echo $$PRJ ; make -C $$PRJ clean INCLUDE_PATH="../$(INCLUDE_PATH)" LIB_PATH="../$(LIB_PATH)" ; RET=$$? ; done ; return $$RET

clean_link:
	for PRJ in $(PROJECTS) ; do make -C $$PRJ clean_link INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH) ; RET=$$? ; done ; return $$RET

clean_doku:
	make -C libs clean_doku

clean: clean_apps
	make -C common clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C libs clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	rm -fr lib
	rm -fr include

uninstall:
	for PRJ in $(PROJECTS) ; do make -C $$PRJ uninstall ; RET=$$? ; done ; return $$RET
	rm /var/www/mrupdate
	rm /etc/init.d/mrsystem

test:
	make -C client_zentrale test INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
