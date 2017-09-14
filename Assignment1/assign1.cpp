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
	double sum = 0.0;
	double mean = 0.0;
	double variance = 0.0;
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
	outStream << "\nStandard Deviation: " << standDev << "\n";
}

void dnaProcess::nucleoProbability(ofstream& outStream) {
	double probOfAA = 0, probOfAC = 0, probOfAT = 0, probOfAG = 0;
	double probOfCA = 0, probOfCC = 0, probOfCT = 0, probOfCG = 0;
	double probOfTA = 0, probOfTC = 0, probOfTT = 0, probOfTG = 0;
	double probOfGA = 0, probOfGC = 0, probOfGT = 0, probOfGG = 0;

	for(int i = 0; i < dna.size();  ++i) {
		if((dna[i] == 'a')||(dna[i] == 'A')) {
			probOfA += 1;
			if(dna[i+1] != '\n') {
				nucleoCount += 1;
				if((dna[i+1] == 'a')||(dna[i+1] == 'A')) {
					probOfAA += 1;
				}
				else if((dna[i+1] == 'c')||(dna[i+1] == 'C')) {
					probOfAC += 1;
				}
				else if((dna[i+1] == 't')||(dna[i+1] == 'T')) {
					probOfAT += 1;
				}
				else if((dna[i+1] == 'g')||(dna[i+1] == 'G')) {
					probOfAG += 1;
				}
			}
		}
                else if((dna[i] == 'c')||(dna[i] == 'C')) {
                        probOfC += 1;
                        if(dna[i+1] != '\n') {
                                nucleoCount += 1;
                                if((dna[i+1] == 'a')||(dna[i+1] == 'A')) {
                                        probOfCA += 1;
                                }
                                else if((dna[i+1] == 'c')||(dna[i+1] == 'C')) {
                                        probOfCC += 1;
                                }
                                else if((dna[i+1] == 't')||(dna[i+1] == 'T')) {
                                        probOfCT += 1;
                                }
                                else if((dna[i+1] == 'g')||(dna[i+1] == 'G')) {
                                        probOfCG += 1;
                                }
                        }
                }
                else if((dna[i] == 't')||(dna[i] == 'T')) {
                        probOfT += 1;
                        if(dna[i+1] != '\n') {
                                nucleoCount += 1;
                                if((dna[i+1] == 'a')||(dna[i+1] == 'A')) {
                                        probOfTA += 1;
                                }
                                else if((dna[i+1] == 'c')||(dna[i+1] == 'C')) {
                                        probOfTC += 1;
                                }
                                else if((dna[i+1] == 't')||(dna[i+1] == 'T')) {
                                        probOfTT += 1;
                                }
                                else if((dna[i+1] == 'g')||(dna[i+1] == 'G')) {
                                        probOfTG += 1;
                                }
                        }
                }
                else if((dna[i] == 'g')||(dna[i] == 'G')) {
                        probOfG += 1;
                        if(dna[i+1] != '\n') {
                                nucleoCount += 1;
                                if((dna[i+1] == 'a')||(dna[i+1] == 'A')) {
                                        probOfGA += 1;
                                }
                                else if((dna[i+1] == 'c')||(dna[i+1] == 'C')) {
                                        probOfGC += 1;
                                }
                                else if((dna[i+1] == 't')||(dna[i+1] == 'T')) {
                                        probOfGT += 1;
                                }
                                else if((dna[i+1] == 'g')||(dna[i+1] == 'G')) {
                                        probOfGG += 1;
                                }
                        }
                }
	}
	//Singular Nucleotides
	probOfA = (probOfA/nucleoCount)*100;
	probOfC = (probOfC/nucleoCount)*100;
	probOfT = (probOfT/nucleoCount)*100;
	probOfG = (probOfG/nucleoCount)*100;
	//Nucleotides of A
	probOfAA = (probOfAA/nucleoCount)*100;
	probOfAC = (probOfAC/nucleoCount)*100;
	probOfAT = (probOfAT/nucleoCount)*100;
	probOfAG = (probOfAG/nucleoCount)*100;
	//Nucleotides of C
	probOfCA = (probOfCA/nucleoCount)*100;
	probOfCC = (probOfCC/nucleoCount)*100;
	probOfCT = (probOfCT/nucleoCount)*100;
	probOfCG = (probOfCG/nucleoCount)*100;
	//Nucleotides of T
	probOfTA = (probOfTA/nucleoCount)*100;
	probOfTC = (probOfTC/nucleoCount)*100;
	probOfTT = (probOfTT/nucleoCount)*100;
	probOfTG = (probOfTG/nucleoCount)*100;
	//Nucleotides of G
	probOfGA = (probOfGA/nucleoCount)*100;
	probOfGC = (probOfGC/nucleoCount)*100;
	probOfGT = (probOfGT/nucleoCount)*100;
	probOfGG = (probOfGG/nucleoCount)*100;
	//Printing the percentage values to outStream (ZachJagoda.out)
	outStream << "\nSingular Nucleotides" << "\nA: " << probOfA << "%\nC: " << probOfC << "%\nT: " << probOfT << "%\nG: " << probOfG << "%";
	outStream << "\nNucleotide Pairs (A)" << "\nAA: " << probOfAA << "%\nAC: " << probOfAC << "%\nAT: " << probOfAT << "%\nAG: " << probOfAG << "%";
        outStream << "\nNucleotide Pairs (C)" << "\nCA: " << probOfCA << "%\nCC: " << probOfCC << "%\nCT: " << probOfCT << "%\nCG: " << probOfCG << "%";
        outStream << "\nNucleotide Pairs (T)" << "\nTA: " << probOfTA << "%\nTC: " << probOfTC << "%\nTT: " << probOfTT << "%\nTG: " << probOfTG << "%";
        outStream << "\nNucleotide Pairs (G)" << "\nGA: " << probOfGA << "%\nGC: " << probOfGC << "%\nGT: " << probOfGT << "%\nGG: " << probOfGG << "%\n";
}

void dnaProcess::guassianDistribution(ofstream& outStream) {
	double a = ((double) rand() / (RAND_MAX));
	double b = ((double) rand() / (RAND_MAX));

	double c = (sqrt(-2*log(a)))*(cos(2*(M_PI)*b));
	double d = (standDev * c) + mean;

	for(int i = 0; i < 1000; ++i) {
		for(int j = 0; j < d; ++j) {
			double range = rand() % 100;
			if(range <= probOfA) {
				outStream << "A";
			}
			else if(range <= (probOfC + probOfA)) {
				outStream << "C";
			}
			else if(range <= (probOfT + probOfC + probOfA)) {
				outStream << "T";
			}
			else if(range <= 100) {
				outStream << "G";
			}
		}
		outStream << "\n";
	}
	//Reset Probabilities of Singular Nucleotides for if user runs another file
	probOfA = 0;
	probOfC = 0;
	probOfT = 0;
	probOfG = 0;
}
