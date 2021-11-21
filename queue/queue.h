#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_SIZE 10

struct queue;
typedef struct queue queue;

int createEmptyQueue(queue *q);
int enqueue(queue *q, int val);
int dequeue(queue *q);
int is_full(queue *q);
int is_empty(queue *q);
int peek(queue *q);
int rear(queue *q);
int size(const queue* q);

int copy(int *arr, int *data, int size);
int expand(queue *q);
int clear_queue(queue *q);

void clean_queue(queue *q);
void print_queue(queue *q);

struct queue
{
    int *elements;
    int rear, front;
    int size, max;
};

int createEmptyQueue(queue *q)
{
    if (q == NULL)
        return -1;

    
    q->elements = (int *)(malloc(sizeof(int) * DEFAULT_SIZE));
    q->front = q->rear = -1;
    q->size = 0;
    q->max = DEFAULT_SIZE;
    
    return 1;
}

int enqueue(queue *q, int val)
{
    if (q != NULL)
    {
        q->rear++;
        q->size++;
        
        if(q->front == -1)
            q->front++;
        
        if(q->size > q->max)
            expand(q);
        
        q->elements[q->rear] = val;
        
        return 1;
    }
    return -1;
}

int dequeue(queue *q)
{
    if (q != NULL ){
        if(q->size > 1){
            q->size--;
            return q->elements[++q->front];
        }
        clear_queue(q);
    }
    return -1;
}

int is_full(queue *q)
{
    return q != NULL && q->size == q->max;
}

int is_empty(queue *q)
{
    return q != NULL && q->size == 0;
}

int peek(queue *q)
{
    if (q == NULL || q->front == -1)
        return -1;
    
    return q->elements[q->front];
}

int rear(queue *q)
{
    if (q == NULL || q->rear == -1)
        return -1;
    
    return q->elements[q->rear];
}

int size(const queue* q)
{
    if(q != NULL)
        return q->size;
    
    return -1;
}

int copy(int *arr, int *data, int size)
{
    
    if (arr == NULL || data == NULL || size < 0)
        return -1;
    
    for (size_t i = 0; i < size; i++)
    {
        *(arr + i) = *(data + i);
    }
    return 1;
}

int expand(queue *q)
{
    if (q == NULL)
        return -1;
    
    int *oldElements = q->elements;
    int newMax = q->max * 2;
    
    q->elements = (int *)(malloc(sizeof(int) * newMax));
    
    copy(q->elements, oldElements, q->max);
    
    q->max = newMax;
    
    free(oldElements);
    return 1;
}

int clear_queue(queue *q)
{
    if (q == NULL)
        return -1;
    
    q->size = 0;
    q->front = q->rear = -1;
    return 1;
}

void clean_queue(queue *q)
{
    free(q->elements);
    free(q);

}
void print_queue(queue *q)
{
    if (q == NULL)
    {
        printf("Invalid queue");
        return;
    }
    
    if (is_empty(q))
    {
        printf("Empty queue");
    }
    else
    {
        printf("\nmax: %d\nsize: %d\nfront: %d, rear: %d\n\n", q->max, q->size, q->front, q->rear);
        for (int i = q->front; i < q->size; i++)
        {
            printf("%d : %d\n", i, *(q->elements + i));
        }
    }
}
