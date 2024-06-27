#include <stdio.h>
#include <stdlib.h>

#define MAXN 2000000

// Funzione per trovare l'area del più grande rettangolo in un istogramma
int maxRectangleInHistogram(int hist[], int n) {
    int max_area = 0; // Inizializzare il massimo dell'area
    int tp; // Per memorizzare l'indice dell'elemento superiore della pila
    int area_with_top; // Area con l'elemento in cima come l'elemento più basso del rettangolo

    int stack[MAXN]; // Pila per memorizzare gli indici
    int top = -1; // Inizializzare la pila vuota

    int i = 0;
    while (i < n) {
        // Se questo elemento è più alto del bar in cima alla pila, push it
        if (top == -1 || hist[stack[top]] <= hist[i])
            stack[++top] = i++;
        else {
            // Pop l'elemento più alto
            tp = stack[top--];

            // Calcola l'area con hist[tp] come l'elemento più basso del rettangolo
            area_with_top = hist[tp] * (top == -1 ? i : i - stack[top] - 1);

            // Aggiorna il massimo dell'area, se necessario
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Ora pop gli elementi rimanenti e calcola l'area con ogni elemento come il più basso del rettangolo
    while (top != -1) {
        tp = stack[top--];
        area_with_top = hist[tp] * (top == -1 ? i : i - stack[top] - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        fprintf(stderr, "Errore nell'apertura del file di input.\n");
        return 1;
    }

    int M;
    fscanf(inputFile, "%d", &M);

    int offices[MAXN];
    for (int i = 0; i < M; i++) {
        fscanf(inputFile, "%d", &offices[i]);
    }

    fclose(inputFile);

    int max_area = maxRectangleInHistogram(offices, M);

    fprintf(outputFile, "%d\n", max_area);
    fclose(outputFile);

    return 0;
}
