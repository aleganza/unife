/* 
- Leggere da tastiera due numeri interi, n ≤100 e k ≤ n.
- Successivamente prendere in ingresso un array di interi di dimensione n, compresi tra 0 e k - 1.
- Sviluppare una funzione che trovi il valore che si ripete più volte nell’array ed il numero di ripetizioni.
    Implementare almeno una funzione occorrenze che abbia almeno come parametro l’array inserito e che calcoli
    l’elemento che si ripete più volte e il numero di occorrenze (poiché una funzione può avere solamente un valore
    di ritorno, uno dei due valori deve essere passato per riferimento...).
- Per esempio, per n=12, k = 10 e arr = {2, 2, 2, 0, 2, 0, 2, 8, 0, 9, 2, 3}, la funzione calcola 2 (elemento che si ripete
    più volte) e 6 (numero di occorrenze). Come si può sfruttare il fatto che il numero di interi sia compreso tra 0 e k -
    1, per aumentare la velocità di esecuzione? 
*/

#include <stdio.h>

void generaArray(int *arr, int dim, int limite) {
    for (int i=0; i<dim; i++) {
        do{
            printf ("Inserire cella %d: ", i);
            scanf ("%d", (arr+i));
        } while (*(arr+i) < 0 || *(arr+i) > limite-1);
    }
}

void stampaArray(int *arr, int dim) {
    for (int i=0; i<dim; i++) {
        printf ("%d ", *(arr+i));
    }
}

void occorrenze(int *arr, int dim, int limite, int *rip, int *nOcc) {
    int cnt = 0;

    for (int i=0; i<dim; i++) {
        // trovo le occorrenze
        for (int j=i; j<dim; j++) {
            if (*(arr+i) == *(arr+j)) {
                cnt++;
            }
        }

        // cerco se l'occorrenza è maggiore
        if (i != 0) {
            if (cnt > *nOcc) {
                *rip = *(arr+i);
                *nOcc = cnt;
            }
        } else {
            *rip = *(arr+i);
            *nOcc = cnt;
        }

        cnt = 0;
    }
}

int main(int argc, char **argv) {
    int n, k, rip, nOcc;

    do {
        printf ("Inserire n (n <= 100): ");
        scanf ("%d", &n);
    } while (n > 100);

    do {
        printf ("\nInserire k (k <= n): ");
        scanf ("%d", &k);
    } while (k > n);

    int numeri[n];
    generaArray(numeri, n, k);
    stampaArray(numeri, n);

    // trovo le occorrenze
    occorrenze (numeri, n, k, &rip, &nOcc);
    printf ("{%d} trovata %d volte", rip, nOcc);

    printf ("\n");
    return 0;
}