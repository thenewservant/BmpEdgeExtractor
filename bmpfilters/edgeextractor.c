#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../bmputils/loadbmp.h"
#include "../bmputils/bmpinfo.h"

bmparray *edgeextractor(bmparray *img,bmpinfo *info){
    uint32_t height=info->height;
    uint32_t width=info->width;
    uint32_t bpp=img->bytesperpixel;

    bmparray *map=bmparrayallocate(height,width,bpp,img->padding);

    int diff=0;

    for (int i=0;i<height;i++){
    	for (int j=0; j< width-1; j++){
    		for (int k=0;k<bpp; k++){

    			diff=img->data[i][j][k]-img->data[i][j+1][k];

    			if (diff<0) diff=-diff;
    			if (map->data[i][j][k]+diff>255){
					map->data[i][j][k]=255;
				}else{
					map->data[i][j][k]+=diff;
				}
    		}
    	}
    }

    for (int i=0;i<height-1;i++){
        	for (int j=0; j< width; j++){
        		for (int k=0;k<bpp; k++){
        			diff=img->data[i][j][k]-img->data[i+1][j][k];
        			if (diff<0) diff=-diff;
        			if (map->data[i][j][k]+diff>255){
        				map->data[i][j][k]=255;
        			}else{
        				map->data[i][j][k]+=diff;
        			}
        		}
        	}
        }


    return map;
}
