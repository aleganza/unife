#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Funzione per trovare l'area del rettangolo più grande in un istogramma
int maxHistogramArea(int hist[], int n) {
    int max_area = 0;
    int stack[n];
    int top = -1;
    int i = 0;

    while (i < n) {
        if (top == -1 || hist[stack[top]] <= hist[i]) {
            stack[++top] = i++;
        } else {
            int h = hist[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            max_area = MAX(max_area, h * width);
        }
    }

    while (top != -1) {
        int h = hist[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        max_area = MAX(max_area, h * width);
    }

    return max_area;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    int M;
    fscanf(input, "%d", &M);

    int *V = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        fscanf(input, "%d", &V[i]);
    }

    // Trova l'area massima del rettangolo
    int max_area = 0;
    int hist[M + 1];
    for (int i = 0; i <= M; i++) {
        hist[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < V[i]; j++) {
            hist[j]++;
        }
        for (int j = V[i]; j < M; j++) {
            hist[j] = 0;
        }
        max_area = MAX(max_area, maxHistogramArea(hist, M));
    }

    fprintf(output, "%d", max_area);

    free(V);
    fclose(input);
    fclose(output);

    return 0;
}
