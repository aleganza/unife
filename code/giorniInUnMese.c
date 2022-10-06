// verifica quanti giorni ci sono in certo mese

#include <stdio.h>

int main() {
    int nGiorni, mese, anno;
    int bis = 0;

    printf ("Inserisci il mese (in numero): ");
    scanf("%d", &mese);

    printf ("Inserisci l'anno: ");
    scanf("%d", &anno);

    if ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0)
        bis = 1;

    if (mese == )

    switch(mese) {
        case 1: {
            nGiorni = 31;
            break;
        }
        case 2: {
            if (bis)
                nGiorni = 29;
            else
                nGiorni = 28;
            break;
        }
        case 3: {
            nGiorni = 31;
            break;
        }
        case 4: {
            nGiorni = 30;       
            break;
        }
        case 5: {
            nGiorni = 31;
            break;
        }
        case 6: {
            nGiorni = 30;
            break;
        }
        case 7: {
            nGiorni = 31;
            break;
        }
        case 8: {
            nGiorni = 31;
            break;
        }
        case 9: {
            nGiorni = 30;
            break;
        }
        case 10: {
            nGiorni = 31;
            break;
        }
        case 11: {
            nGiorni = 30;
            break;
        }
        case 12: {
            nGiorni = 31;
            break;
        }
        default: {
            printf ("Mese non valido");
            break;
        }
    }

    printf ("Il mese inserito ha %d giorni", nGiorni);

    printf("\n");
    return 0;
}