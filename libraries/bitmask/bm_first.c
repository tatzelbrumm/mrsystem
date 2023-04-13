#include "bitmask.h"

unsigned int BitmaskFirst(const Bitmask *bmp)
{
   return(BitmaskNext(bmp, 0));
}
