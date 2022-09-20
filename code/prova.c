#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona {
    char nome[20];
    char cognome[20];
    int eta;

    struct persona * next;
} p;

char anagrafica(char nome, char cognome) {
    char a = strcat(nome, cognome);

    return a;
};

int main() {
    // struct persona p;

    p->nome = "simone";
    p->cognome = "acuti";

    // char a = anagrafica(p.nome, p.cognome);

    printf(p.nome);

    return 0;
}