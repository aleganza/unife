#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

int main(int argc, char* argv[]) {
    FILE* fpbin;
    FILE* fptxt;
    Lista l;
    nuovaLista (&l);

    Record r;
    char CFbuffer[DIM];

    if (argc != 3) {
        printf ("Errore linea di comando, perfavore scrivere: %s nomeFileBin NomeFileTxt", argv[0]);
        exit (1);
    }
    
    fpbin = fopen (argv[1], "rb");
    if (fpbin == NULL) {
        printf ("Errore apertura file %s", argv[1]);
        exit (2);
    }

    while (fread(CFbuffer, sizeof(CFbuffer), 1, fpbin) == 1) {
        inizLista(&l, CFbuffer);
    }

    fptxt = fopen (argv[2], "rt");
    if (fptxt == NULL) {
        printf ("Errore apertura file %s", argv[2]);
        exit (3);
    }

    while (fscanf(fptxt, "%s%d", r.CF, &r.attivita) == 2) {
        // prendo riga
        // trovo elemento nella lista
        // decremento
        scorriLista(&l, r);
    }

    stampaLista(l);

    fclose (fpbin);
    fclose (fptxt);
    return 0;
}