
#ifndef QUEUE_DS_H
#define QUEUE_DS_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

typedef struct{
    void **queuearray;
    uint32_t queuemaxsize;
    sint32_t queuecount;
    sint32_t queuefront;
    sint32_t queuerear;
}queue_t;

typedef enum{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER
}queuestatus_t;

queue_t *queuecreate(uint32_t maxsize, queuestatus_t *ret);
queuestatus_t enqueueElement(queue_t *queue_obj, void *itemptr);
void *dequeueElement(queue_t *queue_obj, queuestatus_t *ret);
void *queuefront(queue_t *queue_obj, queuestatus_t *ret);
void *queuerear(queue_t *queue_obj, queuestatus_t *ret);
queuestatus_t queuecount(queue_t *queue_obj, uint32_t *queue_count);
queuestatus_t queuedestroy(queue_t *queue_obj);

#endif // QUEUE_DS_H
