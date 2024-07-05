#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    unsigned int max_size;
    int *content;
};

struct stack* make_stack(unsigned int max_size)
{
    struct stack *stack = (struct stack*)malloc(sizeof(struct stack));
    stack->max_size = max_size;
    stack->top = -1;
    stack->content = (int*)malloc(stack->max_size * sizeof(int));
    return stack;
}

int is_full(struct stack* stack)
{
    return stack->top == stack->max_size - 1;
}

int is_empty(struct stack* stack)
{
    return stack->top == -1;
}

void push(struct stack* stack, int val)
{
    if (!is_full(stack)) {
        stack->content[++stack->top] = val;
    } else {
        perror("Error: pushing value in full stack.");
        exit(-1);
    }
}

int pop(struct stack* stack)
{
    if (!is_empty(stack)) {
        return stack->content[stack->top--];
    } else {
        perror("Error: popping value from empty stack.");
        exit(-2);
    }
}

int peek(struct stack* stack)
{
    if (!is_empty(stack)) {
        return stack->content[stack->top];
    } else {
        perror("Error: getting peek value from empty stack.");
        exit(-3);
    }
}

void delete(struct stack* stack)
{
    free(stack->content);
    free(stack);
}

int histogram_area(int histogram[], int N)
{
    struct stack* stack = make_stack(N);
    int max_area = 0;
  
    int i = 0;
    while (i < N) {
        if (is_empty(stack) || histogram[peek(stack)] <= histogram[i]){
            push(stack, i++);
        } else {
            int top_index = pop(stack);
  
            int current_area = histogram[top_index] * 
                (is_empty(stack) ? i : i - peek(stack) - 1);

            if (max_area < current_area) {
                max_area = current_area;
            }
        }
    }
  
    while (!is_empty(stack)) {
        int top_index = pop(stack);

        int current_area = histogram[top_index] * 
                (is_empty(stack) ? i : i - peek(stack) - 1);
  
        if (max_area < current_area)
            max_area = current_area;
    }

    delete(stack);
  
    return max_area;
}

void uffici(FILE *in_file, FILE *out_file) {
    int N;
    fscanf(in_file, "%d", &N);

    int histogram[N];
    for (int i=0; i<N; i++) {
        fscanf(in_file, "%d", histogram+i);
    }

    fprintf(out_file, "%d", histogram_area(histogram, N));
}
  
int main(void) {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");

    if (in_file == NULL || out_file == NULL) {
        perror("io fopen");
        exit(-1);
    }

    uffici(in_file, out_file);
    
    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        perror("io fclose");
        exit(-2);
    }

    return 0;
}