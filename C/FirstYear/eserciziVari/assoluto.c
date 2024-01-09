#include <stdio.h>

int main() {
    int n;
    printf ("Inserisci un intero:\n");
    scanf ("%d", &n);

    printf ("Il valore assoluto di %d vale %d", n, n < 0 ? -n : n);

    printf ("\n");
}