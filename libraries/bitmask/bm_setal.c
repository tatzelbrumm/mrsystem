#include "bitmask.h"

void BitmaskSetAll(Bitmask *bmp)
{  unsigned int i;

   for (i = 0; i < bmp->size; i++)
      BitmaskSetBit(bmp, i);
}
