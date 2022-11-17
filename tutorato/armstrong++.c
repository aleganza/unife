#include <stdio.h>
#include <math.h>

int trovaCifre (int n) {
    int cifre;

    while (n > 0) {
        cifre++;
        n /= 10;
    }

    return cifre;
}

int sommaCifreConEsp (int n, int cifre) {
    int armstrong = 0;

    while (n > 0) {
        armstrong += pow((n%10), cifre);
        n /= 10;
    }

    return armstrong;
}

int isArmstrong (int n, int armstrong) {
    if (n == armstrong) return 1;
    else return 0;
}

int main () {
    int n;
    int cifre,  
        armstrong;

    printf ("Inserisci un numero\n");
    scanf ("%d", &n);

    cifre = trovaCifre (n);
    armstrong = sommaCifreConEsp (n, cifre);

    if (isArmstrong (n, armstrong)) {
        printf ("Il numero inserito appartiene ai numeri di Armostrong");
    } else {
        printf ("Il numero inserito NON appartiene ai numeri di Armostrong");
    }

    printf ("\n");
    return 0;
}