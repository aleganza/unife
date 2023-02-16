#include <stdio.h>
#include <stdlib.h>

int f2(int d) {
    int mat[] = {1, 8, 6, 3, 9, 7};
    int i;

    for (i=0; i<6; i++) {
        if (i == d-1) {
            return mat[i];
        }
    }

    return 0;
}

int f(int d) {
    int mat[] = {1, 8, 6, 3, 9, 7};
    int i;

    for (i=0; i<6; i++) {
        if (d + i == 6) {
            return mat[i];
        }
    }

    return 0;
}

int main() {
    // int a = 0, i[] = {1, 1, 1};
    // while (a < 2)
    //     i[a] = f(++a);

    // for (i[0] = 2; i[0] >= 0; i[0]--) {
    //     printf ("%d ", i[i[0]]);
    // }

    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 1;
    while (i < 7) {
        printf ("%c", *((char*) ((int*)s + i)));
        i += f(i) ? f(i) : 1;
    }

    printf ("\n");
    return 0;
}