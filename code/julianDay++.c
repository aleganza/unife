// Juliand Day++ con funzioni

#include <stdio.h>

int jd (int G, int M, int A) {
    int N0, N1, N2, N3;

    // calcolo JD
    N0 = (M - 14) / 12;
    N1 = (1461 * (A + 4800 + N0)) / 4;
    N2 = (367 * (M - 2 - 12*N0)) / 12;
    N3 = (3 * (A + 4900 + N0)) / 400;

    return N1 + N2 - N3 + G - 32075;
}

// giorno della settimana
char giorno (int G, int M, int A) {
    int day = jd (G, M, A);

    if (day % 7 == 0) return 'l';
    else if (day % 7 == 1) return 'm';
    else if (day % 7 == 2) return 'M';
    else if (day % 7 == 3) return 'g';
    else if (day % 7 == 4) return 'v';
    else if (day % 7 == 5) return 's';
    else if (day % 7 == 6) return 'd';
}

int main() {
    int G, M, A;

    printf ("Inserire il giorno della data:\n");
    scanf ("%d", &G);

    printf ("Inserire il mese della data:\n");
    scanf ("%d", &M);

    printf ("Inserire l'anno della data:\n");
    scanf ("%d", &A);

    printf ("Giorno: %c", giorno (G, M, A));

    printf ("\n");
    return 0;
}