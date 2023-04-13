#ifndef BITMASK_H
#define BITMASK_H

#include <boolean.h>

#define BIT_MASK(first,last)                (((unsigned)-1>>(31-(last)))&~((1U<<(first))-1))
#define BIT_MASK_SET(var,mask)              ((var)|=((mask)))
#define BIT_MASK_CLEAR(var,mask)            ((var)&=(unsigned)~((mask)))
#define BIT_MASK_TOGGLE(var,mask)           ((var)^=((mask)))
#define BIT_MASK_SHIFT_SET(var,mask,bit)    ((var)|=((mask)<<(bit)))
#define BIT_MASK_SHIFT_CLEAR(var,mask,bit)  ((var)&=(unsigned)~((mask)<<(bit)))
#define BIT_MASK_SHIFT_TOGGLE(var,mask,bit) ((var)^=((mask)<<(bit)))
#define BIT_SET(var,bit)                    ((var)|=(1u<<(bit)))
#define BIT_CLEAR(var,bit)                  ((var)&=(unsigned)~(1u<<(bit)))
#define BIT_TOGGLE(var,bit)                 ((var)^=(1u<<(bit)))
#define BIT_ASSIGN(var,bit)                 ((var)=(1u<<(bit)))
#define BIT_IS_SET(var,bit)                 ((var)&(1u<<(bit)))

#define MASK_LOW_NIBBLE  0x0f
#define MASK_HIGH_NIBBLE 0xf0
#define MASK_LOW_BYTE  0x00ff
#define MASK_HIGH_BYTE 0xff00
#define MASK_LOW_WORD  0x0000ffff
#define MASK_HIGH_WORD 0xffff0000
#define MASK_LOW_BYTE_OF_HIGH_WORD  0x00ff0000
#define MASK_HIGH_BYTE_OF_HIGH_WORD 0xff000000

#define SHIFT_0_BYTE  0
#define SHIFT_1_BYTE  8
#define SHIFT_2_BYTE 16
#define SHIFT_3_BYTE 24
#define SHIFT_4_BYTE 32

typedef struct {
   unsigned int size;
   unsigned long *maskp;
} Bitmask;

Bitmask *BitmaskCreate(unsigned int bits);
void BitmaskDestroy(Bitmask *bmp);
void BitmaskSetBit(Bitmask *bmp, unsigned int i);
void BitmaskClearBit(Bitmask *bmp, unsigned int i);
void BitmaskSetAll(Bitmask *bmp);
void BitmaskClearAll(Bitmask *bmp);
BOOL BitmaskIsAllClear(const Bitmask *bmp);
BOOL BitmaskIsBitSet(const Bitmask *bmp, unsigned int i);
unsigned int BitmaskFirst(const Bitmask *bmp);
unsigned int BitmaskLast(const Bitmask *bmp);
unsigned int BitmaskNext(const Bitmask *bmp, unsigned int i);
int BitmaskParseList(const char *buf, Bitmask *bmp);
int BitmaskDisplayList(char *buf, int buflen, const Bitmask *bmp);

#endif
