#include <stdio.h>
#include <stdlib.h>

#define DIM 20

int main() {
    int n[DIM];
    // srand(time(NULL));

    for (int i=0; i<DIM; i++) {
        n[i] = rand() % 31;
    }

    for (int i=0; i<DIM; i++) {
        printf ("%d\n", n[i]);
    }

    printf ("%d", -1);

    printf ("\n");
    return 0;
}