/*Zachary Jagoda
  Student ID: 2274813
  Student Email: jagod101@mail.chapman.edu
  CPSC 350-02
  Assignment 1 (C++ Review/DNA)

  The following assignment is to build a simple analysis program that will compute basic statistics for a list of DNA strings

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dnaProcess {
	private:
		string dna;
		int countLine;
		double bigramCount;
		double nucleoCount;
		double sum;
		double mean;
		double variance;
		double standDev;
		double nucleoTotal;
		double probOfA;
		double probOfC;
		double probOfT;
		double probOfG;

	public:
		dnaProcess();	//Constructor
		~dnaProcess();	//Deconstructor

		void dnaSetString(ifstream& inStream); //Take input from the file
		void fileComputations(ofstream& outStream); //Mathematical Computations (Sum/Mean/Variance/StandDev)
		void nucleoProbability(ofstream& outStream); //Probability of each Nucleo Type
		void guassianDistribution(ofstream& outStream); //Newly generated sequences
};
