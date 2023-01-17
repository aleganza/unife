#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUrl.h"

int main(int argc, char* argv[]) {
    FILE *fp = fopen (argv[1], "rb");
    Lista l;
    nuovaLista(&l);
    Lista lOrd;
    nuovaLista(&lOrd);

    rigaFile riga;

    if (argc != 2) {
        printf ("Per avviare il programma scrivere: %s nomeDelFile", argv[0]);
        exit (1);
    }

    if (fp == NULL) {
        printf ("Errore in apertura file %s", argv[1]);
        exit (2);
    }
     
    while (fread(&riga, sizeof(rigaFile), 1, fp) == 1) {
        setUpLista (&l, riga);
    }

    printf ("Parte 1:\n");
    stampaLista(l);

    printf ("\nParte 2:\n");
    ordinaLista(l, &lOrd);
    stampaLista(lOrd);

    fclose(fp);
    return 0;
}