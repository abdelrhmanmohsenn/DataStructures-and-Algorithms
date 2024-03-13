
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include "platforms_types.h"

typedef struct{
    void **stackarray;
    uint32_t stackmaxsize;
    sint32_t stackcount;
    sint32_t stacktop;
}stack_t;

typedef enum{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}stackstatus_t;

stack_t *CreateStack(uint32_t maxsize, stackstatus_t *ret);
stack_t *DestroyStack(stack_t *stack_obj, stackstatus_t *ret);
stackstatus_t PushStack(stack_t *stack_obj, void *itemptr);
void *PopStack(stack_t *stack_obj, stackstatus_t *ret);
void *StackTop(stack_t *stack_obj, stackstatus_t *ret);
stackstatus_t StackCount(stack_t *stack_obj, uint32_t *stack_size);


#endif // STACK_ARRAY_H

