#ifndef BYTESTREAM_H
#define BYTESTREAM_H

#define BYTESTREAM_LITTLE_ENDIAN 1
#define BYTESTREAM_BIG_ENDIAN    2

#ifdef BYTESTREAM_INTERN

typedef unsigned int (*_GetIntFromByteArrayType)(unsigned char *Data);
typedef unsigned long (*_GetLongFromByteArrayType)(unsigned char *Data);
typedef void (*_SetIntToByteArrayType)(unsigned char *Data, unsigned int Value);
typedef void (*_SetLongToByteArrayType)(unsigned char *Data, unsigned long Value);

unsigned int _BeGetIntFromByteArray(unsigned char *Data);
unsigned int _LeGetIntFromByteArray(unsigned char *Data);
unsigned long _BeGetLongFromByteArray(unsigned char *Data);
unsigned long _LeGetLongFromByteArray(unsigned char *Data);
void _BeSetIntToByteArray(unsigned char *Data, unsigned int Value);
void _LeSetIntToByteArray(unsigned char *Data, unsigned int Value);
void _BeSetLongToByteArray(unsigned char *Data, unsigned long Value);
void _LeSetLongToByteArray(unsigned char *Data, unsigned long Value);

#endif

/*--- Prototypen globaler Funktionen ---------------------------------*/
unsigned long GetLongFromByteArray(unsigned char *Data);
unsigned int GetIntFromByteArray(unsigned char *Data);
void SetLongToByteArray(unsigned char *Data, unsigned long Value);
void SetIntToByteArray(unsigned char *Data, unsigned int Value);
void ByteStreamSetEndianess(int Endianess);

#endif /* BYTESTREAM_H */
