
all : bmptools


bmptools: bin  main.o bmpinfo.o edgeextractor.o loadbmp.o savebmp.o
	gcc -o  bin/bmpedge bin/main.o bin/edgeextractor.o bin/bmpinfo.o bin/loadbmp.o bin/savebmp.o
bin: 
	- mkdir bin

main.o:
	gcc -o bin/main.o -c main.c

edgeextractor.o:
	gcc -o bin/edgeextractor.o -c bmpfilters/edgeextractor.c

bmpinfo.o:
	gcc -o bin/bmpinfo.o -c bmputils/bmpinfo.c

loadbmp.o:
	gcc -o bin/loadbmp.o -c bmputils/loadbmp.c
savebmp.o:
	gcc -o bin/savebmp.o -c bmputils/savebmp.c
	