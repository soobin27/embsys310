#include "stack.h"
#define STACK_SIZE 5

// 

int StackStore[STACK_SIZE];

int* putPtr;
int* getPtr;

// pointers

void stack_init(void);
{
    putPtr* = 0;
    getPtr* = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        QueueStore[i] = '\0';
    }
}

int stack_put(int data)
{
    if (getPtr == StackStore && putPtr == &StackStore[STACK_SIZE-1])
    {
        //stack is full
        return -1;
    }
    
    if (getPtr == putPtr)
    {
        //stack is empty
        return -1;
    }
    f (getPtr == 0)
    {
        getPtr = &QueueStore[0];
    }    
    
    if (putPtr == 0 || putPtr == &QueueStore[QUEUE_SIZE-1])
    {
        putPtr = &QueueStore[0];
    }
    else
    {
        putPtr++;
    }
    
    *putPtr = data;
    return 0;
}

    

// stack.c
