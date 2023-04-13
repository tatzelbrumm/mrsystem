#include "bitmask.h"

#define bitsperlong (8 * sizeof(unsigned long))

static unsigned int _getbit(const Bitmask *bmp, unsigned int n)
{
   if (n < bmp->size)
      return (bmp->maskp[n/bitsperlong] >> (n % bitsperlong)) & 1;
   else
      return 0;
}

BOOL BitmaskIsAllClear(const Bitmask *bmp)
{  unsigned int i;

   for (i = 0; i < bmp->size; i++)
      if (_getbit(bmp, i))
         return FALSE;
   return TRUE;
}

BOOL BitmaskIsBitSet(const Bitmask *bmp, unsigned int i)
{
   return(_getbit(bmp, i) == 1);
}
