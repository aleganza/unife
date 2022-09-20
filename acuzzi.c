#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10 // array length

// print the array
void printArray(int v[]) {
    for (int i=0; i<10; i++){
        printf("%d ", v[i]);
    };
};

void BubbleSort(int v[], int array_size) {
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i) {
        for (j = 0; j < array_size - 1 - i; ++j ) {
            if (v[j] > v[j+1]) {
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("Sorted array: ");
    printArray(v);
};

int main() {

    printf ("Program Starting...\n\n");

    int v[LEN];
    srand(time(NULL));

    // array filling
    for (int i=0; i<LEN; i++){
        v[i] = rand() % 100;
    };

    printf("Array: ");
    printArray(v);

    // sorting
    BubbleSort(v, LEN);

    printf("\n\nProgram Closing...\n");

    return 0;
}