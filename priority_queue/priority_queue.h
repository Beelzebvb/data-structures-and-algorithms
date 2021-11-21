//
//  priority_queue.h
//  data structures and algorithms
//
//  Created by Abdoulaye Dia on 20/11/2021.
//

#ifndef priority_queue_h
#define priority_queue_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 10

typedef struct priority_queue priority_queue;

struct priority_queue
{
    int* elements;
    int max, size, front, rear;
};

void create_empty_priority_queue(priority_queue* pq);

void enqueue(priority_queue* pq, int value);
int dequeue(priority_queue* pq);
void expand(priority_queue* pq);
void copy(int* elements, priority_queue* to);
void remove_front_value(priority_queue* pq, int value);
void set_front(priority_queue* pq);

void free_priority_queue(priority_queue* pq);
void clear_priority_queue(priority_queue* pq);

void print_priority_queue(const priority_queue* pq);

#endif /* priority_queue_h */
