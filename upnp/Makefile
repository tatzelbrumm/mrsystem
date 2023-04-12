TARGET=tools/announce
PATCH=phpdlna.patch
DESTDIR=/usr/sbin

all: $(TARGET)

$(TARGET): $(PATCH)
	if [ ! -d ../Archive ] ; then mkdir ../Archive ; fi
	if [ ! -f ../Archive/phpdlna-master.zip ] ; then wget -P ../Archive https://github.com/ttyridal/phpdlna/archive/master.zip ; fi
	if [ ! -f ../Archive/phpdlna-master.zip ] ; then mv ../Archive/master.zip ../Archive/phpdlna-master.zip ; fi
	if [ ! -d tools ] ; then mkdir tools ; fi
	rm -f tools/announce.cpp
	rm -f tools/config.h
	unzip -d tools -j ../Archive/phpdlna-master.zip phpdlna-master/tools/announce.cpp
	patch --strip=1 < phpdlna.patch
	g++ -o $(TARGET) tools/announce.cpp

install: $(TARGET)
	install $(TARGET) $(DESTDIR)/announce
	install etc/init.d/phpdlna /etc/init.d
	install etc/default/phpdlna /etc/default
	update-rc.d phpdlna defaults
	install -D -m 644 rootDesc.xml /var/www/phpdlna/rootDesc.xml
	install -m 644 dhcp/phpdlna /etc/dhcp/dhclient-exit-hooks.d

uninstall:
	rm $(DESTDIR)/announce

clean:
	rm -f $(TARGET)

clean_link:
	rm -f $(TARGET)

distclean:
	rm -f $(TARGET)
