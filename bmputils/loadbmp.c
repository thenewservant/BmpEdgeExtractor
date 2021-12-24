#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bmpinfo.h"
#include "loadbmp.h"

#define NEEDEDBYTES(a) ((a%8>0)? (a/8)+1 : a/8)

bmparray *loadbmp(bmpinfo *info, FILE *fileptr){

    uint32_t height=info->height;
    uint32_t width=info->width;
    uint32_t bpp=NEEDEDBYTES(info->bitsperpixel);

    uint8_t padding=((width*bpp%4)==0)?0:(4*(1+(bpp*width)/4))%(bpp*width);// computes padding such that the length of every pixel array row is a multiple of 4
    printf("\n,%d",padding);
    bmparray *image=bmparrayallocate(height,width,bpp,padding);

    fseek(fileptr,info->startpoint,0);

    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            for (int k=0;k<bpp;k++){
            	uint8_t dump=0;
                fread(&image->data[i][j][k], 1,1, fileptr);
            }
        }

        fseek(fileptr,padding,SEEK_CUR); //skips padding

    }

    return image;
}

bmparray *bmparrayallocate(int x, int y, int z,uint8_t padding){

    bmparray *img=malloc(sizeof(bmparray));

    img->bytesperpixel=z;
    img->padding=padding;

    img->data=malloc(x*sizeof(uint8_t**));

    int i,j;
    for (i=0;i<x;i++){

        img->data[i]=malloc(y*sizeof(uint8_t*));
        for (j=0;j<y;j++){
           img->data[i][j]=calloc(z,sizeof(uint8_t));
        }
    }

    return img;

}
