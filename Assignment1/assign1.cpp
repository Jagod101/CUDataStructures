#include "assign1.h"
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

dnaProcess::dnaProcess() {

}

dnaProcess::~dnaProcess() {

}

int dnaProcess::nucleoSum() {

}

int dnaProcess::dnaVariance() {

}

int dnaProcess::dnaStringMean() {

}

int dnaProcess::dnaStandDev() {

}

int dnaProcess::nucleoProbability(string file) {
	int count = 0;
	string line;

	for(int i = 0; i <= file.length(); ++i) {
		count++;
	}

	int probOfA = 0;
	int probOfC = 0;
	int probOfT = 0;
	int probOfG = 0;

	for(int i = 0; i <= file.length(); ++i) {
		char c = tolower(line[i]);
		if(c == 'a') {
			probOfA++;
		}
		else if(c == 'c') {
			probOfC++;
		}
		else if(c == 't') {
			probOfT++;
		}
		else if(c == 'g') {
			probOfG++;
		}
	}
}

int dnaProcess::nucleoProbabilityPairs(string file) {
	int count = 0;

	for(int i = 0; i <= file.length(); ++i) {
		count++;
	}

	int probOfAA = 0;
	int probOfAC = 0;
	int probOfAT = 0;
	int probOfAG = 0;
	int probOfTA = 0;
	int probOfTC = 0;
	int probOfTT = 0;
	int probOfTG = 0;
	int probOfCA = 0;
	int probOfCC = 0;
	int probOfCT = 0;
	int probOfCG = 0;
	int probOfGA = 0;
	int probOfGC = 0;
	int probOfGT = 0;
	int probOfGG = 0;

	for(int i = 0; i <= file.length(); ++i) {
		string comp;
		comp += tolower(file[i]);
		comp += tolower(file[i+1]);

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
}

