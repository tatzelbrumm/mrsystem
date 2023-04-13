#include <bitmask.h>
#define BYTESTREAM_INTERN
#include "bytestream.h"

_GetLongFromByteArrayType _GetLongFromByteArrayPtr = _BeGetLongFromByteArray;

unsigned long _BeGetLongFromByteArray(unsigned char *Data)
{
   return ((unsigned long)Data[0] << SHIFT_3_BYTE) |
          ((unsigned long)Data[1] << SHIFT_2_BYTE) |
          ((unsigned long)Data[2] << SHIFT_1_BYTE) |
          ((unsigned long)Data[3] << SHIFT_0_BYTE);
}

unsigned long _LeGetLongFromByteArray(unsigned char *Data)
{
   return ((unsigned long)Data[3] << SHIFT_3_BYTE) |
          ((unsigned long)Data[2] << SHIFT_2_BYTE) |
          ((unsigned long)Data[1] << SHIFT_1_BYTE) |
          ((unsigned long)Data[0] << SHIFT_0_BYTE);
}

unsigned long GetLongFromByteArray(unsigned char *Data)
{
   return(_GetLongFromByteArrayPtr(Data));
}
