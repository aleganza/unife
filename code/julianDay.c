// Juliand Day (JD)

#include <stdio.h>

int main() {
    int G, M, A;
    int JD, N0, N1, N2, N3;

    printf ("--- Inserire la data: ---\n");
    printf ("Inserire il giorno della data:\n");
    scanf ("%d", &G);

    printf ("Inserire il mese della data:\n");
    scanf ("%d", &M);

    printf ("Inserire l'anno della data:\n");
    scanf ("%d", &A);

    // calcolo JD
    N0 = (M - 14) / 12;
    N1 = (1461 * (A + 4800 + N0)) / 4;
    N2 = (367 * (M - 2 - 12*N0)) / 12;
    N3 = (3 * (A + 4900 + N0)) / 400;

    JD = N1 + N2 - N3 + G - 32075;

    printf ("Il Julian Day vale: %d", JD);

    printf ("\n");
    return 0;
}