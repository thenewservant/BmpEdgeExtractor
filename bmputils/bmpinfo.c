
#include <stdio.h>
#include <stdlib.h>
#include "bmpinfo.h"

#define READ2 fread(&var, 2,1, fileptr);
#define READ4 fread(&var, 4,1, fileptr);


bmpinfo *initbmpinfo(FILE* fileptr){ //Filling only the BITMAPINFOHEADER part of the header into the struct. Remaining bytes will be ignored.

    bmpinfo *tmp=calloc(1,sizeof(bmpinfo));

    uint32_t var=0;

    fseek(fileptr,10,0);
    fread(&var, 1,1, fileptr);//read the starting position of the pixel array.

    tmp->startpoint=var;

    fseek(fileptr,14,0);
    READ4;

    tmp->dibheaderlength=var;
    tmp->realheaderlength=(tmp->startpoint-14);

    READ4; //fread(&var, 4,1, fileptr);
    tmp->width=var;

    READ4;
    tmp->height=var;

    READ2; //fread(&var, 2,1, fileptr);
    tmp->colorplanes=var;

    READ2;
    tmp->bitsperpixel=var;

    READ4;
    tmp->compressionmethod=var;

    READ4;
    tmp->imagesize=var;

    tmp->fullbmpheader=malloc((tmp->startpoint));

    fseek(fileptr,0,0);

    for (int i=0;i<(tmp->startpoint);i++){ //duplicating the DIB header into the bmpinfo struct.
        fread(&var, 1,1, fileptr);
        tmp->fullbmpheader[i]=var;
    }
    return tmp;

}


void printbmpinfo(bmpinfo *tmp){

    printf("\nDIB header size: %d",tmp->dibheaderlength);
    printf("\ntype: ");
    switch(tmp->dibheaderlength){

    case BITMAPCOREHEADER:
        printf("\ntype: BITMAPCOREHEADER");
        break;
    case BITMAPINFOHEADER:
        if (tmp->realheaderlength!=40){
            printf("variant of BITMAPINFOHEADER (actual size: %d)",tmp->realheaderlength);
        }else{
        printf("BITMAPINFOHEADER");
        }
        break;
    }

    printf("\nwidth: %d",tmp->width);
    printf("\nheight: %d",tmp->height);
    printf("\ncolor planes: %d",tmp->colorplanes);
    printf("\nbits per pixel: %d",tmp->bitsperpixel);
    printf("\ncompression method: %d",tmp->compressionmethod);
    printf("\narray start position: %d",tmp->startpoint);
    if (tmp->imagesize){
        printf("\nimage size: %d bytes",tmp->imagesize);
    }
    printf("\n");
}



