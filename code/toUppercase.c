#include <stdio.h>

int main() {
    char n;
    printf ("Inserisci una parola un carattere alla volta: ");

    do {
        scanf ("%c", &n);
        printf ("%c", (int) n >= 97 && n <= 122 ? n - 32 : n);

    } while (1);

    printf("\n");
    return 0;
}