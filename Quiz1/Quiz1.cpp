#include "Quiz1.h"
#include <iostream>

using namespace std;

Quiz1::Quiz1()
{

}

Quiz1::~Quiz1()
{
	cout << "object deleted" << endl;
}

int Quiz1::countVowels(string input)
{
	int count = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if(input[i] == "a")
			count++;
		else if (input[i] == "e")
			count++;
		else if (input[i] == "i")
			count++;
		else if (input[i] == "o")
			count++;
		else if (input[i] == "u")
			count++;
	}
	return count;
}