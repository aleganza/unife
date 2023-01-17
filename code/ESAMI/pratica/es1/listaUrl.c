#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUrl.h"

void nuovaLista(Lista *pl) {
    *pl = NULL;
}

void stampaLista(Lista l) {
    while (l != NULL) {
        if (l->dato.nVisite >= 5) {
            printf ("%s %d %d:%d\n", l->dato.url, l->dato.nVisite, l->dato.ora, l->dato.minuto);
        }

        l = l->next;
    }
}

void insTesta(Lista *pl, rigaFile d) {
    // Lista nodo = (Nodo*) malloc (sizef(Nodo));
    Nodo* nodo = (Nodo*) malloc (sizeof(Nodo));

    if (nodo == NULL) {
        printf ("Errore: allocazione di memoria non riuscita.");
        exit (100);
    }

    strcpy (nodo->dato.url, d.url);
    nodo->dato.ora = d.ora;
    nodo->dato.minuto = d.minuto;
    nodo->dato.nVisite = 1;

    nodo->next = *pl;

    *pl = nodo;
}

void insTestaDato(Lista *pl, Dato d) {
    // Lista nodo = (Nodo*) malloc (sizef(Nodo));
    Nodo* nodo = (Nodo*) malloc (sizeof(Nodo));

    if (nodo == NULL) {
        printf ("Errore: allocazione di memoria non riuscita.");
        exit (100);
    }

    strcpy (nodo->dato.url, d.url);
    nodo->dato.ora = d.ora;
    nodo->dato.minuto = d.minuto;
    nodo->dato.nVisite = d.nVisite;

    nodo->next = *pl;

    *pl = nodo;
}

void setUpLista(Lista* pl, rigaFile riga) {
    // scorro la lista
    while (*pl != NULL) {
        // esco se esiste già un elemento uguale
        if ( !strcmp((*pl)->dato.url, riga.url) ) {
            // per settare il maggior tempo di attività
            if ((*pl)->dato.ora < riga.ora) {
                (*pl)->dato.ora = riga.ora;
                (*pl)->dato.minuto = riga.minuto;
            }

            (*pl)->dato.nVisite++;

            return;
        }

        pl = &(*pl)->next;
    }
    
    insTesta(pl, riga);
}



void insOrd(Lista *plOrd, Dato d) {
    while (*plOrd != NULL) {
        if (d.nVisite > (*plOrd)->dato.nVisite) {
            break;
        }
        
        plOrd = &(*plOrd)->next;
    }

    insTestaDato(plOrd, d);
}

void ordinaLista(Lista l, Lista* plOrd) {
    while (l) {
        insOrd (plOrd, l->dato);
        l = l->next;
    }
}