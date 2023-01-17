#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

typedef struct {
    char url[DIM];
    int ora;
    int minuto;
} rigaFile;

typedef struct {
    char url[DIM];
    int ora;
    int minuto;
    int nVisite;
} Dato;

typedef struct nodo {
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista *pl);
void stampaLista(Lista l);
void insTesta(Lista *pl, rigaFile d);
void insTestaDato(Lista *pl, Dato d);
void setUpLista(Lista* pl, rigaFile riga);
void ordinaLista(Lista l, Lista* plOrd);
