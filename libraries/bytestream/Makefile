INCLUDEPATH=/usr/local/include
LIBPATH=/usr/local/lib
OBJS=get_long.o get_int.o set_long.o set_int.o set_end.o
TARGET=libbytestream.a

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rvs $@ $+

get_long.o: get_long.c bytestream.h

get_int.o: get_int.c bytestream.h

set_long.o: get_long.c bytestream.h

set_int.o: get_int.c bytestream.h

set_end.o: set_end.c bytestream.h

install: $(TARGET)
	install -m 644 $(TARGET) $(LIBPATH)
	install -m 644 bytestream.h $(INCLUDEPATH)

clean:
	rm -f $(TARGET) $(OBJS)
