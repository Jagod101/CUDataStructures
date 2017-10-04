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
	//ofstream to signify outgoing info
	ofstream out;
	//ifstream to signify incoming info
	ifstream in;

	//Opens output file
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
		//filepath input
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

		//While Loop to catch any user input errors for their decision
		bool again = true;
		while ( again ) {
			cout << "Would you like to process another list? (Y/N)" << endl;
			string input;
			cin >> input;
			//If user inputs no program exits 
			if ((input == "n")||(input == "N")) {
				out.close();
				return 0;
			}
			//If user inputs yes program repeats
			else if ((input == "y")||(input == "Y")) {
				break;
			}
			//Any other inputs invokes error message
			else {
				cout << "Please Enter a Valid Option" << endl;
				cout << "'Don't Panic' -Hitchhikers Guide to the Galaxy\n" << endl;
				continue;
			}
		}
	}
	return 0;
}
