#include "Quiz1.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	string test = "redeemable";
	Quiz1 q;

	cout << "The number of vowels in " << test << " is " << q.countVowels(test) << endl;

	return 0;
}