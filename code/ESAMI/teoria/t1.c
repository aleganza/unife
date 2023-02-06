#include <stdio.h>

int f(int d) {
    int mat[] = {1, 8, 6, 3, 9, 7};
    int i;

    for (i=0; i<6; i++) {
        if (i == d-1) {
            return mat[i];
        }
    }

    return 0;
}

int main() {
    int i = 8;
    while (!f(--i))
        ;
    do
        printf ("%c", '0' + f(i--));
    while (f(i));
    printf ("\n");
    return 0;
}