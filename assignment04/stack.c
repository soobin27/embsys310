// stack.c
#include "stack.h"
#define STACK_SIZE 5

int* putPtr;
int* getPtr;

int StackStore[STACK_SIZE];
int StackFull;

// initialize int stack
// assign pointer to bottom of stack
void StackInit(void)
{
    putPtr = &StackStore[0];
    getPtr = &StackStore[0];
    for (int i = 0; i < STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

// calling this function checks whether stack is full, if it is full
// it will return an error, if it is not full it will return error

int Stack_Put(int data)
{
    // Check if stack is full by checking the location of put pointer
    if (putPtr == &StackFull)
    {
        return -1;
    }
    // When putPtr is at the top of stack, it stores data at the top of stack
    // then points to another int called StackFull
    if (putPtr == &StackStore[STACK_SIZE-1])
    {
        *putPtr = data;
        putPtr = &StackFull;
        return 1;
    }
    // Put data into stack and move putPtr pointer one stack location above
    else
    {
        *putPtr = data;
        putPtr++;
    }    
    return 0;
}

// calling this function checks whether stack is empty, if it is empty
// it will return an error, if it is not empty it will return the top most value
// in stack and pop off

int Stack_Get(int* data)
{
    // Check whether Stack is empty
    if (putPtr == &StackStore[0])
    {
        *data = *putPtr;
        return -1;
    }
    // Check if Stack is full, move pointer to StackStore to get top of Stack value
    if (putPtr == &StackFull)
    {
        putPtr = &StackStore[STACK_SIZE-1];
        *data = *putPtr;
        *putPtr = 0;
        return 0;
    }
    else 
    {
        putPtr--;
        *data = *putPtr;
        *putPtr = 0;
        return 0;
    }
}
        

    