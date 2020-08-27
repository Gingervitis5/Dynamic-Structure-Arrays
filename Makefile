CC = gcc

all:	lab13

lab13:	cscd240Lab13.c  lab13.o ./utils/fileUtils.c ./utils/fileUtils.h ./utils/utils.c ./utils/utils.h
	gcc -m32 cscd240Lab13.c ./utils/fileUtils.c ./utils/utils.c lab13.o -o lab13

lab13.o:	lab13.c lab13.h
	gcc -c -m32 lab13.c

clean:
	rm lab13.o
	rm lab13

