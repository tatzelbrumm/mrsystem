TARGET=/tmp/update.tar.gz

all: $(TARGET)

$(TARGET):
	./mkupd

test:
	cp diverses/test.sh /tmp/update.sh
	tar cf /tmp/update.tar /tmp/update.sh
	gzip /tmp/update.tar
	rm /tmp/update.sh

rocrail:
	cp diverses/rocrail.sh /tmp/update.sh
	tar cf /tmp/update.tar /tmp/update.sh
	gzip /tmp/update.tar
	rm /tmp/update.sh
	rm $(DESTDIR)/announce

clean:
	if [ -f $(TARGET) ] ; then rm -f $(TARGET) ; fi
