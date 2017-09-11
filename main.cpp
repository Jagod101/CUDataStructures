/*Ashley Wood
2271425
wood198@mail.chapman.edu
CPSC 350-02
Assignment 1: DNA/C++ Review. Build a simple analysis program that will compute basic statistics
for a list of DNA strings.*/

#include <iostream>
#include <string>
//#include <Assignment1.h>
//#include <Assignment1.cpp>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	string fileName;
	cout << "What is the name of the .txt file you want to use? (include.txt)" << endl;
	cin >> fileName;

	ifstream dnaFile;
	dnaFile.open(fileName.c_str());
	string DNA;
	dnaFile >> DNA;

	cout << dnaFile.rdbuf();

	int prompt = 0;

	string continueOn = "y";

	while(continueOn == "y"){

		if(prompt > 0){	
			string fileName;
			cout << "What is the name of the .txt file you want to use? (include.txt)" << endl;
			cin >> fileName;

			ifstream dnaFile;
			dnaFile.open(fileName.c_str());
			dnaFile >> DNA;

		}

		Assignment1 a;

		a.sumOfNucleotides(DNA);
		//a.meanOfStrings(DNA);
		//a.varianceOfNucleotides(DNA);
		//a.standDevOfLengths(DNA);
		a.probabilityOfNucleotides(DNA);
		a.probabilityOfPairs(DNA);


		string wantToContinue;
		cout << "Would you like to process another DNA string?" << endl;
		cin >> wantToContinue;

		if (wantToContinue == "y") {
			continueOn = "y";
			prompt++;
		}else {
			continueOn = wantToContinue;
		}

	}

	dnaFile.close();
	return 0;

}