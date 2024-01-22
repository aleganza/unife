#include <stdio.h>

#define DIM 50

int main() {
    int i = 0, j, DL;
    float n, a[DIM], tmp;

    do {
        printf ("Inserisci un numero: ");
        scanf ("%f", &n);

        if (n >= 0) {
            a[i] = n;
        } else {
            DL = i;
        }

        i++;
    } while (n >= 0);

    for (i = 0; i < DL; i++) {
        for (j = DL-1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }

    // stampa
    for (int i = 0; i < DL; i++) {
        printf ("%f ", a[i]);
    }

    printf ("\n");
    return 0;
}