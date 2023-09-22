#include <stdio.h>

#include "stack.h"


int main(int argc, char const *argv[])
{
    stack s = stack_init();


    stack_push(&s, 1);
    //stack_push(&s, 2);
    //stack_add(&s);
    stack_dump(&s);   

    return 0;
}
