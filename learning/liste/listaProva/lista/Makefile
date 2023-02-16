eseguibile: main.o fun.o
	gcc -g -o eseguibile main.o fun.o

fun.o: fun.c fun.h
	gcc -g -c fun.c

main.o: main.c fun.h
	gcc -g -c main.c