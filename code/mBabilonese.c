// radice quadrata di un numero

#include <stdio.h>
#include <math.h>

float media (float x, float n) {
    return (x + n / x) / 2.0;
}

float radq (float n) {
    float x = 1.0;

    // metodo babilonese
    while (fabsf(x * x - n) / n > 1e-5) {
        // x = (x + n / x) / 2.0;
        x = media (x, n);
    }

    return x;
}

int main() {
    float n;

    printf ("Inserisci un numero: ");
    scanf ("%f", &n);

    if (n > 0) {
        printf ("La radice quadrata di %n vale %0.2f", n, radq (n));
    } else {
        printf ("Il numero inserito e' negativo");
    }

    printf("\n");
    return 0;
}