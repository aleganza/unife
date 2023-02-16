// verifica se è un anno è bisestile

#include <stdio.h>

int main() {
    int anno;

    printf ("Inserisci l'anno: ");
    scanf("%d", &anno);

    if ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0)
        printf ("L'anno %d e' bisestile", anno);
    else
        printf ("L'anno %d NON e' bisestile", anno);

    printf("\n");
    return 0;
}