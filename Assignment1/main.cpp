/*Zachary Jagoda
  Student ID: 2274813
  Student Email: jagod101@mail.chapman.edu
  CPSC 350-02
  Assignment 1 (C++ Review/DNA)

  The following assignment is to build a simple analysis program that will compute basic statistics for a list of DNA strings

*/

#include "assign1.h"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	ofstream outFile ("ZachJagoda.out");
	if(outFile.is_open()) {
		outFile << "Zach Jagoda \n" << endl;
		outFile << "Student ID: 2274813 \n" << endl;
		outFile << "Student Email: jagod101@mail.chapman.edu \n" << endl;
		outFile << "CPSC 350-02 \n" <<  endl;
		outFile << "Assignment 1: C++ Review \n" << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}

	while( true ) {
		string filepath;
		cout << "What is the file path of the .txt file you want to use?" << endl;
		cin >> filepath;
		ifstream inFile; //File input stored as inFile

		inFile.open(filepath.c_str());
		string file;
		inFile >> file;

		cout << inFile.rdbuf();

//		dnaAssignment a;

//		a.nucleoSum(DNA);
//		a.dnaVariance(DNA);
//		a.dnaStringMean(DNA);
//		a.dnaStandDev(DNA);
//		a.nucleoProbability(file);
//		a.nucleoProbabilityPairs(file);

		inFile.close();
		outFile.close();

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
