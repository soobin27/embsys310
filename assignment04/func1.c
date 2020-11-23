// Assignment 04 Problem 2


// function func1 prototype
int func1 (int,int,int,int,int,int,int);
int func2 (void);

// function func1
int func1(int num0, int num1, int num2, int num3, int num4, int num5, int num6)
{
    int sum1;
       
    sum1 = num0 + num1 + num2 + num3 + num4 + num5, num6;

    return sum1;
    }


// function func2 adds all integers passed to this function and returns sum2
int func2(void)
{
    int sum2;
    sum2 = func1(1,2,3,4,5,6,7);
    return sum2;
}

// main function

void main(void)
{
// integer declaration
    volatile int total0;
    volatile int total1;
    
// assign return value from func2 to total
    total0 = func2();
    
    total1 = func1(1,2,3,4,5,6,7);
          
}

