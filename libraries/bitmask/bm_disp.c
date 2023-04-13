#include <string.h>
#include "bitmask.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

static inline int emit(char *buf, int buflen, int rbot, int rtop, int len)
{
   if (len > 0)
      len += snprintf(buf + len, max(buflen - len, 0), ",");
   if (rbot == rtop)
      len += snprintf(buf + len, max(buflen - len, 0), "%d", rbot);
   else
      len += snprintf(buf + len, max(buflen - len, 0), "%d-%d", rbot, rtop);
   return len;
}

int BitmaskDisplayList(char *buf, int buflen, const Bitmask *bmp)
{  int len;
   unsigned int cur, rbot, rtop;

   len = 0;
   if (buflen > 0)
      *buf = 0;
   rbot = cur = BitmaskFirst(bmp);
   while (cur < bmp->size)
   {
      rtop = cur;
      cur = BitmaskNext(bmp, cur+1);
      if (cur >= bmp->size || cur > rtop + 1)
      {
         len = emit(buf, buflen, rbot, rtop, len);
         rbot = cur;
      }
   }
   return len;
}
