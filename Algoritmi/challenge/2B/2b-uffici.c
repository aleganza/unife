#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *content;
  int top;
  unsigned int max_size;
} Stack;

// stack functions taken by the classroom solution

Stack* make_stack(unsigned int max_size) {
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->max_size = max_size;
  stack->top = -1;
  stack->content = (int*)malloc(stack->max_size * sizeof(int));
  return stack;
}

int is_full(Stack* stack) {
  return stack->top == stack->max_size - 1;
}

int is_empty(Stack* stack) {
  return stack->top == -1;
}

void push(Stack* stack, int val) {
  if (!is_full(stack)) {
    stack->content[++stack->top] = val;
  } else {
    perror("Error: pushing value in full stack.");
    exit(-1);
  }
}

int pop(Stack* stack) {
  if (!is_empty(stack)) {
    return stack->content[stack->top--];
  } else {
    perror("Error: popping value from empty stack.");
    exit(-2);
  }
}

int peek(Stack* stack) {
  if (!is_empty(stack)) {
    return stack->content[stack->top];
  } else {
    perror("Error: getting peek value from empty stack.");
    exit(-3);
  }
}

void delete(Stack* stack) {
  free(stack->content);
  free(stack);
}

int pop_and_get_area(Stack* stack, int floors[], int i) {
  int top_index = pop(stack);
  return floors[top_index] * (is_empty(stack) ? i : i - peek(stack) - 1);
}

int get_max_area(FILE *input, FILE *output) {
  int N;
  fscanf(input, "%d", &N);

  int floors[N];
  for (int i=0; i<N; i++) {
      fscanf(input, "%d", &floors[i]);
  }

  Stack *stack = make_stack(N);
  int max_area = 0,
      i = 0;

  while (i < N) {
    if (is_empty(stack) || floors[peek(stack)] <= floors[i]){
      push(stack, i++);
    } else {
      int area = pop_and_get_area(stack, floors, i);

      if (max_area < area) max_area = area;
    }
  }

  while (!is_empty(stack)) {
    int area = pop_and_get_area(stack, floors, i);

    if (max_area < area) max_area = area;
  }

  delete(stack);

  return max_area;
}

int main(void) {

  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("open files");
    return -1;
  }

  int max_area = get_max_area(input, output);
  fprintf(output, "%d", max_area);

  fclose(input);
  fclose(output);

  return 0;
}