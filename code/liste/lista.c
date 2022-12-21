#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define DIM 30

// definizione del dato della lista
typedef struct {
    char nome[DIM];
    char cognome[DIM];
    int eta;
} Dato;

/*
    Definizione del nodo della lista
    Es di nodo:

    --------------------   
    -          -       -
    -   dato   -  next -
    -          -       -
    --------------------

*/

typedef struct nodo {
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo* Lista;

// stampa
void stampaLista (Lista l) {
    while (l != NULL) {
        printf ("Nome: %33s\n", l->dato.nome);
        printf ("Cognome: %30s\n", l->dato.cognome);
        printf ("Eta': %33d\n", l->dato.eta);
        printf ("\n");

        l = l->next;
    }
}

// es: se inserisco secondo a, b, c secondo questo ordine, la lista sarà formata da c, b, a (inserimento in testa)
void insTesta (Lista* pl, char* nome, char* cognome, int eta) {
    // alloco memoria per il nodo nuovo
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

    // controllo
    if (nodo == NULL) {
        printf ("Errore: allocazione di memoria non riuscita.");
        exit (100);
    }

    // assegno i dati al nodo
    strcpy (nodo->dato.nome, nome);
    strcpy (nodo->dato.cognome, cognome);
    nodo->dato.eta = eta;

    // attacco il nodo alla lista
    nodo->next = *pl;

    // testa
    *pl = nodo;
}

void insCoda (Lista* pl, char* nome, char* cognome, int eta) {
    
}

int main() {
    Lista l;

    // listaNonOrdinata (&l, 5);

    insTesta(&l, "Alessio", "Ganzarolli", 19);
    insTesta(&l, "Simone", "Acuti", 19);
    insTesta(&l, "Anas", "Noureddine", 18);
    insTesta(&l, "Leonardo", "Lodi", 19);

    insCoda(&l, "Marius", "Ceban", 21);

    stampaLista(l);

    printf ("\n");
    return 0;
}