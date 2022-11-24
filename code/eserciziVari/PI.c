#include <stdio.h>
#include <string.h>

/*
    verifica se il numero è primo:
    ritorna 0 se il numero vale 0, 1 o appena trova un suo divisore che non sia 1 o se stesso
    ritorna 1 se è idoneo al ciclo
    (il numero 2 skippa il ciclo e ritorna subito 1)
*/
int primo (int num) {
    if (num == 0 || num == 1) return 0;

    for (int i=2; i<num && num != 2; i++) {
        if (num % i == 0) return 0;
    }

    return 1;
}

int PI (int n) {
    int cnt = 0;

    for (int i=1; i<=n; i++) {
        if (primo (i)) cnt++;
    }

    return cnt;
}

int main () {
    int n;

    do {
        printf ("Inserisci un numero: ");
        scanf ("%d", &n);
    } while (n < 1);

    printf ("\n%d", PI (n));

    printf ("\n");
    return 0;
}