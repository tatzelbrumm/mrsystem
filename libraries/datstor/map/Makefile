INCLUDEPATH=/usr/local/include
LIBPATH=/usr/local/lib
ARFLAGS=rc
OBJS=map_crea.o map_del.o map_dest.o map_get.o map_init.o map_purg.o map_set.o map_walk.o
TARGET=libmap.a


all: $(TARGET)


$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	-@ ($(RANLIB) $@ || true) > /dev/null 2> /dev/null


map_crea.o: map_crea.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_del.o: map_del.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_dest.o: map_dest.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_get.o: map_get.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_init.o: map_init.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_purg.o: map_purg.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_set.o: map_set.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


map_walk.o: map_walk.c map.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


install:
	install -m 644 map.h $(INCLUDEPATH)
	install -m 644 $(TARGET) $(LIBPATH)


clean:
	rm -f $(TARGET) *.o
