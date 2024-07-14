#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int num_vertices;
    Node** adj_lists;
    int* color; // -1 white, 0 grey, 1 black
    int* group; // -1 not assigned, 0 first group, 1 second group
} Graph;

// long functions, better list them below main
Node* create_node(int v);
Graph* create_graph(int vertices);
void add_edge(Graph* graph, int src, int dest);
int is_bipartite(Graph* graph, int src);
void free_graph(Graph* graph);

int main() {

  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("open files");
    return -1;
  }

  int N, M;
  fscanf(input, "%d %d", &N, &M);

  Graph* graph = create_graph(N);

  // for each rivality, add the edges to the graph
  for (int i = 0; i < M; i++) {
      int src, dest;
      fscanf(input, "%d %d", &src, &dest);
      add_edge(graph, src, dest);
      add_edge(graph, dest, src);
  }

  // assuming the graph is bipartite, scroll through not visited nodes
  int result = 1;
  for (int i = 0; i < N; i++) {
    if (graph->color[i] == -1) {
      if (!is_bipartite(graph, i)) {
        result = 0;
        break;
      }
    }
  }

  if (result) {
    fprintf(output, "TRUE");
  } else {
    fprintf(output, "FALSE");
  }

  free_graph(graph);

  fclose(input);
  fclose(output);

  return 0;
}

Node* create_node(int v) {
  Node* new_node = malloc(sizeof(Node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

Graph* create_graph(int vertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->num_vertices = vertices;
  graph->adj_lists = malloc(vertices * sizeof(Node*));
  graph->color = malloc(vertices * sizeof(int));
  graph->group = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; i++) {
    graph->adj_lists[i] = NULL;
    graph->color[i] = -1;
    graph->group[i] = -1;
  }

  return graph;
}

void add_edge(Graph* graph, int src, int dest) {
  Node* new_node = create_node(dest);

  // link the new edge to the src adjacence list
  new_node->next = graph->adj_lists[src];
  graph->adj_lists[src] = new_node;
}

int is_bipartite(Graph* graph, int src) {
  int* queue = malloc(graph->num_vertices * sizeof(int));
  int front = 0;
  int rear = 0;
  queue[rear++] = src;
  graph->color[src] = 0;
  graph->group[src] = 0;

  while (front < rear) {
    // get first queue node adjacence list
    int u = queue[front++];
    Node* list = graph->adj_lists[u];

    // scroll through u adjacents
    while (list) {
      int v = list->vertex;

      if (graph->color[v] == -1) {
        graph->color[v] = 0;
        graph->group[v] = 1 - graph->group[u];
        queue[rear++] = v;
      } else if (graph->group[v] == graph->group[u]) {
        // found an adjacent node of the same group -> graph not bipartite
        free(queue);
        return 0;
      }

      list = list->next;
    }

    graph->color[u] = 1;
  }

  free(queue);
  return 1;
}

void free_graph(Graph* graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    Node* temp = graph->adj_lists[i];
    while (temp) {
      Node* next = temp->next;
      free(temp);
      temp = next;
    }
  }
  free(graph->adj_lists);
  free(graph->color);
  free(graph->group);
  free(graph);
}
