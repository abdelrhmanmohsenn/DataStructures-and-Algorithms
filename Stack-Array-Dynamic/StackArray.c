
#include "StackArray.h"

stack_t *CreateStack(uint32_t maxsize, stackstatus_t *ret){
    stack_t *stack_obj=NULL;
    stack_obj = (stack_t *)malloc(sizeof(stack_t));
    if(NULL == stack_obj){
        *ret=STACK_NULL_POINTER;
    }
    else{
        stack_obj->stackarray = (void **)calloc(maxsize, sizeof(void *));
        if(NULL == stack_obj->stackarray){
            *ret=STACK_NULL_POINTER;
        }
        else{
            stack_obj->stackcount=0;
            stack_obj->stackmaxsize=maxsize;
            stack_obj->stacktop=-1;
            *ret=STACK_OK;
        }
    }
    return stack_obj;
}

stack_t *DestroyStack(stack_t *stack_obj, stackstatus_t *ret){
    if(NULL == stack_obj){
        *ret=STACK_NULL_POINTER;
    }
    else{
        free(stack_obj->stackarray);
        free(stack_obj);
        stack_obj=NULL;
        *ret=STACK_OK;
    }
    return stack_obj;
}

stackstatus_t PushStack(stack_t *stack_obj, void *itemptr){
    stackstatus_t retval=STACK_NOK;
    if(NULL == stack_obj || NULL == itemptr){
        retval=STACK_NULL_POINTER;
    }
    else{
        if(stack_obj->stackcount == stack_obj->stackmaxsize){
            retval=STACK_FULL;
        }
        else{
            stack_obj->stacktop++;
            stack_obj->stackcount++;
            stack_obj->stackarray[stack_obj->stacktop]=itemptr;
            retval=STACK_OK;
        }
    }
    return retval;
}

void *PopStack(stack_t *stack_obj, stackstatus_t *ret){
    void *itemptr=NULL;
    if(NULL == stack_obj){
        *ret=STACK_NULL_POINTER;
    }
    else{
        if(stack_obj->stackcount == 0){
            *ret=STACK_EMPTY;
        }
        else{
            itemptr=stack_obj->stackarray[stack_obj->stacktop];
            stack_obj->stacktop--;
            stack_obj->stackcount--;
            *ret=STACK_OK;
        }
    }
    return itemptr;
}

void *StackTop(stack_t *stack_obj, stackstatus_t *ret){
    void *itemptr=NULL;
    if(NULL == stack_obj){
        *ret=STACK_NULL_POINTER;
    }
    else{
        if(stack_obj->stackcount == 0){
            *ret=STACK_EMPTY;
        }
        else{
            itemptr=stack_obj->stackarray[stack_obj->stacktop];
            *ret=STACK_OK;
        }
    }
    return itemptr;
}

stackstatus_t StackCount(stack_t *stack_obj, uint32_t *stack_size){
    stackstatus_t retval=STACK_NOK;
    if(NULL == stack_obj || NULL == stack_size){
        retval=STACK_NULL_POINTER;
    }
    else{
        *stack_size=stack_obj->stackcount;
        retval=STACK_OK;
    }
    return retval;
}


