#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include "GenStack.h"

using namespace std;

int main(int argc, char ** argv)
{
	bool continued = true;

	if(argc < 2)
	{
		cout << "Error: You did not input a file name." << endl;
	}
	else if(argc >= 2)
	{
		string file = argv[1];
		GenStack<char> boundaries(50);

		while(continued)
		{
			cout << "File name: " << file << endl;

			string code;
			int lineNum = 0;

			ifstream inputStream;
			inputStream.open(file.c_str());

			while(inputStream >> code)
			{
				for(int i = 0; i < code.size(); ++i) 
				{
					if(code[i] == '(' || code[i] == ')' || code[i] == '{' || code[i] == '}' || code[i] == '[' || code[i] == ']') //goes through to check for instances of (,),{,},[, or ]
					{
						if(boundaries.peek() == '(' && code[i] == ')')
						{
							boundaries.pop(); //if both are closed, continue normally
						}
						else if(boundaries.peek() == '(' && (code[i] == '}' || code[i] == ']'))
						{
							cout << "Error: Line " << lineNum << ": ')' expected and found " << code[i] << " instead." << endl; //print error and line #
							return 0;
						}
						else if(boundaries.peek() == '{' && code[i] == '}')
						{
							boundaries.pop(); //if both are closed, continue normally
						}
						else if(boundaries.peek() == '{' && (code[i] == ')' || code[i] == ']'))
						{
							cout << "Error: Line " << lineNum << ": '}' expected and found " << code[i] << " instead." << endl; //print error and line #
							return 0;
						}
						else if(boundaries.peek() == '[' && code[i] == ']')
						{
							boundaries.pop(); //if both are closed, continue normally
						}
						else if(boundaries.peek() == '[' && (code[i] == ')' || code[i] == '}'))
						{
							cout << "Error: Line " << lineNum << ": ']' expected and found " << code[i] << " instead." << endl; //print error and line #
							return 0;
						}
						else if(boundaries.empty() == 1 && (code[i] == '}' || code[i] == ')' || code[i] == ']'))
						{
							cout << "Error: Line " << lineNum << ": Invalid delimiter via an unopened " << code[i] << " symbol." << endl;
							return 0;
						}
						else if(code[i] == '(' || code[i] == '[' || code[i] == '{')
						{
							boundaries.push(code[i]);
						}
					}
				}
				++lineNum;
			}

			inputStream.close();

			if(boundaries.empty() == 0)
			{
				cout << "End of file.  Missing: " << boundaries.peek() << "." << endl;
				return 0;
			}
			else if(boundaries.empty() == 1)
			{
				char answer;

				cout << "The syntax of the whole file is correct. \nIf you would like to analyze another file, type 'Y'.  \nOtherwise, press any key and enter to exit: ";
				cin >> answer;

				if(answer == 'y' || answer == 'Y') //continues
				{
					cout << "Enter the file name: ";
					cin >> file;
					continue;
				}
				else //ends
				{
					continued = false;
				}
			}
		}
	}
	return 0;
}