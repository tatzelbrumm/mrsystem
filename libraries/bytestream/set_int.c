#include <bitmask.h>
#define BYTESTREAM_INTERN
#include "bytestream.h"

_SetIntToByteArrayType _SetIntToByteArrayPtr = _BeSetIntToByteArray;

void _BeSetIntToByteArray(unsigned char *Data, unsigned int Value)
{
   Data[0] = (Value >> SHIFT_1_BYTE) & MASK_LOW_BYTE;
   Data[1] = (Value >> SHIFT_0_BYTE) & MASK_LOW_BYTE;
}

void _LeSetIntToByteArray(unsigned char *Data, unsigned int Value)
{
   Data[0] = (Value >> SHIFT_0_BYTE) & MASK_LOW_BYTE;
   Data[1] = (Value >> SHIFT_1_BYTE) & MASK_LOW_BYTE;
}

void SetIntToByteArray(unsigned char *Data, unsigned int Value)
{
   _SetIntToByteArrayPtr(Data, Value);
}
