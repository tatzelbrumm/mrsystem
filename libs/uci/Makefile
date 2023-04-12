DOKUDIR=uci
DOKUPATH="../../doku/quellcode/$(DOKUDIR)"
DOKUWEBPATH="/var/www/Doku/mrsystem/quellcode/$(DOKUDIR)"
TARGET=libuci.a
OBJS=uci_op_uci_wr.o uci_wr_uci_hdr.o uci_wr_uci_tab.o \
	uci_op_hlp_wr.o uci_wr_hlp.o \
	uci_op_cfg_wr.o uci_wr_cfg_int.o uci_wr_cfg_str.o \
	uci_op_def_wr.o uci_wr_def_hdr.o uci_wr_def_txt.o uci_wr_def_str.o \
	uci_wr_def_ip.o uci_wr_def_cb.o uci_wr_def_sel.o uci_wr_def_rb.o \
	uci_wr_def_bits.o uci_wr_def_int.o \
	uci_open_wr.o uci_wr_txt.o uci_wr_int.o

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $<

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rvs $@ $+
	cp $@  $(LIB_PATH)
	cp uci.h $(INCLUDE_PATH)

uci_op_uci_wr.o: uci_op_uci_wr.c uci.h

uci_wr_uci_hdr.o: uci_wr_uci_hdr.c uci.h

uci_wr_uci_tab.o: uci_wr_uci_tab.c uci.h

uci_op_hlp_wr.o: uci_op_hlp_wr.c uci.h

uci_wr_hlp.o: uci_wr_hlp.c uci.h

uci_op_cfg_wr.o: uci_op_cfg_wr.c uci.h

uci_wr_cfg_int.o: uci_wr_cfg_int.c uci.h

uci_wr_cfg_str.o: uci_wr_cfg_str.c uci.h

uci_op_def_wr.o: uci_op_def_wr.c uci.h

uci_wr_def_hdr.o: uci_wr_def_hdr.c uci.h

uci_wr_def_txt.o: uci_wr_def_txt.c uci.h

uci_wr_def_str.o: uci_wr_def_str.c uci.h

uci_wr_def_int.o: uci_wr_def_int.c uci.h

uci_wr_def_ip.o: uci_wr_def_ip.c uci.h

uci_wr_def_cb.o: uci_wr_def_cb.c uci.h

uci_wr_def_sel.o: uci_wr_def_sel.c uci.h

uci_wr_def_rb.o: uci_wr_def_rb.c uci.h

uci_wr_def_bits.o: uci_wr_def_bits.c uci.h

uci_open_wr.o: uci_open_wr.c uci.h

uci_wr_txt.o: uci_wr_txt.c uci.h

uci_wr_int.o: uci_wr_int.c uci.h

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
	rm -f $(INCLUDE_PATH)/uci.h
	rm -f $(LIB_PATH)/$(TARGET)

clean_doku:
	if [ -d $(DOKUPATH) ] ; then rm -r $(DOKUPATH) ; fi
