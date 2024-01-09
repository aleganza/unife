/* 
    - Leggere da tastiera due array di char di al più 100 elementi.
    - Sviluppare una funzione rimuoviDuplicati che, presi in ingresso i due array inseriti da tastiera, rimuova tutte le
        occorrenze di ciascuna lettera del secondo array dal primo array e che abbia come valore di ritorno il numero di
        caratteri eliminati.
    - Esempio:
        a1 = ’parolalunghissima’ (NB. senza spazi)
        a2 = ’la’
        risultato = ’prounghissim’
        eliminati = ’5’
*/

#include <stdio.h>
#include <string.h>

#define DIM 100

void shiftStringa(char *string, int index, int dim) {
    for (int i=index; i<dim; i++) {
        *(string+i) = *(string+i+1);
    }
}

int rimuoviDuplicati(char *a1, char *a2, int *eliminati) {
    for (int i=0; i<strlen(a1); i++) {
        for (int j=0; j<strlen(a2); j++) {

            // se trovo un duplicato
            if (*(a1+i) == *(a2+j)) {
                shiftStringa(a1, i, strlen(a1));
                i--;
                (*eliminati)++;
                // break;
            }
        }
    }
}

int main(int argc, char **argv) {
    char a1[DIM] = "parolalunghissima",
         a2[DIM] = "la";
    int eliminati = 0;

    rimuoviDuplicati (a1, a2, &eliminati);

    printf ("Risultato: %s\nEliminati: %d", a1, eliminati);

    printf ("\n");
    return 0;
}