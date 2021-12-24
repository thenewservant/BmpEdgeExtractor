#ifndef LOADBMP_H_INCLUDED
#define LOADBMP_H_INCLUDED

#include <stdint.h>



typedef struct bmparray{
    uint8_t padding;
    uint32_t bytesperpixel;
    uint8_t ***data;

}bmparray;


bmparray *bmparrayallocate(int x, int y, int z,uint8_t padding);

#endif // LOADBMP_H_INCLUDED
