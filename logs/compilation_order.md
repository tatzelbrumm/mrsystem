# Compilation order

1. `cd libraries/boolean; sudo make install; make ..`
1. `cd libraries/compare; sudo make install; make ..`
1. `cd libraries/bitmask; make all; sudo make install; make ..`
1. `cd libraries/bytestream; make all; sudo make install; make ..`
1. `cd libraries/scanner; make all; sudo make install; make ..`
1. `cd libraries/datstor/avl; make all; sudo make install; make ../..`
1. `cd libraries/datstor/map; make all; sudo make install; make ../..`
1. `cd libraries/datstor/dliste; make all; sudo make install; make ../..`
1. `cd libraries/datstor/queue; make all; sudo make install; make ../..`
1. `cd libraries/datstor/menge; make all; sudo make install; make ../..`
1. `cd libraries/datstor/liste; make all; sudo make install; make ../..`
1. `cd libraries/datstor/stack; make all; sudo make install; make ../..`
1. `cd libraries/inipars; make all; sudo make install; make ..`
1. `cd libraries/fsm; make all; sudo make install; make ..`
1. `make all; sudo make install`
