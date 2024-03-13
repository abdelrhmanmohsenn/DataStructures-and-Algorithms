
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define ARRAY_MAX_SIZE 5

typedef struct{
    uint32_t data[ARRAY_MAX_SIZE];
    sint32_t stackpointer;
}stack_t;

typedef enum{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}stackstatus_t;

stackstatus_t stack_init(stack_t *my_stack);
stackstatus_t stack_push(stack_t *my_stack, uint32_t value);
stackstatus_t stack_pop(stack_t *my_stack, uint32_t *value);
stackstatus_t stack_top(stack_t *my_stack, uint32_t *value);
stackstatus_t stack_size(stack_t *my_stack, uint32_t *stack_size);
stackstatus_t stack_display(stack_t *my_stack);

#endif // STACK_ARRAY_H
