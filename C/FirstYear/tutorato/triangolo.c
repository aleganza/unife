#include <stdio.h>

// ritorna il maggiore tra tre numeri
// int max (int a, int b, int c) {
//     if (a >= b && a >= c) return a;
//     if (b >= a && b >= c) return b;
//     if (c >= a && c >= b) return c;
// }

// trova se un lato è minore della somma degli altri due
int lessThanSum (int l, int s) {
    if (l < s) return 1;
    else return 0;
}

// dati 3 lati ritorna se si può trattare di un triangolo o no
int isTriangolo (int l1, int l2, int l3) {
    if (lessThanSum (l1, l2+l3) && lessThanSum (l2, l1+l3) && lessThanSum (l3, l1+l2)) return 1;
}



int main () {
    int l1, l2, l3,
        max;

    printf ("Inserire lato 1: ");
    scanf ("%d", l1);

    printf ("Inserire lato 2: ");
    scanf ("%d", l2);

    printf ("Inserire lato 3: ");
    scanf ("%d", l3);

    if (isTriangolo) {

    } else {
        printf ("I dati inseriti non possono appartenere ai lati di un triangolo");
    }

    // DA FINIRE
    
    printf ("\n");
    return 0;
}