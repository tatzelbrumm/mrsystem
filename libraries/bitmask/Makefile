INCLUDEPATH=/usr/local/include
LIBPATH=/usr/local/lib
OBJS=bm_creat.o bm_destr.o bm_setcl.o bm_setal.o bm_clral.o bm_isclr.o \
	bm_first.o bm_last.o bm_next.o bm_parse.o bm_disp.o
TARGET=libbitmask.a


all: $(TARGET)


$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	-@ ($(RANLIB) $@ || true) > /dev/null 2>/dev/null


bm_creat.o: bm_creat.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_destr.o: bm_destr.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_setcl.o: bm_setcl.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_setal.o: bm_setal.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_clral.o: bm_clral.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_isclr.o: bm_isclr.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_first.o: bm_first.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_last.o: bm_last.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_next.o: bm_next.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_parse.o: bm_parse.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

bm_disp.o: bm_disp.c bitmask.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


install:
	install -m 644 bitmask.h $(INCLUDEPATH)
	install -m 644 $(TARGET) $(LIBPATH)


clean:
	rm -f $(TARGET) *.o
