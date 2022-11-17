#include <stdio.h>

int main () {
    int n, somma = 0;

    printf ("Inserire un numero: ");
    scanf ("%d", &n);

    for (int i=1; i<n; i++) {
        if (n % i == 0) {
            somma += i;
        }
    }

    if (n == somma) {
        printf ("Il numero %d e' un numero perfetto", n);
    } else {
        printf ("Il numero %d NON e' un numero perfetto", n);
    }
}