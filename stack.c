#include "stack.h"

#include <stdio.h>

// Function: initStack

stack stack_init(void)
{
    stack s;
    s.halt = 0;
    s.size = STACK_SIZE;
    s.stack_pointer = 1;
    return s;
}


void stack_push(stack *s, byte value)
{
    assert(s != NULL && "Stack is NULL");
    assert(!(s->stack_pointer > s->size) && "Stack overflow");
    assert(!(s->stack_pointer <= 0) && "Stack underflow");
    s->stack[s->stack_pointer - 1] = value;
    s->stack_pointer++;
}

void stack_pop(stack *s)
{
    assert(s != NULL && "Stack is NULL");
    assert(!(s->stack_pointer > s->size) && "Stack overflow");
    assert(!(s->stack_pointer <= 0) && "Stack underflow");
    s->stack_pointer--;
}


void stack_add(stack *s)
{
    assert(s != NULL && "Stack is NULL");
    assert(!(s->stack_pointer > s->size) && "Stack overflow");
    assert(!(s->stack_pointer <= 0) && "Stack underflow");
    s->stack_pointer--;
    s->stack[s->stack_pointer - 2] += s->stack[s->stack_pointer - 1];
}


void stack_halt(stack *s)
{
    assert(s != NULL && "Stack is NULL");
    s->halt = 1;
}


void stack_dump(stack *s)
{
    assert(s != NULL && "Stack is NULL");
    printf("Stack dump:\n");
    for (uint64_t i = 0; i < s->stack_pointer; i++)
    {
        printf("%lu: %i\n", i, s->stack[i]);
    }
    printf("Stack pointer: %lu\n", s->stack_pointer);
    printf("Stack size: %lu\n", s->size);
    printf("Stack halt: %d\n", s->halt);
}


void stack_instruction_create(stack *s, instruction ins)
{
    assert(s != NULL && "Stack is NULL");
    assert(s->stack_pointer < s->size && "Stack overflow");

    switch (ins.instruction)
    {
        case INS_NOP:
            break;
        case INS_PUSH:
            stack_push(s, ins.operand);
            break;
        case INS_POP:
            stack_pop(s);
            break;
        case INS_ADD:
            stack_add(s);
            break;
        case INS_SUB:
            stack_sub(s);
            break;
        case INS_MUL:
            stack_mul(s);
            break;

        case INS_DIV:
            stack_div(s);
            break;

        case INS_MOD:
            stack_mod(s);
            break;
        
        case INS_LOAD:
            stack_load(s);
            break;
        
        case INS_STORE:
            stack_store(s);
            break;
        
        case INS_EQ:
            stack_eq(s);
            break;
        
        case INS_NEQ:
            stack_neq(s);
            break;
        case INS_JMP:
            stack_jmp(s);
            break;
        case INS_HALT:
            stack_halt(s);
            break;
        default:
            assert(0 && "Unknown instruction");
            break;
    }

}