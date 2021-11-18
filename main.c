#include "queue.h"

int main(int argc, char const *argv[])
{
    
    srand(time(NULL));
    
    queue *q = (queue *)(malloc(sizeof(queue)));
    
    createEmptyQueue(q);
    
    enqueue(q, rand() % 100);
    enqueue(q, rand() % 100);
    enqueue(q, rand() % 100);
    
    print_queue(q);
    
    printf("front: %d\n", peek(q));
    printf("rear: %d\n\n", rear(q));
    
    printf("dequeu: %d size: %d\n", dequeue(q), size(q));
    printf("dequeu: %d size: %d\n", dequeue(q), size(q));
    printf("dequeu: %d size: %d\n\n", dequeue(q), size(q));
    
    
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    enqueue(q, rand()%100);
    
    printf("Queue full: %s", is_full(q) ? "true" : "false");
    
    enqueue(q, rand()%100);
    
    printf("Queue full: %s", is_full(q) ? "true" : "false");
    
    clean_queue(q);
    return 0;
}
