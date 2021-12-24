#ifndef BMPINFO_H_INCLUDED
#define BMPINFO_H_INCLUDED

#include <stdint.h>


enum HEADERTYPE{
    BITMAPCOREHEADER=12,
    OS22XBITMAPHEADER=16,
    BITMAPINFOHEADER=40,
    BITMAPV2INFOHEADER=52,
    BITMAPV3INFOHEADER=56,
    BITMAPV4HEADER=128,
    BITMAPV5HEADER=124
    };

typedef struct dibcontents{

    uint32_t startpoint;
    uint32_t width,height;
    uint32_t imagesize;
    uint32_t compressionmethod;

    uint16_t colorplanes;
    uint16_t bitsperpixel;

    uint8_t dibheaderlength;
    uint8_t realheaderlength;

    uint8_t *fullbmpheader;


}bmpinfo;

bmpinfo *initbmpinfo(FILE* fileptr);
void printbmpinfo(bmpinfo *tmp);

#endif // BMPINFO_H_INCLUDED
