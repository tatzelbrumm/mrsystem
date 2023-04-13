#include "bitmask.h"

#define bitsperlong (8 * sizeof(unsigned long))

static void _setbit(Bitmask *bmp, unsigned int n, unsigned int v)
{
   if (n < bmp->size)
   {
      if (v)
         bmp->maskp[n/bitsperlong] |= 1UL << (n % bitsperlong);
      else
         bmp->maskp[n/bitsperlong] &= ~(1UL << (n % bitsperlong));
   }
}

void BitmaskSetBit(Bitmask *bmp, unsigned int i)
{
   _setbit(bmp, i, 1);
}

void BitmaskClearBit(Bitmask *bmp, unsigned int i)
{
   _setbit(bmp, i, 0);
}
