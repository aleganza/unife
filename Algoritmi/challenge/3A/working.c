#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];
int rank[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    else
        return (parent[i] = find(parent[i]));
}

void union_set(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->w - e2->w;
}

int main() {
    int N, M;
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    fscanf(input, "%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        fscanf(input, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    fclose(input);

    qsort(edges, M, sizeof(Edge), compare);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalCost = 0;
    int edgesUsed = 0;

    for (int i = 0; i < M && edgesUsed < N - 1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            union_set(edges[i].u, edges[i].v);
            totalCost += edges[i].w;
            edgesUsed++;
        }
    }

    fprintf(output, "%d\n", totalCost);
    fclose(output);

    return 0;
}
