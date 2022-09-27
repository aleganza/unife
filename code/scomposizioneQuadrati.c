/* 
    Scrivere un programma che legge un intero positivo n da stdin e verifica se
    n può essere scomposto nella somma di due quadrati (verifica cioè se PER OGNI A a,
    b APPARTIENE A N | a^2+b^2=n ). Se sì, stampare a video la scomposizione.
*/

#include <stdio.h>
#include <stdlib.h>

int checkExp(int n) {
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i*i + j*j == n){
                printf ("%d al quadrato + %d al quadrato vale %d\n", i, j, n);
                /* return 1; */
            }
        }
    }

    return 0;
}

int main() {
    int n;

    printf ("Inserisci un numero: ");
    scanf("%d", &n);

    if(!checkExp(n))
        printf ("niente :(");

    printf ("\n");
    return 0;
}