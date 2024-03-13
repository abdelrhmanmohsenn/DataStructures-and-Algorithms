
#include "StackArray.h"

stackstatus_t stack_init(stack_t *my_stack){
    stackstatus_t retval=STACK_NOK;
    if(NULL == my_stack){
        retval=STACK_NULL_POINTER;
    }
    else{
        my_stack->stackpointer=-1;
        retval=STACK_OK;
    }
    return retval;
}

stackstatus_t stack_push(stack_t *my_stack, uint32_t value){
    stackstatus_t retval=STACK_NOK;
    if(NULL == my_stack || my_stack->stackpointer == ARRAY_MAX_SIZE-1){
        retval=STACK_NULL_POINTER;
    }
    else{
        my_stack->stackpointer++;
        my_stack->data[my_stack->stackpointer]=value;
        retval=STACK_OK;
    }
    return retval;
}

stackstatus_t stack_pop(stack_t *my_stack, uint32_t *value){
    stackstatus_t retval=STACK_NOK;
    if(NULL == my_stack || my_stack->stackpointer == -1){
        retval=STACK_NULL_POINTER;
    }
    else{
        *value=my_stack->data[my_stack->stackpointer];
        my_stack->stackpointer--;
        retval=STACK_OK;
    }
    return retval;
}

stackstatus_t stack_top(stack_t *my_stack, uint32_t *value){
    stackstatus_t retval=STACK_NOK;
    if(NULL == my_stack || my_stack->stackpointer == -1){
        retval=STACK_NULL_POINTER;
    }
    else{
        *value=my_stack->data[my_stack->stackpointer];
        retval=STACK_OK;
    }
    return retval;
}

stackstatus_t stack_size(stack_t *my_stack, uint32_t *stack_size){
    stackstatus_t retval=STACK_NOK;
    if(NULL == my_stack || NULL == stack_size){
        retval=STACK_NULL_POINTER;
    }
    else{
        *stack_size =my_stack->stackpointer+1;
        retval=STACK_OK;
    }
    return retval;
}

stackstatus_t stack_display(stack_t *my_stack){
    stackstatus_t retval=STACK_NOK;
    if(NULL == my_stack){
        retval=STACK_NULL_POINTER;
    }
    else{
        printf("elements in the stack :");
        for(int counter = my_stack->stackpointer ; counter>=0 ; counter--){
            printf("%i\t",my_stack->data[counter]);
        }
        printf("\n");
        retval=STACK_OK;
    }
    return retval;
}


