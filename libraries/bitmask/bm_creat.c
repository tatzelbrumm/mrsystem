#include <stdlib.h>
#include "bitmask.h"

/* How many bits in an unsigned long */
#define bitsperlong (8 * sizeof(unsigned long))
/* howmany(a,b) : how many elements of size b needed to hold all of a */
#define howmany(x, y) (((x)+((y)-1))/(y))
/* How many longs in mask of n bits */
#define longsperbits(n) howmany(n, bitsperlong)

Bitmask *BitmaskCreate(unsigned int bits)
{  Bitmask *bmp;

   bmp = malloc(sizeof(Bitmask));
   if (bmp != (Bitmask *)NULL)
   {
      bmp->size = bits;
      bmp->maskp = calloc(longsperbits(bits), sizeof(unsigned long));
      if (bmp->maskp == 0)
      {
         free(bmp);
         bmp = (Bitmask *)NULL;
      }
   }
   return bmp;
}
