#include <stdio.h>
#include <stdlib.h>
#include "bmputils/bmpinfo.h"
#include "bmputils/loadbmp.h"
#include "bmpfilters/edgeextractor.h"
#include "bmputils/savebmp.h"

FILE *checkfile(int, char**);
void usage();

int main( int argc, char* argv[]){


    if (argc==1){
    	usage();
    }

    if (argc==2){
    	if ((!strcmp(argv[1],"--help")) || (!strcmp(argv[1],"-h"))){
    		printf("\nBMPEDGE V1.0 -- simple BMP edge detector\n");
    		usage();
    	}else{
    		usage();
    	}
    }

    if (argc==3){
    	if (!strcmp(argv[1], "-i") || !strcmp(argv[1], "--info")){
    		FILE *fileptr=checkfile(argc,argv);
			bmpinfo *currentbmpinfo=initbmpinfo(fileptr);

			printbmpinfo(currentbmpinfo);
			exit(0);
    	}

    }

    FILE *fileptr=checkfile(argc,argv);
	bmpinfo *currentbmpinfo=initbmpinfo(fileptr);

	printbmpinfo(currentbmpinfo);

    bmparray *image=loadbmp(currentbmpinfo, fileptr);
    bmparray *new=edgeextractor(image,currentbmpinfo);
    uint8_t error=savebmp(currentbmpinfo, new,argv[2]);

    if (error) {
    	printf("Problem saving file, please check file save path");
    	exit(1);
    }

}


FILE *checkfile(int argc, char **argv){
    if (!(argc>1)){
        printf("Missing argument");
        exit(0);
    }

    FILE *tmp=fopen(argv[1],"rb");

    if (!tmp){
        printf("File does not exist");
        exit(0);
    }

    uint32_t val=0;

    fread(&val, 4,1, tmp);

        if (val==0x4d42){
            printf("Invalid Microsoft Bitmap image");
            exit(0);
        }
    return tmp;
}

void usage(){
	printf("\nUsage:");
	printf("\n	bmpedge --help : this message");
	printf("\n	bmpedge --info | -i  <file>  : shows bitmap info about the input file");
	printf("\n	bmpedge <filein> <fileout> : detects edges in filein, and saves them into fileout");
	exit(0);
}
