#include <stdio.h>

#define DIM 30

typedef struct {
    char nome[DIM];
    char cognome[DIM];
    int eta;
} Dato;

typedef struct nodo {
    Dato dato;
    struct nodo* next;
} Nodo

typedef Nodo* Lista;



int main() {
    Lista l;

    printf ("\n");
    return 0;
}