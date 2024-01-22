// Estrare una parola a caso dal file 'words_italian.txt'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 31
#define LEN 61000 // con 100.000 non va (?)

// funzione per estrarre una parola a caso dalla elenco
void parolaCasuale(char *parolaRandom, int *index, char parole[][DIM], int dl) {
    // creo una stringa dove collocare la parola random
    *index = rand() % dl;

    char randP[DIM]; strcpy(randP, parole[*index]);

    // copio la parola random dentro la stringa passata per riferimento
    for (int i=0; i<sizeof(randP); i++) {
        *(parolaRandom+i) = randP[i];
    }
}

int main() {
    char parole[LEN][DIM];
    char parolaRandom[DIM];
    int index; // indice della parola random nell'elenco

    FILE *fp = fopen ("words.italian.txt", "rt");

    if (fp == NULL) {
        printf ("Errore in apertura file");
        exit (1);
    }

    // trovo la dimensione logica
    int dl = 0;
    while (fscanf(fp, "%30s", parole[dl]) == 1) {
        dl++;
    }

    // estraggo la parola casuale e la stampo
    parolaCasuale(parolaRandom, &index, parole, dl);
    printf ("La parola random e' %s, collocata all'indice %d", parolaRandom, index);

    printf ("\n");
    return 0;
}