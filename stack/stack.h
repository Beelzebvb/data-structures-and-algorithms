#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MAX 10

typedef struct stack stack;

struct stack;
void createEmptyStack(stack *s);
void createStack(stack *s, int size);
int is_full(const stack *s);
int is_empty(const stack *s);
int push(stack *s, int value);
int pop(stack *s);
int top(const stack *s);
int expand(stack *s);
int copy(int *data, int *arrToCopy, int size);

int clear(stack *s);

void print_stack(const stack *s);
int clean_stack(stack *s);

struct stack
{
    int *elements;
    int size;
    int max;
    int top;
};

void createEmptyStack(stack *s)
{
    s->elements = (int *)malloc(sizeof(int) * DEFAULT_MAX);
    s->size = 0;
    s->max = DEFAULT_MAX;
    s->top = -1;
}

void createStack(stack *s, int max)
{
    if (max < 0)
        return;

    s->elements = (int *)malloc(sizeof(int) * max);
    s->max = max;
    s->size = 0;
    s->top = -1;
}

int is_full(const stack *s)
{
    return s->size >= s->max;
}

int is_empty(const stack *s)
{
    return s->size == 0;
}

int push(stack *s, int value)
{
    if (s != NULL)
    {
        if (!is_full(s))
        {
            s->elements[++(s->top)] = value;
            s->size++;
        }
        else
        {
            expand(s);
        }
        return 1;
    }
    return -1;
}

int pop(stack *s)
{
    if (s != NULL && s->size > 0)
    {
        s->top--;
        s->size--;
        return 1;
    }

    return -1;
}

int top(const stack *s)
{
    if (s != NULL)
        return s->elements[s->top];
    return -1;
}

int expand(stack *s)
{
    if (s == NULL)
        return -1;

    int *oldElements = s->elements;
    int newMax = s->max * 2;

    s->elements = (int *)(malloc(sizeof(int) * newMax));
    copy(oldElements, s->elements, s->max);
    s->max = newMax;

    free(oldElements);
    return 1;
}

int copy(int *data, int *arrToCopy, int size)
{
    if (data == NULL || arrToCopy == NULL)
        return -1;

    for (size_t i = 0; i < size; i++)
    {
        *(arrToCopy + i) = *(data + i);
    }

    return 1;
}

int clear(stack *s)
{
    if (s == NULL || s->size == 0)
        return -1;

    s->top = -1;
    s->size = 0;
}

void print_stack(const stack *s)
{
    if (s == NULL || s->size == 0)
        printf("Invalid stack\n");
    else
    {
        printf("size: %d\nmax: %d\n\n", s->size, s->max);
        for (size_t i = 0; i < s->size; i++)
        {
            printf("%d : %d\n", i, s->elements[i]);
        }
    }
}

int clean_stack(stack *s)
{
    if (s == NULL)
        return -1;

    free(s->elements);
    free(s);
}