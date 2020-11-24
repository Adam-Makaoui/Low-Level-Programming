
all: doublylinkedlist

doublylinkedlist: doublylinkedlist.c
	gcc -std=c11 -pedantic-errors doublylinkedlist.c -o dList

clean:
	rm -rf doublylinkedlist



