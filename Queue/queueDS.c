
#include "queueDS.h"

queue_t *queuecreate(uint32_t maxsize, queuestatus_t *ret){
    queue_t *queue_obj;
    queue_obj = (queue_t *)malloc(sizeof(queue_t));
    if(NULL == queue_obj){
        *ret=QUEUE_NULL_POINTER;
    }
    else{
        queue_obj->queuearray = (void **)calloc(maxsize, sizeof(void *));
        if(NULL == queue_obj->queuearray){
            *ret=QUEUE_NOK;
        }
        else{
            queue_obj->queuecount=0;
            queue_obj->queuefront=-1;
            queue_obj->queuerear=-1;
            queue_obj->queuemaxsize=maxsize;
            *ret=QUEUE_OK;
        }
    }
    return queue_obj;
}

queuestatus_t enqueueElement(queue_t *queue_obj, void *itemptr){
    queuestatus_t retval=QUEUE_NOK;
    if(NULL == queue_obj || NULL == itemptr){
        retval=QUEUE_NULL_POINTER;
    }
    else{
        if(queue_obj->queuecount == queue_obj->queuemaxsize){
            retval=QUEUE_FULL;
        }
        else{
            (queue_obj->queuerear)++;
            if(queue_obj->queuerear == queue_obj->queuemaxsize){
                queue_obj->queuerear=0;
            }
            else{/*do nothing*/}
            queue_obj->queuearray[queue_obj->queuerear]=itemptr;
            if(queue_obj->queuecount == 0){
                queue_obj->queuefront=0;
                queue_obj->queuecount=1;
            }
            else{
                queue_obj->queuecount++;
            }
            retval=QUEUE_OK;
        }
    }
    return retval;
}

void *dequeueElement(queue_t *queue_obj, queuestatus_t *ret){
    void *itemptr=NULL;
    if(NULL == queue_obj || NULL == ret){
        *ret=QUEUE_NULL_POINTER;
    }
    else{
        if(queue_obj->queuecount == 0){
            *ret=QUEUE_EMPTY;
        }
        else{
            itemptr = queue_obj->queuearray[queue_obj->queuefront];
            queue_obj->queuefront++;
            if(queue_obj->queuefront == queue_obj->queuemaxsize){
                queue_obj->queuefront=0;
            }
            else{}
            if(queue_obj->queuecount == 1){
                queue_obj->queuefront=-1;
                queue_obj->queuerear=-1;
            }
            else{}
            queue_obj->queuecount--;
            *ret=QUEUE_OK;
        }
    }
    return itemptr;
}

void *queuefront(queue_t *queue_obj, queuestatus_t *ret){
    void *itemptr;
    if(NULL == queue_obj || NULL == ret){
        *ret=QUEUE_NULL_POINTER;
    }
    else{
        if(queue_obj->queuecount == 0){
            *ret=QUEUE_EMPTY;
        }
        else{
            itemptr=queue_obj->queuearray[queue_obj->queuefront];
            *ret=QUEUE_OK;
        }
    }
    return itemptr;
}

void *queuerear(queue_t *queue_obj, queuestatus_t *ret){
    void *itemptr;
    if(NULL == queue_obj || NULL == ret){
        *ret=QUEUE_NULL_POINTER;
    }
    else{
        if(queue_obj->queuecount == 0){
            *ret=QUEUE_EMPTY;
        }
        else{
            itemptr=queue_obj->queuearray[queue_obj->queuerear];
            *ret=QUEUE_OK;
        }
    }
    return itemptr;
}

queuestatus_t queuecount(queue_t *queue_obj, uint32_t *queue_count){
    queuestatus_t retval=QUEUE_NOK;
    if(NULL == queue_obj || NULL == queue_count){
        retval=QUEUE_NULL_POINTER;
    }
    else{
        *queue_count=queue_obj->queuecount;
        retval=QUEUE_OK;
    }
    return retval;
}

queuestatus_t queuedestroy(queue_t *queue_obj){
    queuestatus_t retval=QUEUE_NOK;
    if(NULL == queue_obj){
        retval=QUEUE_NULL_POINTER;
    }
    else{
        free(queue_obj->queuearray);
        free(queue_obj);
        retval=QUEUE_OK;
    }
    return retval;
}
