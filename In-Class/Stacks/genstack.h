#include <iostream>

using namespace std;

template <class T>
class genstack
{
    public:
        genstack(int maxsize);
        ~genstack();

        void push(T data);
        T pop();
        T peek(); //top();
        int isFull();
        int isEmpty();

        int top;
        int max;

        T *myArray;
};

template <class T>
genstack<T>::genstack(int maxsize)
{
    myArray = new T[maxsize];
    max = maxsize;
    top = -1; //Denotes that top is empty
}

template <class T>
genstack<T>::~genstack()
{
    cout << "Object Destroyed" << endl;
    //Also need to delete the Array
}

template <class T>
void genstack<T>::push(T data)
{
    myArray[++top] = data;
    //Add checks
}

template <class T>
T genstack<T>::pop()
{
    //returns char in myArray from the top and then decrements
    return myArray[top--];

    //Implement error-checking for if myArray is empty
}

template <class T>
T genstack<T>::peek()
{

    return myArray[top];
}

template <class T>
int genstack<T>::isFull()
{
    return (top == max-1);
}

template <class T>
int genstack<T>::isEmpty()
{
    return (top == -1);
}

/*
    ORIGINAL genstack.h File for REFERENCE ONLY
    
    class genstack
    {
        public:
            genstack(int maxsize);
            ~genstack();

            void push(char data);
            char pop();
            char peek(); //top();
            int isFull();
            int isEmpty();

            int top;
            int max;

            char myArray;
    };
 */
