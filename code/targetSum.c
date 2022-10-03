// Write a C program to divide two given integers without using multiplication, division and mod operator. Return the quotient after dividing.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dendo, sore;
    printf ("--- Divisione tra due numeri: ---\n");
    
    printf ("Inserisci il dividendo: \n");
    scanf ("%d", &dendo);
    printf ("Inserisci il divisore: \n");
    scanf ("%d", &sore);

    int quoz = 0;
    int resto = 0;
    for (int i=0; i<dendo; i+=sore){
        if ((dendo - i) < sore )
            resto = dendo - i;
        else
            quoz++;
    }

    printf ("Il quoziente vale %d, con un resto di %d", quoz, resto);

    printf ("\n");
    return 0;
}