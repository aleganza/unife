#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALFDIM 7
#define CODDIM 3

typedef struct {
    char lettera[2];
    char codificato[CODDIM + 1]; // lunghezza + terminatore
} Coppia;

// controlla esistenza del file
void fileEsiste (FILE *f) {
    if (f == NULL) {
        printf ("Errore in apertura del file corrispondenze");
        exit (1);
    }
}

// stampo le coppie
void stampaCoppie (Coppia sp[ALFDIM]) {
    for (int i=0; i<ALFDIM; i++) {
        printf ("%c - %s\n", sp[i].lettera[0], sp[i].codificato);
    }
}

int main() {
    Coppia p[ALFDIM];
    FILE *fpc;
    FILE *fpm;

    int i = 0;
    int dl = 0; 

    char righe[10][50]; 
    
    fpc = fopen ("corrispondenze.txt", "rt");
    fileEsiste (fpc);

    // salvo i dati nello struct Coppia
    while (fscanf(fpc, "%s%s", p[dl].lettera, p[dl].codificato) == 2) {
        // printf ("%c %s\n", p[dl].lettera[0], p[dl].codificato);
    }

    fpm = fopen ("messaggi.txt", "rt");
    fileEsiste (fpm);

    // ciclo ogni riga
    while (fscanf(fpm, "%s", righe[dl]) == 1) {
        dl++;
    }

    for (i=0; i<dl; i++) {
        printf ("| %s | \n", righe[i]);
    }

    fclose (fpc);
    fclose (fpm);

    printf ("\n");
    return 0;
}