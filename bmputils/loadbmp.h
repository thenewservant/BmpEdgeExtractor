#ifndef LOADBMP_H_INCLUDED
#define LOADBMP_H_INCLUDED
#include "bmpinfo.h"
#include <stdint.h>

typedef struct bmparray{
    uint8_t padding;
    uint32_t bytesperpixel;
    uint8_t ***data;

}bmparray;

bmparray *loadbmp(bmpinfo *info, FILE *fileptr);
bmparray *bmparrayallocate(int x, int y, int z,uint8_t padding);

#endif // LOADBMP_H_INCLUDED
