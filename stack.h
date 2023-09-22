#ifndef STACK_H
#define STACK_H


#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#define STACK_SIZE 100

typedef uint8_t byte;
typedef uint64_t pointer;

typedef enum
{
    INS_NOP = 0,
    INS_PUSH,
    INS_POP,
    INS_ADD,
    INS_SUB,
    INS_MUL,
    INS_DIV,
    INS_MOD,
    INS_LOAD,
    INS_STORE,
    INS_EQ,
    INS_NEQ,
    INS_JMP,
    INS_HALT,    
}   INS;

typedef struct instruction {
    INS instruction;
    byte operand;
} instruction;




typedef struct stack {
    byte stack[STACK_SIZE];
    pointer stack_pointer;
    pointer size;
    int halt;
} stack;


stack stack_init(void);
void stack_halt(stack *s);
void stack_push(stack *s, byte value);
void stack_pop(stack *s);
void stack_add(stack *s);
void stack_dump(stack *s);


#endif