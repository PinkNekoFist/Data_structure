#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

void createQueue(Queue *queue, int capacity);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
void add(Queue *queue, int item);
int dequeue(Queue *queue);

void createQueue(Queue *queue, int capacity)
{
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->data = malloc(sizeof(int) * capacity);
}

int isFull(Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int isEmpty(Queue *queue)
{
    return queue->front == (queue->rear + 1) % queue->capacity;
}

void add(Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

int main(void)
{
    struct Queue queue;
    createQueue(&queue, 10);
    printf("Queue is empty: %d\n", isEmpty(&queue));
    printf("Queue is full: %d\n", isFull(&queue));
    return 0;
}