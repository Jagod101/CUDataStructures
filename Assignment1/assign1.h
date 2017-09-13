#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dnaProcess {
	private:
		string dna;
		int countLine;
		double nucleoCount;
		double mean;
		double standDev;
		double nucleoTotal;
		double probOfA;
		double probOfC;
		double probOfT;
		double probOfG;

	public:
		dnaProcess();	//Constructor
		~dnaProcess();	//Deconstructor

		void dnaSetString(ifstream& inStream);
		void fileComputations(ofstream& outStream);
		void nucleoProbability(ofstream& outStream);
		void guassianDistribution(ofstream& outStream);
};
