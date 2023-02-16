// numeri primi

#include <stdio.h>
#include <stdlib.h>

int main() {

    int cnt = 0;

    printf("Stampa numeri primi da 1 a 10:\n");

    for (int i=1; i<=2000; i++){
        for (int j=1; j<=i; j++){
            if (i%j == 0) {
                cnt++;
            }
        }

        if (cnt <= 2)
            printf ("%d ", i);
        else
            printf ("_ ");

        cnt = 0;
    }

    return 0;
}