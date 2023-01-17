#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista* pl) {
    *pl = NULL;
}

void stampaLista(Lista l) {
    while (l != NULL) {
        printf ("%s %d %d %d\n", l->dato.CF, l->dato.cnt[0], l->dato.cnt[1], l->dato.cnt[2]);
        l = l->next;
    }
}

void inizLista(Lista *pl, char* d) {
    // while (*pl != NULL) {
    //     pl = &(*pl)->next;
    // }

    Nodo* nodo = (Nodo*) malloc (sizeof(Nodo));

    strcpy (nodo->dato.CF, d);
    nodo->dato.cnt[0] = 4;
    nodo->dato.cnt[1] = 4;
    nodo->dato.cnt[2] = 4;

    nodo->next = *pl;
    *pl = nodo;
}

void accessoNegato(Record d) {
    printf ("Codice Fiscale %s, attivita' %d: Accesso negato\n", d.CF, d.attivita);
}

void scorriLista(Lista *pl, Record d) {
    while (*pl != NULL) {
        if (!strcmp((*pl)->dato.CF, d.CF)) {
            break;
        }
        
        pl = &(*pl)->next;
    }

    switch(d.attivita) {
        case 1: {
            if ((*pl)->dato.cnt[0] != 0) {
                (*pl)->dato.cnt[0]--;
            } else {
                accessoNegato(d);
            }
            break;
        }
        case 2: {
            if ((*pl)->dato.cnt[1] != 0) {
                (*pl)->dato.cnt[1]--;
            } else {
                accessoNegato(d);
            }
            break;
        }
        case 3: {
            if ((*pl)->dato.cnt[2] != 0) {
                (*pl)->dato.cnt[2]--;
            } else {
                accessoNegato(d);
            }
            break;
        }
    }
}