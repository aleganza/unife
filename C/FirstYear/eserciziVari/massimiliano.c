// Leggere una serie di numeri interi passati dall’utente, fermandosi al primo numero che rende 
// la serie non crescente e restituendo quanti numeri erano stati inseriti.

#include <stdio.h>

#define DIM 20

int main() {
    int n = 0, prec = 0, cnt = 0;

    do {
        prec = n;
        printf ("Inserisci numero: ");
        scanf ("%d", &n);
        cnt++;
    } while (n > prec);

    printf ("%d", cnt);

    printf ("\n");
    return 0;
}