#include <iostream>
#include <stack>
#include <string>

using namespace std;

template<class T> //template class 

class GenStack
{
	private:
		T *baseArray; //array used for T
		T *tempArray; //temporary array for memory allocation

		int max; //max array size
		int front; //keeps track of positioning

	public:
		GenStack(int maxSize);
		~GenStack();

		void push(T data);
		T pop();
		T peek();

		int empty(); //checks for an empty stack
		int full(); //checks if array is full

		void increase(); //expands the array by 20 whenever it is called
};

template<class T>
GenStack<T>::GenStack(int maxSize)
{
	baseArray = new T[maxSize];
	max = maxSize;
	front = -1;
	tempArray = new T[max];
}

template<class T>
GenStack<T>::~GenStack()
{
	delete []baseArray;
	delete []tempArray;

	cout << "Object deleted.  The program will now exit." << endl;
}

template<class T>
void GenStack<T>::push(T data)
{
	if(full() == 1) //if data is full, make more data and push the existing data
	{
		increase();
		push(data);
	}
	else
	{
		baseArray[++front] = data;  //continue like a normal push function
	}
}

template<class T>
T GenStack<T>::pop()
{
	if(empty() == 1)
	{
		cout << "Error: The current stack is empty.  There is no way to pop any more elements." << endl;
		return 0;
	}
	else
	{
		return baseArray[front--];
	}
}

template<class T>
T GenStack<T>::peek()
{
	if(front == -1)
	{
		// cout << "tag" << endl;
		return 0;
	}
	else
	{
		return baseArray[front];
	}
}

template<class T>
int GenStack<T>::empty()
{
	return (front == -1);
}

template<class T>
int GenStack<T>::full()
{
	return (front == (max - 1));
}

template<class T>
void GenStack<T>::increase()
{
	tempArray = new T[max];

	for(int i = front; i > -1; --i)
	{
		tempArray[i] = baseArray[i]; //makes a temporary array so the data allocation can be swifter
	}

	max += 20; //increases size by 20
	baseArray = new T[max];

	for(int i = front; i > -1; --i)
	{
		baseArray[i] = tempArray[i]; //puts orignial values back into the original array
	}
}