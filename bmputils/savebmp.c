#include <stdio.h>
#include <stdlib.h>
#include "savebmp.h"

int savebmp(bmpinfo *info, bmparray *arr, char* path){
	FILE *svptr=fopen(path,"wb");

	if (!svptr){
		return 1; //can't create or modify file
	}

	//Writing the full header into the save file

	fwrite(info->fullbmpheader, info->startpoint,1,svptr);
	uint8_t dummy=35;

	 for (int i=0;i<info->height;i++){
	        for (int j=0;j<info->width;j++){
	            for (int k=0;k<arr->bytesperpixel;k++){

	            	fwrite(&arr->data[i][j][k],1,1,svptr);

	            }
	        }

	        	fwrite(&dummy,arr->padding,1,svptr);

	 }

	return 0;

}
