#include <stdio.h>

int main () {
    int scelta, scelta2;
    float km, mig, kg, lb;

    do {
        printf ("\nDesideri fare una conversione di massa o di lunghezza? (1/0, altro numero per uscire)");
        scanf ("%d", &scelta);

        if (scelta) {
            // massa
            printf ("Digitare:\n1. Chili -> Libbre\n0. Libbre -> Chili");
            scanf ("%d", &scelta2);

            if (scelta2) {
                printf ("Inserire la misura in chili:\n");
                scanf ("%f", &kg);

                lb = kg * 2.205;
                printf ("%f chili equivalgono a %f libbre", kg, lb);
            } else {
                printf ("Inserire la misura in libbre:\n");
                scanf ("%f", &lb);

                kg = lb / 2.205;
                printf ("%f libbre equivalgono a %f chili", lb, kg);
            }

        } else if (!scelta) {
            // lunghezza
            printf ("Digitare:\n1. Chilometri -> Miglia\n0. Miglia -> Chilometri");
            scanf ("%d", &scelta2);

            if (scelta2) {
                printf ("Inserire la misura in chilometri:\n");
                scanf ("%f", &km);

                mig = km * 1.609;
                printf ("%f chilometri equivalgono a %f miglia", km, mig);
            } else {
                printf ("Inserire la misura in miglia:\n");
                scanf ("%f", &mig);

                km = mig / 1.609;
                printf ("%f miglia equivalgono a %f chilometri", mig, km);
            }
        }

    } while (scelta == 0 || scelta == 1);

    printf ("\n");
    return 0;
}