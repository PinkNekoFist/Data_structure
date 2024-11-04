#include <stdlib.h>
typedef struct Stack
{
    int *data;
    int top;
    int capacity;
} Stack;

void createStack(Stack *stack, int capacity);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);

void createStack(Stack *stack, int capacity)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = malloc(sizeof(int) * capacity);
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->data[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top--];
}

int main(void)
{
    struct Stack stack;
    createStack(&stack, 10);
    return 0;
}