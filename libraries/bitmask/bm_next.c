#include "bitmask.h"

unsigned int BitmaskNext(const Bitmask *bmp, unsigned int i)
{  unsigned int n;

   for (n = i; n < bmp->size; n++)
      if (BitmaskIsBitSet(bmp, n))
         break;
   return n;
}
