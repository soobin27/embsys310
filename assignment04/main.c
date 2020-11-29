#include<assert.h>
#include"stack.h"

int main()
{
    
int testInt = 0;

// **************************************************************************
// Test 1: Retrieve item from an empty stack
// **************************************************************************   
// Arrange

StackInit();

// Act



// Assert

assert(-1 == Stack_Get(&testInt));


// **************************************************************************
// Test 2: Successfully retrieve an item from the stack
// ************************************************************************** 

// Arrange

StackInit();
  
// Act

Stack_Put(2020);

// Assert

assert(0 == Stack_Get(&testInt));
assert(2020 == testInt);


// **************************************************************************
// Test 3: Fill Stack, then get all items
// ************************************************************************** 

// Arrange
StackInit();
  
// Act

Stack_Put(1);
Stack_Put(2);
Stack_Put(3);
Stack_Put(4);

// Assert

// stack should be full first return value is 1
assert(1 == Stack_Put(5));
assert(0 == Stack_Get(&testInt));
assert(5 == testInt);

// stack is not full expect 0
assert(0 == Stack_Get(&testInt));
assert(4 == testInt);

assert(0 == Stack_Get(&testInt));
assert(3 == testInt);


assert(0 == Stack_Get(&testInt));
assert(2 == testInt);

assert(0 == Stack_Get(&testInt));
assert(1 == testInt);


// *******************************************************************
// Test4: Fill Stack, then put one more item, should fail
// *******************************************************************

// Arrange

StackInit();
  
// Act

Stack_Put(1);
Stack_Put(2);
Stack_Put(3);
Stack_Put(4);
Stack_Put(5);

// Assert
// return -1 when attempt is made to add more data to a full stack
assert(-1 == Stack_Put(6));

// Start retrieving from Stack
assert(0 == Stack_Get(&testInt));
assert(5 == testInt);

// stack is not full expect 0
assert(0 == Stack_Get(&testInt));
assert(4 == testInt);

assert(0 == Stack_Get(&testInt));
assert(3 == testInt);


assert(0 == Stack_Get(&testInt));
assert(2 == testInt);

assert(0 == Stack_Get(&testInt));
assert(1 == testInt);

// *******************************************************************
// Test5: Fill Stack, retrieve one item, then add item, then retrieve all
// *******************************************************************

// Arrange

StackInit();
  
// Act

Stack_Put(1);
Stack_Put(2);
Stack_Put(3);
Stack_Put(4);


// Assert

// adding last value returns a 1 
assert(1 == Stack_Put(5));

// remove one item
assert(0 == Stack_Get(&testInt));
assert(5 == testInt);

// adding item
assert(1 == Stack_Put(2020));

// remove all items
assert(0 == Stack_Get(&testInt));
assert(2020 == testInt);

assert(0 == Stack_Get(&testInt));
assert(4 == testInt);

assert(0 == Stack_Get(&testInt));
assert(3 == testInt);


assert(0 == Stack_Get(&testInt));
assert(2 == testInt);

assert(0 == Stack_Get(&testInt));
assert(1 == testInt);

// *******************************************************************
// Test6: Fill Stack, retrieve all do it twice in a row
// *******************************************************************

// Arrange
StackInit();

// Act 
Stack_Put(1);
Stack_Put(2);
Stack_Put(3);
Stack_Put(4);

// Assert
// adding last value returns a 1 
assert(1 == Stack_Put(5));

assert(0 == Stack_Get(&testInt));
assert(5 == testInt);

// stack is not full expect 0
assert(0 == Stack_Get(&testInt));
assert(4 == testInt);

assert(0 == Stack_Get(&testInt));
assert(3 == testInt);


assert(0 == Stack_Get(&testInt));
assert(2 == testInt);

assert(0 == Stack_Get(&testInt));
assert(1 == testInt);

// return -1 when attempting to get from empty stack
assert(-1 == Stack_Get(&testInt));
assert(0 == testInt);

// start filling stack again
assert(0 == Stack_Put(1));
assert(0 == Stack_Get(&testInt));
assert(1 == testInt);

assert(0 == Stack_Put(2));
assert(0 == Stack_Get(&testInt));
assert(2 == testInt);

assert(0 == Stack_Put(3));
assert(0 == Stack_Get(&testInt));
assert(3 == testInt);

assert(0 == Stack_Put(4));
assert(0 == Stack_Get(&testInt));
assert(4 == testInt);

assert(0 == Stack_Put(5));
assert(0 == Stack_Get(&testInt));
assert(5 == testInt);

return 0;
}
