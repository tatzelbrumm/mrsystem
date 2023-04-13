INCLUDEPATH=/usr/local/include
LIBPATH=/usr/local/lib
ARFLAGS=rc
OBJS=ip_creat.o ip_destr.o ip_init.o ip_exit.o ip_read.o
TARGET=libinipars.a


all: $(TARGET)


$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	-@ ($(RANLIB) $@ || true) > /dev/null 2> /dev/null


ip_creat.o: ip_creat.c inipars.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


ip_destr.o: ip_destr.c inipars.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


ip_init.o: ip_init.c inipars.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


ip_exit.o: ip_exit.c inipars.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


ip_read.o: ip_read.c inipars.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


install:
	install -m 644 inipars.h $(INCLUDEPATH)
	install -m 644 $(TARGET) $(LIBPATH)


clean:
	rm -f $(TARGET) *.o
