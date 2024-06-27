#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int index;
  int w;
  int w_limit;
  int h;
  int area;
  int end;
} floor;

typedef struct Node {
    floor data;
    struct Node* next;
} node;

node* pushTail(node *_t, int index, int w, int w_limit, int h, int area, int end){
  node *tmp;

  if(_t == 0){    // sono in lista vuota.
    _t = malloc(sizeof(node));
    _t->data.index = index;
    _t->data.w = w;
    _t->data.w_limit = w_limit;
    _t->data.h = h;
    _t->data.area = area;
    _t->data.end = end;
    _t->next = 0;
    return(_t);
  }
  else{   // ho una lista con almeno un nodo
    tmp = _t;
    while(tmp->next != 0)
        tmp = tmp->next;
    
    tmp->next = malloc(sizeof(node));
    tmp = tmp->next;
    tmp->data.index = index;
    tmp->data.w = w;
    tmp->data.w_limit = w_limit;
    tmp->data.h = h;
    tmp->data.area = area;
    tmp->data.end = end;
    tmp->next = 0;
    return(_t);
  }
}

void updateFloors(node *head, int index, int w, int w_limit, int h, int area, int* max_area) {
  node *tmp;
  node *prev = NULL;
  int maybe_new_area;

  if (head != 0) {
    tmp = head;

    while (tmp != 0 && tmp->next != 0) {
      if (tmp->data.end == 0) {
        if (w != 0) {
          tmp->data.h++;

          if (w < tmp->data.w_limit) {
            tmp->data.w_limit = w;
          }

          maybe_new_area = tmp->data.h * tmp->data.w_limit;
          if (maybe_new_area > tmp->data.area) {
            tmp->data.area = maybe_new_area;
          }
        } else {
          tmp->data.end = 1;
        }
      } else {
        if (prev != NULL) {
          prev->next = tmp->next;
        } else {
          head = tmp->next;
        }

        node *toDelete = tmp;
        tmp = tmp->next;
        free(toDelete);
        continue;
      }

      prev = tmp;
      tmp = tmp->next;

      if(maybe_new_area > *max_area) {
        *max_area = maybe_new_area;
      }
    }
  }
}

void showList(node *_t) {
    node *tmp;
    if(_t == 0){
        printf("Empty list.\n");
    }
    else{
        tmp = _t;
        while(tmp != 0){
            printf("%d index\n", tmp->data.index);
            printf("%d w\n", tmp->data.w);
            printf("%d w_limit\n", tmp->data.w_limit);
            printf("%d h\n", tmp->data.h);
            printf("%d area\n\n", tmp->data.area);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void freeList(node *head) {
    node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {

  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("open files");
    return -1;
  }

  node *head;
  head = 0; 

  int M;
  fscanf(input, "%d", &M);
  
  int max_area = 0; 
  int maybe_new_area, w, i, j;

  for(i=0; i<M; i++) {
    // initialize i-floor
    fscanf(input, "%d", &w);
    head = pushTail(head, i, w, w, 1, w, 0);

    updateFloors(head, i, w, w, 1, w, &max_area);
  }

  // showList(head);
  fprintf(output, "%d", max_area);

  fclose(input);
  fclose(output);

  freeList(head);

  return 0;
}
