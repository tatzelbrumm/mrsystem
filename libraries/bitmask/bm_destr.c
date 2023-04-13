#include <stdlib.h>
#include "bitmask.h"

void BitmaskDestroy(Bitmask *bmp)
{
   if (bmp != (Bitmask *)NULL)
   {
      free(bmp->maskp);
      bmp->maskp = (unsigned long *)NULL;
      free(bmp);
   }
}
