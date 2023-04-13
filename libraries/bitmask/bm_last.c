#include "bitmask.h"

unsigned int BitmaskLast(const Bitmask *bmp)
{  unsigned int i, m;

   m = bmp->size;
   for (i = 0; i < bmp->size; i++)
      if (BitmaskIsBitSet(bmp, i))
         m = i;
   return m;
}
