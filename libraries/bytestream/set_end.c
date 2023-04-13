#define BYTESTREAM_INTERN
#include "bytestream.h"

extern _GetIntFromByteArrayType _GetIntFromByteArrayPtr;
extern _GetLongFromByteArrayType _GetLongFromByteArrayPtr;
extern _SetIntToByteArrayType _SetIntToByteArrayPtr;
extern _SetLongToByteArrayType _SetLongToByteArrayPtr;

void ByteStreamSetEndianess(int Endianess)
{
   if (Endianess == BYTESTREAM_LITTLE_ENDIAN)
   {
      _GetIntFromByteArrayPtr = _LeGetIntFromByteArray;
      _GetLongFromByteArrayPtr = _LeGetLongFromByteArray;
      _SetIntToByteArrayPtr = _LeSetIntToByteArray;
      _SetLongToByteArrayPtr = _LeSetLongToByteArray;
   }
   else if (Endianess == BYTESTREAM_BIG_ENDIAN)
   {
      _GetIntFromByteArrayPtr = _BeGetIntFromByteArray;
      _GetLongFromByteArrayPtr = _BeGetLongFromByteArray;
      _SetIntToByteArrayPtr = _BeSetIntToByteArray;
      _SetLongToByteArrayPtr = _BeSetLongToByteArray;
   }
}
