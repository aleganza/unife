#include <stdio.h>
#include <math.h>

int main () {
    int n;

    printf ("Inserisci un numero\n");
    scanf ("%d", &n);

    int cifre = 0, tmp = n, armstrong = 0;

    // trovo le cifre
    while (tmp > 0) {
        cifre++;
        tmp /= 10;
    }

    tmp = n;

    // controllo se appartiene alla sequenza
    while (tmp > 0) {
        armstrong += pow((tmp%10), cifre);
        tmp /= 10;
    }

    if (n == armstrong) {
        printf ("Il numero inserito appartiene ai numeri di Armostrong");
    } else {
        printf ("Il numero inserito NON appartiene ai numeri di Armostrong");
    }

    printf ("\n");
    return 0;
}