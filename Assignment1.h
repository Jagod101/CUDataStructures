/*Ashley Wood
2271425
wood198@mail.chapman.edu
CPSC 350-02
Assignment 1: DNA/C++ Review. Build a simple analysis program that will compute basic statistics
for a list of DNA strings.*/

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

class ProcessDNA {
	public:
		Process();
		~Process();
		int sumOfNucleotides(string file);
		int meanOfStrings(string file);
		int varianceOfNucleotides(string file);
		int standDevOfNucleotides(string file);
		int probabilityOfNucleotides(string file);
		int probabilityOfPairs(string file);
};