#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
  int src, dest;
  long long weight;
} Edge;

typedef struct Set {
  int parent;
  int rank;
} Set;

int make_sets(Set sets[], int n_elements) {
  for (int i = 0; i < n_elements; i++) {
    sets[i].parent = i;
    sets[i].rank = 0;
  }
}

int find_set(Set sets[], int x) {
  if (sets[x].parent != x)
    sets[x].parent = find_set(sets, sets[x].parent);
  return sets[x].parent;
}

void union_set(Set sets[], int x, int y) {
  x = find_set(sets, x);
  y = find_set(sets, y);

  if (sets[x].rank > sets[y].rank) {
    sets[y].parent = x;
  } else if (sets[x].rank <= sets[y].rank) {
    sets[x].parent = y;

    if(sets[x].rank == sets[y].rank) 
      sets[y].rank++;
  }
}

int compare_edges(const void *x, const void *y) {
    long long w1 = ((const Edge *) x)->weight;
    long long w2 = ((const Edge *) y)->weight;
    return w1 > w2;
}

long long mst_kruskal(Edge* edges, int N, int M) {
  Set* sets = malloc(N * sizeof(Set));
  make_sets(sets, N);

  qsort(edges, M, sizeof(Edge), compare_edges);

  long long cost = 0;

  for (int i = 0; i < M; i++) {
    int u = edges[i].src;
    int v = edges[i].dest;

    int set_u = find_set(sets, u);
    int set_v = find_set(sets, v);

    if (set_u != set_v) {
      cost += edges[i].weight;
      union_set(sets, set_u, set_v);
    }
  }

  free(sets);
  return cost;
}

int main() {
  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("open files");
    return -1;
  }

  int N, M;
  fscanf(input, "%d %d", &N, &M);

  // setup all connecting edges
  Edge* edges = malloc(M * sizeof(Edge));
  for (int i = 0; i < M; i++) {
    fscanf(input, "%d %d %lld", &edges[i].src, &edges[i].dest, &edges[i].weight);
  }

  fprintf(output, "%lld", mst_kruskal(edges, N, M));

  free(edges);

  fclose(input);
  fclose(output);

  return 0;
}
