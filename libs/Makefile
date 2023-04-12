LIBS=cs2_parse mr_ipc mr_ipchl mr_cs2ms2 config io_fkts uci cs2 srcp


.PHONY: $(LIBS)

all: $(LIBS)

cs2_parse:
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

mr_ipc: mr_cs2ms2 cs2
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

mr_ipchl: mr_ipc
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

mr_cs2ms2: cs2
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

config:
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

io_fkts:
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

uci:
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

cs2:
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

srcp:
	make -C $@  CFLAGS="$(CFLAGS)"  INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

doku:
	make -C config doku
	make -C cs2 doku
	make -C cs2_parse doku
	make -C io_fkts doku
	make -C mr_cs2ms2 doku
	make -C mr_ipc doku
	make -C mr_ipchl doku
	make -C srcp doku
	make -C uci doku

install_web:
	make -C config install_web
	make -C cs2 install_web
	make -C cs2_parse install_web
	make -C io_fkts install_web
	make -C mr_cs2ms2 install_web
	make -C mr_ipc install_web
	make -C mr_ipchl install_web
	make -C srcp install_web
	make -C uci install_web

clean:
	make -C cs2_parse clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C mr_ipc clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C mr_ipchl clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C mr_cs2ms2 clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C config clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C uci clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C cs2 clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
	make -C srcp clean INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)

clean_doku:
	make -C config clean_doku
	make -C cs2 clean_doku
	make -C cs2_parse clean_doku
	make -C io_fkts clean_doku
	make -C mr_cs2ms2 clean_doku
	make -C mr_ipc clean_doku
	make -C mr_ipchl clean_doku
	make -C srcp clean_doku
	make -C uci clean_doku

test:
	make -C cs2 test INCLUDE_PATH=../$(INCLUDE_PATH) LIB_PATH=../$(LIB_PATH)
