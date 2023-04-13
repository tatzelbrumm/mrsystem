#include "bitmask.h"

void BitmaskClearAll(Bitmask *bmp)
{  unsigned int i;

   for (i = 0; i < bmp->size; i++)
      BitmaskClearBit(bmp, i);
}
