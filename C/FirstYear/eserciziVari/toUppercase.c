// minuscole -> maiuscole

#include <stdio.h>

char toUppercase (char n) {
    return n >= 97 && n <= 122 ? n - 32 : n;
}

int main() {
    char n;
    printf ("Inserisci caratteri: ");

    do {
        scanf ("%c", &n);
        printf ("%c", toUppercase (n));
    } while (n != '\n');

    printf("\n");
    return 0;
}