#include <stdio.h>
#include <stdlib.h>
typedef struct Set
{
    int *data;
    size_t size;
} Set;

typedef struct Queue
{
    int *data;
    size_t size;
} Queue;

void bfs(int **map, int m, Set *set, Queue *queue, int start)
{
    set->data[start] = 1;
    set->size++;
    queue->data[queue->size++] = start;
    size_t q_begin = 0;
    for (size_t q_begin = 0; q_begin < queue->size; q_begin++)
    {
        printf("%d ", queue->data[q_begin] + 1);
        for (size_t i = 0; i < m; i++)
        {
            if (map[queue->data[q_begin]][i] == 1 && set->data[i] == 0)
            {
                set->data[i] = 1;
                set->size++;
                queue->data[queue->size++] = i;
            }
        }
    }
    printf("\n");
    return;
}

int main(void)
{
    int m;
    scanf("%d", &m);
    Set set = {.data = malloc(sizeof(int) * m), .size = 0};
    Queue queue = {.data = malloc(sizeof(int) * m), .size = 0};

    int **map = malloc(sizeof(int *) * m);
    for (size_t i = 0; i < m; i++)
    {
        map[i] = malloc(sizeof(int) * m);
        for (size_t j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    bfs(map, m, &set, &queue, 0);
    return 0;
}