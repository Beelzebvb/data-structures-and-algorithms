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
    printf("read: %d\n", rear(q));

    printf("dequeu: %d\n", dequeue(q));
    printf("dequeu: %d\n", dequeue(q));

    printf("front: %d\n", peek(q));

    clear(q);

    enqueue(q, rand() % 100);
    print_queue(q);

    printf("front: %d\n", peek(q));
    printf("read: %d\n", rear(q));

    clean_queue(q);
    return 0;
}
