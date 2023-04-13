#include <bitmask.h>
#define BYTESTREAM_INTERN
#include "bytestream.h"

_SetLongToByteArrayType _SetLongToByteArrayPtr = _BeSetLongToByteArray;

void _BeSetLongToByteArray(unsigned char *Data, unsigned long Value)
{
   Data[0] = (Value >> SHIFT_3_BYTE) & MASK_LOW_BYTE;
   Data[1] = (Value >> SHIFT_2_BYTE) & MASK_LOW_BYTE;
   Data[2] = (Value >> SHIFT_1_BYTE) & MASK_LOW_BYTE;
   Data[3] = (Value >> SHIFT_0_BYTE) & MASK_LOW_BYTE;
}

void _LeSetLongToByteArray(unsigned char *Data, unsigned long Value)
{
   Data[0] = (Value >> SHIFT_0_BYTE) & MASK_LOW_BYTE;
   Data[1] = (Value >> SHIFT_1_BYTE) & MASK_LOW_BYTE;
   Data[2] = (Value >> SHIFT_2_BYTE) & MASK_LOW_BYTE;
   Data[3] = (Value >> SHIFT_3_BYTE) & MASK_LOW_BYTE;
}

void SetLongToByteArray(unsigned char *Data, unsigned long Value)
{
   _SetLongToByteArrayPtr(Data, Value);
}
