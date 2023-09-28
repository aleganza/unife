#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define DIM 30

typedef struct {
    char nome[DIM];
    char cognome[DIM];
    int eta;
} Dato;

typedef struct nodo {
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void stampaLista(Lista l);

void insTesta(Lista* pl, char* nome, char* cognome, int eta);
Lista* scorri(Lista* pl);
void insCoda(Lista* pl, char* nome, char* cognome, int eta);

void elimTesta(Lista* pl);
// void elimCoda(Lista* pl);

Lista* ricerca(Lista* pl, Dato d);