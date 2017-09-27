#include <iostream>
#include "genstack.h"

using namespace std;

genstack::genstack(int maxsize)
{
    myArray = new char[maxsize];
    max = maxsize;
    top = -1; //Denotes that top is empty
}

genstack::~genstack()
{
    cout << "Object Destroyed" << endl;
    //Also need to delete the Array
}

void genstack::push(char data)
{
    myArray[++top] = data;
    //Add checks
}

char genstack::pop()
{
    //returns char in myArray from the top and then decrements
    return myArray[top--];

    //Implement error-checking for if myArray is empty
}

char genstack::peek()
{

    return myArray[top];
}

int genstack::isFull()
{
    return (top == max-1);
}

int genstack::isEmpty()
{
    return (top == -1);
}