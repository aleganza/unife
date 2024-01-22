/* 
    Scrivere un programma che legge da stdin una sequenza (di lunghezza
    arbitraria) di numeri interi positivi, terminata da 0, e indica, alla fine
    delal sequenza, qual è la lunghezza della massima sottosequenza di
    numeri consecutivi in ordine crescente.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int var, tmp = 0, cnt = 1, max = 1;

    printf ("Inserisci una sequenza di numeri (chiusura ciclo inserendo 0)\n");

    do {
        scanf ("%d", &var);

        // eseguo l'algoritmo solo se siamo dopo il primo numero inserito
        if (tmp) {
            // se il numero inserito è maggiore di quello precedente, aumento la sequenza, altrimenti la resetto
            if (var > tmp)
                cnt++;
            else
                cnt = 1;

            // se la sequenza attuale è maggiore della sequenza max, aggiorno la max
            if (cnt > max)
                max = cnt;
                
        }

        // salvo in tmp il numero inserito precedentemente nella sequenza
        tmp = var;
        
    } while (var != 0);

    printf ("La sequenza massima vale %d", max);

    printf ("\n");
    return 0;
}