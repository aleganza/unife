cronologia: main.o listaUrl.o
	gcc -g -o cronologia main.o listaUrl.o

listaUrl.o: listaUrl.c listaUrl.h
	gcc -g -c listaUrl.c

main.o: main.c listaUrl.h
	gcc -g -c main.c