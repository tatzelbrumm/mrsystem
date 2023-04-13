#include <stdio.h>
#include <string.h>
#include "bitmask.h"

static BOOL scan_was_ok(int sret, char nextc, const char *ok_next_chars)
{
   return sret == 1 || (sret == 2 && strchr(ok_next_chars, nextc) != NULL);
}

static const char *nexttoken(const char *q,  int sep)
{
   if (q)
      q = strchr(q, sep);
   if (q)
      q++;
   return q;
}

int BitmaskParseList(const char *buf, Bitmask *bmp)
{  const char *p, *q;
   unsigned int a, b, s;
   const char *c1, *c2;
   char nextc;
   int sret;

   BitmaskClearAll(bmp);
   q = buf;
   while (p = q, q = nexttoken(q, ','), p)
   {
      sret = sscanf(p, "%u%c", &a, &nextc);
      if (!scan_was_ok(sret, nextc, ",-"))
         goto err;
      b = a;
      s = 1;
      c1 = nexttoken(p, '-');
      c2 = nexttoken(p, ',');
      if (c1 != NULL && (c2 == NULL || c1 < c2))
      {
         sret = sscanf(c1, "%u%c", &b, &nextc);
         if (!scan_was_ok(sret, nextc, ",:"))
            goto err;
         c1 = nexttoken(c1, ':');
         if (c1 != NULL && (c2 == NULL || c1 < c2))
         {
            sret = sscanf(c1, "%u%c", &s, &nextc);
            if (!scan_was_ok(sret, nextc, ","))
               goto err;
         }
      }
      if (!(a <= b))
         goto err;
      if (b >= bmp->size)
         goto err;
      while (a <= b)
      {
         BitmaskSetBit(bmp, a);
         a += s;
      }
   }
   return 0;
err:
   BitmaskClearAll(bmp);
   return -1;
}
