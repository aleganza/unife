#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALFDIM 7
#define CODDIM 3

typedef struct {
    char lettera[2];
    char codificato[CODDIM + 1]; // lunghezza + terminatore
} Coppia;

void stampaCoppia (Coppia sp[ALFDIM]) {
    for (int i=0; i<ALFDIM; i++) {
        printf ("%c - %s\n", sp[i].lettera[0], sp[i].codificato);
    }
}

int main() {
    Coppia p[ALFDIM];
    FILE *fpc;
    FILE *fpm;

    int dl = 0; 

    char riga[50]; // riga del file
    char messaggio[CODDIM + 1]; // messaggio codificato + terminatore
    char decodificata[1]; // parola decodificata
    
    fpc = fopen ("corrispondenze.txt", "rt");
    if (fpc == NULL) {
        printf ("Errore in apertura del file corrispondenze");
        exit (1);
    }
    
    // salvo i dati nello struct Coppia
    while (fscanf(fpc, "%s%s", p[dl].lettera, p[dl].codificato) == 2) {
        // printf ("%c %s\n", p[dl].lettera[0], p[dl].codificato);
        dl++;
    }

    // stampaCoppia (p);

    fpm = fopen ("messaggi.txt", "rt");
    if (fpm == NULL) {
        printf ("Errore in apertura del file messaggi");
        exit (1);
    }

    int i, j = 0, k = 0, l = 0;

    // ciclo ogni riga
    while (fscanf(fpm, "%s", riga) == 1) {
        // ciclo ogni lettera
        for (i=0; i<strlen(riga); i++) {
            // ogni tre lettere azzero j e concateno messaggio a decodificata
            printf ("\n.");
            if (j == 3) {
                j = 0;

                strcat (messaggio, decodificata);
            }

            messaggio[j] = riga[i];
            printf ("%s", messaggio);
            j++;
        }

        strcat (" ", decodificata);
    }

    // printf ("%s ue", decodificata);

    fclose (fpc);
    printf ("\n");
    return 0;
}