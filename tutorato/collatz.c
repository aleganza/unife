#include <stdio.h>

int main () {
    int a, b, n, cnt = 0;

    printf ("Inserisci il valore iniziale: ");
    scanf ("%d", &a);

    printf ("Inserisci il valore finale: ");
    scanf ("%d", &b);

    for (int i=a; i<=b; i++) {
        n = i;

        do {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = n*3 + 1;
            }

            cnt++;

        } while (n > 1);

        printf ("Numero %d eseguito %d volte\n", i, cnt);
        cnt = 0;
    }
}