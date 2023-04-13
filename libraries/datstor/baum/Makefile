INCLUDEPATH=/usr/local/include
LIBPATH=/usr/local/lib
ARFLAGS=rc
OBJS=baum_cre.o baum_del.o baum_des.o baum_fin.o baum_ini.o baum_ins.o baum_win.o baum_wpo.o baum_wpr.o
TARGET=libbaum.a


all: $(TARGET)


$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	-@ ($(RANLIB) $@ || true) > /dev/null 2>/dev/null


baum_cre.o: baum_cre.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_del.o: baum_del.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_des.o: baum_des.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_fin.o: baum_fin.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_ini.o: baum_ini.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_ins.o: baum_ins.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_win.o: baum_win.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_wpo.o: baum_wpo.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


baum_wpr.o: baum_wpr.c baum.h
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<


install:
	install -m 664 baum.h $(INCLUDEPATH)
	install -m 644 $(TARGET) $(LIBPATH)


clean:
	rm -f $(TARGET) *.o
