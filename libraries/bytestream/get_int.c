#include <bitmask.h>
#define BYTESTREAM_INTERN
#include "bytestream.h"

_GetIntFromByteArrayType _GetIntFromByteArrayPtr = _BeGetIntFromByteArray;

unsigned int _BeGetIntFromByteArray(unsigned char *Data)
{
   return ((unsigned int)Data[0] << SHIFT_1_BYTE) |
          ((unsigned int)Data[1] << SHIFT_0_BYTE);
}

unsigned int _LeGetIntFromByteArray(unsigned char *Data)
{
   return ((unsigned int)Data[1] << SHIFT_1_BYTE) |
          ((unsigned int)Data[0] << SHIFT_0_BYTE);
}

unsigned int GetIntFromByteArray(unsigned char *Data)
{
   return(_GetIntFromByteArrayPtr(Data));
}
