// Priority Queue Implementation Using Min-Heap
// 140.116.245.97
#include <stdio.h>
typedef struct Heap
{
    int data[100];
    size_t size;
} Heap;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct Heap *heap, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < heap->size && heap->data[l] < heap->data[smallest])
    {
        smallest = l;
    }
    if (r < heap->size && heap->data[r] < heap->data[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&heap->data[i], &heap->data[smallest]);
        heapify(heap, smallest);
    }
}

void push(struct Heap *heap, int x)
{
    int i = heap->size++;
    heap->data[i] = x;
    while (i != 0 && heap->data[(i - 1) / 2] > heap->data[i])
    {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void delete(struct Heap *heap, int x)
{
    for (size_t i = 0; i < heap->size; i++)
    {
        if (heap->data[i] == x)
        {
            heap->data[i] = heap->data[--heap->size];
            heapify(heap, i);
            break;
        }
    }
}

void print(struct Heap *heap)
{
    for (size_t i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main(void)
{
    char s[100];
    Heap heap = {.size = 0};
    while (scanf("%s", s) != EOF)
    {
        int x;
        if (s[0] == 'i')
        {
            scanf("%d", &x);
            push(&heap, x);
        }
        else if (s[0] == 'd')
        {
            scanf("%d", &x);
            delete (&heap, x);
        }
    }
    print(&heap);
    return 0;
}