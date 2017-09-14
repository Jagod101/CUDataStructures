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
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
	ofstream out;
	ifstream in;

	out.open("ZachJagoda.out");
	if(out.is_open()) {
		out << "\nZach Jagoda";
		out << "\nStudent ID: 2274813";
		out << "\nStudent Email: jagod101@mail.chapman.edu";
		out << "\nCPSC 350-02";
		out << "\nAssignment 1: C++ Review\n";
	}
	else {
		cout << "Unable to open file" << endl;
	}

	while( true ) {
		string filepath;
		cout << "What is the file path of the .txt file you want to use?" << endl;
		cin >> filepath;

		in.open(filepath.c_str());

		dnaProcess a;

		a.dnaSetString(in);
		a.fileComputations(out);
		a.nucleoProbability(out);
		a.guassianDistribution(out);

		in.close();

		cout << "Would you like to process another list? (Y/N)" << endl;
		string input;
		cin >> input;

		if ((input == "n")||(input == "N")) {
			out.close();
			return 0;
		}
		else
			continue;

	}
	cout << "Don't Panic' -Hitchhikers Guide to the Galaxy" << endl;
	return 0;
}
