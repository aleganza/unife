
// quadrato di un numero con l'uso di sole somme

#include <stdio.h>
#include <stdlib.h>

int toExp(int a, int e) {
    int value = 0;
    int k = 1;

    for(int i=0; i<a; i++){
        value += k;
        k += 2;
    }

    return value;
}

int main() {
    int a; // numero
    int e; // esponente

    do {
        printf ("Inserisci un numero intero positivo: ");
        scanf("%d", &a);
    } while(a <= 0);

    int value = toExp(a, e);

    printf ("\n\n%d", value);

    return 0;
}