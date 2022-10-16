#include <stdio.h>

int main () {
    int div = 0;

    for (int i=1; i<=10000; i++) {
        for (int j=1; j<i; j++) {
            if (i % j == 0) {
                div += j;
            }
        }

        if (i == div) {
            printf ("%d\n", div);
        }
        
        div = 0;

    }
}