/* 
    - Una ladro è riuscito ad intrufolarsi all’interno di un caveau di una banca. Tuttavia si è dimenticato di prendere con
        se uno zaino quindi non riesce a portare via tutte le pietre preziose che ha trovato ma può portarne via
        solamente k (quelle che riesce a tenere in mano). Tra tutte le pietre presenti sceglierà le k più preziose.
    - Scrivere un programma che legga da tastiera tutte le k ≤ n ≤ 20, pietre contenute nel caveau con relativo nome
        e valore.
    - Salvare poi questi due campi in una struttura pietra composta da un campo int valore e un campo char
        nome[DIM] con DIM = 20.
    - Inserire ciascuna struttura in un array di strutture e ordinarlo sul campo valore in maniera crescente. Selezionare
        poi le prime k pietre e stamparle.
    - Sviluppare la soluzione utilizzando il numero di funzioni che si ritiene adeguato.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 20

typedef struct {
    int valore;
    char nome[DIM];
} pietra;

void inserisciPietre(pietra *s, int index) {
    for (int i=0; i<index; i++) {
        printf ("%d - Nome della pietra: ", i);
        scanf ("%s", s[i].nome);

        s[i].valore = rand() % 50 + 1;

        // printf ("%d - Valore della pietra: ", i);
        // scanf ("%d", &s[i].valore);
    }
}

void swap(pietra *s, int i, int j) {
    pietra tmp;

    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void ordinaPietre(pietra *s, int index) {
    for (int i=0; i<index; i++) {
        for (int j=i; j<index; j++) {
            if (s[j].valore > s[i].valore) {
                swap(s, i, j);
            }
        }
    }
}

void stampaPietre(pietra *s, int index) {
    for (int i=0; i<index; i++) {
        printf ("%s - %d\n", s[i].nome, s[i].valore);
    }
}

int main() {
    int k,
        n;

    printf ("Inserire quante pietre puo' trasportare il ladro: ");
    scanf ("%d", &k);

    do {
        printf ("Inserire numero di pietre nel caveau: ");
        scanf ("%d", &n);
    } while (n < k || n > 20);

    pietra pietre[n];

    inserisciPietre(pietre, n);
    ordinaPietre(pietre, n);

    printf ("Pietre che il ladro riesce a rubare:\n");
    stampaPietre(pietre, k);

    printf ("\n");
    return 0;
}