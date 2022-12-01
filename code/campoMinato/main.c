/*
    CAMPO MINATO

    * -> bomba

    esempio:
    ----------
    | *.*... |
    | ....*. |
    | ...**. |
    | **..** |
    ----------
*/

#include <stdio.h>
#include <stdlib.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.2

float rnd_float(float a, float b) {
    return a + (b-a) * (float)rand() / RAND_MAX; // numero casuale float compreso tra a e b
}

void inizializza(int g[NRIGHE][NCOLONNE]) { // volendo, nelle matrice è omissibile la prima dimensione
    for (int i=0; i<NRIGHE; i++) {
        for (int j=0; j<NCOLONNE; j++) {
            if (rnd_float (0, 1) < PROBMINA) {
                g[i][j] = 1;
            } else {
                g[i][j] = 0;
            }
        }
    }
}

void indiciColonna() {
    for (int i=0; i<NCOLONNE + 2; i++) {
        printf (" ");
    }
    for (int i=0; i<NCOLONNE ; i++) {
        printf ("%c ", 'a' + i);
    }
}

void bordoOrizzontale() {
    for (int i=0; i<NCOLONNE; i++) {
        printf (" ");
    }
    for (int i=0; i<NCOLONNE*2 + 3; i++) {
        printf ("-");
    }

    printf ("\n");
}

int mineAdiacenti(int g[NRIGHE][NCOLONNE], int r, int c) {
    int cnt = 0;

    for (int i=r-1; i<=r+1; i++) {
        for (int j=c-1; j<=c+1; j++) {
            // controlla che non sia al bordo
            if ((i >= 0 && i < NRIGHE) && (j >= 0 && j < NCOLONNE)) {
                if (g[i][j] == 1) {
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

void stampa(int g[NRIGHE][NCOLONNE]) {
    int cnt;

    bordoOrizzontale();

    for (int i=0; i<NRIGHE; i++) {
        printf ("%2d -> | ", i+1);
        for (int j=0; j<NCOLONNE; j++) {
            if (g[i][j]) {
                printf ("* ");
            } else {
                cnt = mineAdiacenti(g, i, j);
                printf ("%d ", cnt);
            }
        }
        printf ("|");
        printf ("\n");
    }

    bordoOrizzontale();
    indiciColonna();
}

int main() {
    int griglia[NRIGHE][NCOLONNE];

    inizializza(griglia);
    stampa(griglia);

    printf ("\n");
    return 0;
}