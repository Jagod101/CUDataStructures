#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dnaProcess {
	public:
		dnaProcess();	//Constructor
		~dnaProcess();	//Deconstructor
		int nucleoSum(); //Sum of the Nucleotides
		int dnaVariance(); //Varience of the DNA strings
		int dnaStringMean(); //Mean of the length of DNA strings
		int dnaStandDev(); //Standard Deviation of DNA strings
		int nucleoProbability(string file); //Relative Probability of each Nucleotide
		int nucleoProbabilityPairs(string file); //Probability of each Nucleotide Bigram
};
