#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct Queue
{
    int size;
    int length;
    int top;
    int tail;
    int* array;
};

struct Queue* constructor(int size)
{
    struct Queue* myQueue;
    myQueue = malloc(sizeof(struct Queue));
    myQueue->array = malloc(sizeof(int) * size);
    myQueue->top = NULL;
    myQueue->tail = NULL;
    myQueue->length = NULL;
    myQueue->size = size;

    return myQueue;
}

int destructor(struct Queue* myQueue)
{
    free(myQueue->array);
    free(myQueue);
    return 1;
}

int isEmpty(struct Queue* myQueue)
{
    if(myQueue->length == 0)
    {
        return 1;
    }
    return 0;
}

int enqueue(struct Queue* myQueue, int value)
{
    myQueue->array[myQueue->tail] = value;
    myQueue->tail += 1;
    if(myQueue->tail == myQueue->length)
    {
        myQueue->tail = 0;
    }
    return 1;
}

int dequeue(struct Queue* myQueue)
{
    int temp;
    temp = myQueue->array[myQueue->top];
    myQueue->top += 1;
    if(myQueue->top == myQueue->length)
    {
        myQueue->top = 0;
    }
    return temp;
}
