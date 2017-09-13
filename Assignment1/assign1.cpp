#include "assign1.h"
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

dnaProcess::dnaProcess() {
	string dna;
	int countLine;
	double nucleoCount = 0.0;
	double mean = 0.0;
	double standDev = 0.0;
	double nucleoTotal = 0.0;
	double probOfA = 0;
	double probOfC = 0;
	double probOfT = 0;
	double probOfG = 0;
}

dnaProcess::~dnaProcess() {

}

void dnaProcess::dnaSetString(ifstream& inStream) {
	countLine = 0;
	char c;
	while(!inStream.eof()) {
		if(c == '\n') {
			countLine++;
		}
		inStream.get(c);
		dna += c;
	}
}

void dnaProcess::fileComputations(ofstream& outStream) {
	int count = 0;
	double sum = 0.0;
	double variance = 0.0;
	double nucleoCount = 0;

	for(int i = 0; i < dna.size(); ++i) {
		if(dna[i] != '\n') {
			nucleoTotal += 1;
		}
		else {
			count += 1;
			if(count == countLine) {
				sum = nucleoTotal;
				mean = sum/countLine;
				count = 0;
				break;
			}
		}
	}
	outStream << "\nSum: " << sum;
	outStream << "\nMean: " << mean;

	for(int j = 0; j < dna.size(); ++j) {
		if(dna[j] != '\n') {
			nucleoCount += 1;
		}
		else {
			variance += pow((nucleoCount - mean), 2);
			nucleoCount = 0;
			count += 1;
			if(count == countLine) {
				variance = variance/nucleoTotal;
				standDev = sqrt(variance);
				break;
			}
		}
	}

	outStream << "\nVariance: " << variance;
	outStream << "\nStandard Deviation: " << standDev;
}

void dnaProcess::nucleoProbability(ofstream& outStream) {
	double probOfAA = 0, probOfAC = 0, probOfAT = 0, probOfAG = 0;
	double probOfCA = 0, probOfCC = 0, probOfCT = 0, probOfCG = 0;
	double probOfTA = 0, probOfTC = 0, probOfTT = 0, probOfTG = 0;
	double probOfGA = 0, probOfGC = 0, probOfGT = 0, probOfGG = 0;
	int count = 0;
/*
	for(int i = 0; i < dna.size();  ++i) {
		probOfA++;
*/
	for(int i = 0; i <= dna.size(); ++i) {
		string comp;
		comp += tolower(dna[i]);
		comp += tolower(dna[i+1]);

		if(!comp.compare("aa")) {
			probOfAA++;
		}
		else if(!comp.compare("ac")) {
			probOfAC++;
		}
		else if(!comp.compare("at")) {
			probOfAT++;
		}
		else if(!comp.compare("ag")) {
			probOfAG++;
		}
		else if(!comp.compare("ca")) {
			probOfCA++;
		}
		else if(!comp.compare("cc")) {
			probOfCC++;
		}
		else if(!comp.compare("ct")) {
			probOfCT++;
		}
		else if(!comp.compare("cg")) {
			probOfCG++;
		}
		else if(!comp.compare("ta")) {
			probOfTA;
		}
		else if(!comp.compare("tc")) {
			probOfTC;
		}
		else if(!comp.compare("tt")) {
			probOfTT;
		}
		else if(!comp.compare("tg")) {
			probOfTG;
		}
		else if(!comp.compare("ga")) {
			probOfGA++;
		}
		else if(!comp.compare("gc")) {
			probOfGC++;
		}
		else if(!comp.compare("gt")) {
			probOfGT++;
		}
		else if(!comp.compare("gg")) {
			probOfGG++;
		}
	}

	outStream << "\nThe relative probability of AA is: " << probOfAA/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of AC is: " << probOfAC/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of AT is: " << probOfAT/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of AG is: " << probOfAG/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of CA is: " << probOfCA/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of CC is: " << probOfCC/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of CT is: " << probOfCT/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of CG is: " << probOfCG/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of TA is: " << probOfTA/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of TC is: " << probOfTC/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of TT is: " << probOfTT/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of TG is: " << probOfTG/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of GA is: " << probOfGA/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of GC is: " << probOfGC/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of GT is: " << probOfGT/((float)count/*lineCount*/) << "\n";
//	cout << "\nThe relative probability of GG is: " << probOfGG/((float)count/*lineCount*/) << "\n";

}

void dnaProcess::guassianDistribution(ofstream& outStream) {

}
