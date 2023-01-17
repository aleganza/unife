#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 17

typedef struct {
    char CF[DIM];
    int attivita;
} Record;

typedef struct {
    char CF[DIM];
    int cnt[3];
} Dato;

typedef struct nodo {
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void stampaLista(Lista l);
void inizLista(Lista *pl, char* d);
void scorriLista(Lista *pl, Record d);
void accessoNegato(Record d);