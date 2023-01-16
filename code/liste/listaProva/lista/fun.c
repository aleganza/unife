#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "fun.h"

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

// scorrimento fino alla fine della lista per permettere l'inserimento in coda
Lista* scorri(Lista* pl) {
    while (*pl){
        pl = &(*pl)->next;
    }
    return pl;
}

// inserimento in coda: se inserisco a, b, c secondo questo ordine, la lista sarà formata da a, b, c
void insCoda(Lista* pl, char* nome, char* cognome, int eta) {
    // scorro fino alla fine della lista
    pl = scorri(pl);

    insTesta(pl, nome, cognome, eta);
}

//elimino un elemento dalla testa
void elimTesta(Lista* pl) {
    if (*pl == NULL) {
        printf ("La lista e' vuota\n");
        return;
    }

    Nodo* tmp = *pl;

    *pl = (*pl)->next;
    free(tmp);
}

// void elimTesta ( Lista * pl ) {
//     Nodo * aux = * pl ;
//     * pl = (* pl ) -> next ;
//     free ( aux ) ;
// }

// void elimCoda(Lista *pl) {
//     if (*pl == NULL) {
//         printf ("La lista e' vuota\n");
//         return;
//     }
// }

Lista* ricerca(Lista* pl, Dato d) {
    if (*pl == NULL) {
        printf ("La lista e' vuota");
        return pl;
    }

    while (*pl) {
        if (!strcmp((*pl)->dato.nome, d.nome) &&
            !strcmp((*pl)->dato.cognome, d.cognome) &&
            (*pl)->dato.eta == d.eta) {
            
            return pl;
        }

        pl = &(*pl)->next;
    }

}