//
//  priority_queue.c
//  data structures and algorithms
//
//  Created by Abdoulaye Dia on 20/11/2021.
//

#include "priority_queue.h"

void create_empty_priority_queue(priority_queue* pq)
{
    if(pq != NULL)
    {
        pq->elements = (int*)(malloc(sizeof(int) * DEFAULT_SIZE));
        pq->size = 0;
        pq->rear = pq->front = -1;
        pq->max = 10;
    }
}

void enqueue(priority_queue* pq, int value)
{
    if(pq != NULL)
    {
        pq->size++;
        if(pq->size <= pq->max)
        {
            if(pq->size == 1)
                pq->front = pq->rear = 0;
            
            *(pq->elements + (pq->size - 1)) = value;
        }else{
            expand(pq);
            *(pq->elements + (pq->size - 1)) = value;
        }
        set_front(pq);
    }
}

int dequeue(priority_queue* pq)
{
    if(pq != NULL)
    {
        int frontValue = pq->elements[pq->front];
        remove_front_value(pq, frontValue);
        set_front(pq);
        return frontValue;
    }
    return -1;
}

void expand(priority_queue* pq)
{
    if(pq != NULL)
    {
        int* oldElements = pq->elements;
        int newMax = pq->max * 2;
        
        pq->elements = (int*)(malloc(sizeof(int) * newMax));
        pq->max = newMax;
        
        copy(oldElements, pq);
        
        free(oldElements);
    }
}

void copy(int* elements, priority_queue* to)
{
    if(elements != NULL && to != NULL)
    {
        for (int i = 0; i < to->size; ++i) {
            *(to->elements + i) = *(elements + i);
        }
    }
}

void remove_front_value(priority_queue* pq, int value)
{
    if(pq != NULL && pq->elements != NULL)
    {
        int findException = 0;
        for (int i = 0; i < pq->size; ++i) {
            int tempVal =*(pq->elements + i);
            if(tempVal == value && !findException)
            {
                findException = 1;
            }
            else{
                *(pq->elements + i + (findException ? -1 : 0)) = *(pq->elements + i);
            }
        }
        pq->size--;
    }
}

void set_front(priority_queue* pq)
{
    if(pq != NULL && pq->size > 0)
    {
        int max = *pq->elements;
        pq->front = 0;
        for (int i = 1; i < pq->size; ++i) {
            if(*(pq->elements + i) > max)
            {
                max = *(pq->elements + i);
                pq->front = i;
            }
        }
    }
}

void free_priority_queue(priority_queue* pq)
{
    if(pq != NULL)
    {
        free(pq->elements);
        free(pq);
    }
}

void clear_priority_queue(priority_queue* pq)
{
    if(pq != NULL && pq->size > 0)
    {
        pq->size = 0;
        pq->front = pq->rear = -1;
    }
}

void print_priority_queue(const priority_queue* pq)
{
    if(pq != NULL)
    {
        for(int i = 0; i < pq->size; ++i)
        {
            printf("%d: %d\n", i, *(pq->elements + i));
        }
    }
}
