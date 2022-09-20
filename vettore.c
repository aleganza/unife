/*  
    Dato un array di 10 elementi generato casualmente riordinalo in modo decrescente.
    Successivamente genera un nuovo valore casualmente ed inseriscilo
    dentro il vettore per ordine decrescente sempre 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN 10

// print the array
void printArray(int v[]) {
    for (int i=0; i<LEN; i++){
        printf("%d ", v[i]);
    }
};

// bubble sort
void bubblesort(int v[]) {
    int i,k;
    int temp;
    for(i = 0; i<LEN-1; i++) {
        for(k = 0; k<LEN-1-i; k++) {
            if(v[k] < v[k+1]) {
                temp = v[k];
                v[k] = v[k+1];
                v[k+1] = temp;
            }
        }
    }

    printArray(v);
};

// inserts value in the array and sorts it
void insertInArray(int v[], int a) {
    int flag = 0;

    for(int i=0; i<LEN; i++) {
        if (a > v[i]) {

            // array elements shifting
            for(int j=LEN-1; j>=i; j--) {
                v[j] = v[j-1];
            }

            // inserting the value
            v[i] = a;
            break;
        }
    }

    printArray(v);
};

int main() {
    int v[LEN];
    srand(time(NULL));

    // array filling
    for (int i=0; i<LEN; i++){
        v[i] = rand() % 100;
    }

    printArray(v);
    printf("\n\n");

    bubblesort(v);
    printf("\n\n");
    
    int a;
    printf("Inserisci un valore da inserire: ");
    scanf("%d", &a);

    insertInArray(v, a);

    return 0;
}