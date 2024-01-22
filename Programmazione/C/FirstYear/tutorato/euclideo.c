#include <stdio.h>

int main () {
    int a, b;

    printf ("Inserisci il valore minore: ");
    scanf ("%d", &b);

    printf ("Inserisci il valore maggiore: ");
    scanf ("%d", &a);

    int mcd, q, r;

    while (b != 0) {
        r = a % b;

        a = b;
        b = r;
    } 

    printf ("%d", a);
}