/*
    Definizione del nodo della lista
    Esempio di nodo:

    --------------------   
    -          -       -
    -   dato   -  next -
    -          -       -
    --------------------

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "fun.h"

int main() {
    Lista l;
    nuovaLista(&l);

    // listaNonOrdinata (&l, 5);

    printf ("Inserisco in testa 2 elementi\n");
    insTesta(&l, "Alessio", "Ganzarolli", 19);
    insTesta(&l, "Simone", "Acuti", 19);
    stampaLista(l);

    printf ("Inserisco in coda 2 elementi\n");
    insCoda(&l, "Anas", "Noureddine", 19);
    insCoda(&l, "Leonardo", "Lodi", 19);
    // insCoda(&l, "Marius", "Ceban", 21);
    stampaLista(l);

    printf ("Elimino dalla testa 1 elemento\n");
    elimTesta(&l);
    stampaLista(l);
    
    // printf ("Elimino dalla coda 1 elemento\n");
    // elimCoda(&l);
    // stampaLista(l);

    Dato d;
    strcpy(d.nome, "Anas");
    strcpy(d.cognome, "Noureddine");
    d.eta = 19;

    printf ("Ricerca di un elemento nella lista\n");
    Lista* rl = ricerca(&l, d);
    printf ("\n%s\n\n", (*rl)->dato.nome);

    // insTesta(&l, "Ceban", "Marius", 19);
    stampaLista(l);

    printf ("\n");
    return 0;
}