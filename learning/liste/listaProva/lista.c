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

// inizializzazione lista
void nuovaLista(Lista* pl) {
    *pl = NULL;
}

// stampa
void stampaLista(Lista l) {
    while (l != NULL) {
        printf ("Nome: %33s\n", l->dato.nome);
        printf ("Cognome: %30s\n", l->dato.cognome);
        printf ("Eta': %33d\n", l->dato.eta);
        printf ("\n");

        l = l->next;
    }
}

// inserimento in testa: se inserisco a, b, c secondo questo ordine, la lista sarà formata da c, b, a
void insTesta(Lista* pl, char* nome, char* cognome, int eta) {
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

    // il nuovo nodo viene collegato in testa alla lista
    nodo->next = *pl;
    
    // la lista (*pl) punta al nodo creato quindi alla testa
    *pl = nodo;
}

// Lista* ricerca(Lista* pl) {
//     while (*pl != NULL) {
//         pl = &(*pl)->next;
//     }

//     return pl;
// }

// scorrimento fino alla fine della lista per permettere l'inserimento in coda
Lista* ricerca(Lista* pl) {
    while (*pl){
        pl = &(*pl)->next;
    }
    return pl;
}

// inserimento in coda: se inserisco a, b, c secondo questo ordine, la lista sarà formata da a, b, c
void insCoda(Lista* pl, char* nome, char* cognome, int eta) {
    // scorro fino alla fine della lista
    pl = ricerca(pl);

    insTesta(pl, nome, cognome, eta);
}

int main() {
    Lista l;
    nuovaLista(&l);

    // listaNonOrdinata (&l, 5);

    insTesta(&l, "Alessio", "Ganzarolli", 19);
    insTesta(&l, "Simone", "Acuti", 19);
    // insTesta(&l, "Anas", "Noureddine", 18);
    // insTesta(&l, "Leonardo", "Lodi", 19);

    insCoda(&l, "Marius", "Ceban", 21);

    stampaLista(l);
    
    printf ("\n");
    return 0;
}