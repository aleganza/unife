#include <stdio.h>
#include <stdlib.h>

#define DIM 31

int main(int argc, char **argv) {
    int frequenze[DIM], n;

    for (int i=0; i<DIM; i++) {
        frequenze[i] = 0;
    }

    do {
        if (n == -1) break;
            scanf ("%d", &n);
            frequenze[n]++;
    } while (1);

    for (int i=0; i<DIM; i++) {
        printf ("%d ", frequenze[i]);
    }

    printf ("\n");
    return 0;
}