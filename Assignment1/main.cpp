/*Zachary Jagoda
  Student ID: 2274813
  Student Email: jagod101@mail.chapman.edu
  CPSC 350-02
  Assignment 1 (C++ Review/DNA)

  The following assignment is to build a simple analysis program that will compute basic statistics for a list of DNA strings

*/

//#include "assign1.h"

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	while( true ) {
		string filepath;
		cout << "What is the file path of the .txt file you want to use?" << endl;
		cin >> filepath;
		ifstream inFile;

		inFile.open(filepath.c_str());

		cout << inFile.rdbuf();

		inFile.close();

		cout << "Would you like to process another list? (Y/N)" << endl;
		string input;
		cin >> input;

		if ((input == "n")||(input == "N")) {
			return 0;
		}
		else
			continue;

	}
	cout << "Don't Panic' -Hitchhikers Guide to the Galaxy" << endl;
	return 0;
}
