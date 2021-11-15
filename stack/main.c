#include "stack.h"

int main(int argc, char const *argv[])
{

    struct stack *s = (stack *)malloc(sizeof(stack));
    createEmptyStack(s);

    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);

    print_stack(s);

    printf("\ntop: %d\n", top(s));

    clean_stack(s);
    return 0;
}