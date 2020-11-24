
all: doubletroublelist

doubletroublelist: doubletroublelist.c
	gcc -std=c11 -pedantic-errors doubletroublelist.c -o dList

clean:
	rm -rf doubletroublelist



