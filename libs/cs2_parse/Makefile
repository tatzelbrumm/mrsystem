DOKUDIR=cs2_parse
DOKUPATH="../../doku/quellcode/$(DOKUDIR)"
DOKUWEBPATH="/var/www/Doku/mrsystem/quellcode/$(DOKUDIR)"
TARGET=libcs2_parse.a
OBJS=cs2p_create.o cs2p_destroy.o cs2p_init.o cs2p_parse.o write_cs2.o

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $<

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rvs $@ $+
	cp $@  $(LIB_PATH)
	cp cs2parse.h $(INCLUDE_PATH)
	cp write_cs2.h $(INCLUDE_PATH)
	cp cs2_types.h $(INCLUDE_PATH)

cs2p_create.o: cs2p_create.c cs2parse.h

cs2p_destroy.o: cs2p_destroy.c cs2parse.h

cs2p_init.o: cs2p_init.c cs2parse.h

cs2p_parse.o: cs2p_parse.c cs2parse.h

write_cs2.o: write_cs2.c write_cs2.h

doku:
	if [ ! -d $(DOKUPATH) ] ; then mkdir $(DOKUPATH) ; fi
	doxygen Doxyfile

install_web:
	if [ ! -d $(DOKUWEBPATH) ] ; then mkdir $(DOKUWEBPATH) ; fi
	if [ ! -d $(DOKUWEBPATH)/search ] ; then mkdir $(DOKUWEBPATH)/search ; fi
	find $(DOKUPATH) -type f -maxdepth 0 -exec install -m 644 -D "{}" $(DOKUWEBPATH) ";"
	find $(DOKUPATH)/search -type f -maxdepth 0 -exec install -m 644 -D "{}" $(DOKUWEBPATH)/search ";"

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f $(INCLUDE_PATH)/scanner.h
	rm -f $(INCLUDE_PATH)/parser.h
	rm -f $(INCLUDE_PATH)/write_cs2.h
	rm -f $(INCLUDE_PATH)/cs2_types.h
	rm -f $(LIB_PATH)/$(TARGET)

clean_doku:
	if [ -d $(DOKUPATH) ] ; then rm -r $(DOKUPATH) ; fi
