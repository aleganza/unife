// potenza di un numero

#include <stdio.h>

float potenza (int base, int esp) {
    float ris = 1;

    if (esp > 0) {
        for (int i=0; i<esp; i++) {
            ris = ris * base;
        }
    } else if (esp < 0){
        for (int i=0; i>esp; i--) {
            ris = ris / base;
        }
    }

    return ris;
}

int main() {
    int base, esp;

    printf("Inserisci un baseumero: ");
    scanf("%d", &base);

    printf("Inserisci l'esponente: ");
    scanf("%d", &esp);

    printf ("%f", potenza (base, esp));

    printf("\n");
    return 0;
}