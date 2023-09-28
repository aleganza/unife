/* 
    Si realizzi un programma che legga da tastiera un valore intero
    N, compreso tra 1 e 10, e stampi a video un “quadrato di
    asterischi” di lato N.
*/

#include <stdio.h>
#include <stdlib.h>

void printMatrix (int len, int mat[len][len]) {
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            printf ("%d", mat[i][j]);
        }
        printf ("\n");
    }
}

void clearMatrix (int len, int mat[len][len]) {
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            mat[i][j] = "_";
        }
    }
}

int main() {
    int n;

    do {
        printf ("Inserisci un numero compreso tra 1 e 10: ");
        scanf ("%d", &n);

    } while (n < 1 || n > 10);

    int mat[n][n];

    printf ("Quadrato: \n");

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mat[i][j] = 0;
        }
    }

    printMatrix (n, mat);

    printf ("Quadrato (solo lati): \n");

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==0 || i==n || j==0 || j==n)
                mat[i][j] = 0;
        }
    }

    printMatrix (n, mat);

    return 0;
}