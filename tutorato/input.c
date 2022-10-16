#include <stdio.h>

int main () {
    int n;
    int s = 0, max = 0, min = 101;

    do {
        printf ("Inserisci un numero: ");
        scanf ("%d", &n);

        s += n;
        if (n > max) max = n;
        if (n < min && n != 0) min = n;
    } while (n != 0);

    printf ("Somma: %d\nMax: %d\nMin: %d\n", s, max, min);
}