all: hello.o
	gcc hello.o -o hi

hello.o: hello.c
	gcc -c hello.c

clean:
	rm *.o
	rm hi
