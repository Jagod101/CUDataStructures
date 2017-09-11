/*Ashley Wood
2271425
wood198@mail.chapman.edu
CPSC 350-02
Assignment 1: DNA/C++ Review. Build a simple analysis program that will compute basic statistics
for a list of DNA strings.*/

#include <iostream>
#include <string>
#include <Assignment1.h>
#include <math.h>
#include <fstream>

using namespace std;

ProcessDNA::Process() {

}

ProcessDNA::~Process(){

}

//Loops through the nucleotides in the file and counts them
int ProcessDNA::sumOfNucleotides(string file){

	int count = 0;

	for (i = 0; i <= string.length(file); ++i) {
		count++;
	}

}


//Computes the average length of each string in the file
int ProcessDNA::meanOfStrings(string file){

	int countNucleotides = 0;
	int count = 0;

	for (i = 0; i <= string.length(file); ++i) {
		count++;
	}

}

//
int ProcessDNA::varianceOfNucleotides(string file){


}

//Computes the Standard Deviation of the lines in the file
int ProcessDNA::standDevOfLengths(string file){


}

//Computes the probability that each of the 4 nucleotides will show up in the file
int ProcessDNA::probabilityOfNucleotides(string file){

	int count = 0;

	for (i = 0; i <= string.length(file); ++i) {
		count++;
	}

	int numberOfTypeA = 0;
	int numberOfTypeC = 0;
	int numberOfTypeT = 0;
	int numberOfTypeG = 0;
	int probabilityOfA = 0;
	int probabilityOfC = 0;
	int probabilityOfT = 0;
	int probabilityOfG = 0;

	for (i = 0; i <= string.length(file); i++) {
		if(input[i] == 'A' || input[i] == 'a'){
			numberOfTypeA++;
		}else if(input[i] == 'C' || input[i] == 'c'){
			numberOfTypeC++;
		}else if(input[i] == 'T' || input[i] == 't'){
			numberOfTypeT++;
		}else if(input[i] == 'G' || input[i] == 'g'){
			numberOfTypeG++;
		}
	}

	probabilityOfA = numberOfTypeA / count;
	probabilityOfC = numberOfTypeC / count;
	probabilityOfT = numberOfTypeT / count;
	probabilityOfG = numberOfTypeG / count;

	cout << "The probability of A showing up in your file is:" << probabilityOfA << endl;
	cout << "The probability of T showing up in your file is:" << probabilityOfT << endl;
	cout << "The probability of C showing up in your file is:" << probabilityOfC << endl;
	cout << "The probability of G showing up in your file is:" << probabilityOfG << endl;
}

//Computes the probability that any pair of nucleotides with show up in the file
int ProcessDNA::probabilityOfPairs(string file){

	int count = 0;

	for (i = 0; i <= string.length(file); ++i) {
		count++;
	}

	int newCount = count/2;

	int numberOfTypeAA = 0;
	int numberOfTypeAT = 0;
	int numberOfTypeAC = 0;
	int numberOfTypeAG = 0;
	int numberOfTypeTA = 0;
	int numberOfTypeTT = 0;
	int numberOfTypeTC = 0;
	int numberOfTypeTG = 0;
	int numberOfTypeCA = 0;
	int numberOfTypeCT = 0;
	int numberOfTypeCC = 0;
	int numberOfTypeCG = 0;
	int numberOfTypeGA = 0;
	int numberOfTypeGT = 0;
	int numberOfTypeGC = 0;
	int numberOfTypeGG = 0;

	int probabilityOfAA = 0;
	int probabilityOfAC = 0;
	int probabilityOfAT = 0;
	int probabilityOfAG = 0;
	int probabilityOfTA = 0;
	int probabilityOfTC = 0;
	int probabilityOfTT = 0;
	int probabilityOfTG = 0;
	int probabilityOfCA = 0;
	int probabilityOfCC = 0;
	int probabilityOfCT = 0;
	int probabilityOfCG = 0;
	int probabilityOfGA = 0;
	int probabilityOfGC = 0;
	int probabilityOfGT = 0;
	int probabilityOfGG = 0;

	for (i = 0; i <= string.length(file); i+2) {
	if(input[i] == 'AA' || input[i] == 'aA' || input[i] == 'Aa' || input[i] == 'aa' ||){		
		numberOfTypeAA++;
	}else if(input[i] == 'AT' || input[i] == 'aT' || input[i] == 'At' || input[i] == 'at' ||){
		numberOfTypeAT++;
	}else if(input[i] == 'AC' || input[i] == 'aC' || input[i] == 'Ac' || input[i] == 'ac' ||){
		numberOfTypeAC++;
	}else if(input[i] == 'AG' || input[i] == 'aG' || input[i] == 'Ag' || input[i] == 'ac' ||){
		numberOfTypeAG++;
	}else if(input[i] == 'TA' || input[i] == 'tA' || input[i] == 'Ta' || input[i] == 'ta' ||){
		numberOfTypeTA++;
	}else if(input[i] == 'TT' || input[i] == 'tT' || input[i] == 'Tt' || input[i] == 'tt' ||){
		numberOfTypeTT++;
	}else if(input[i] == 'TC' || input[i] == 'tC' || input[i] == 'Tc' || input[i] == 'tc' ||){
		numberOfTypeTC++;
	}else if(input[i] == 'TG' || input[i] == 'tG' || input[i] == 'Tg' || input[i] == 'tg' ||){
		numberOfTypeTG++;
	}else if(input[i] == 'CA' || input[i] == 'cA' || input[i] == 'Ca' || input[i] == 'ca' ||){
		numberOfTypeCA++;
	}else if(input[i] == 'CT' || input[i] == 'cT' || input[i] == 'Ct' || input[i] == 'ct' ||){
		numberOfTypeCT++;
	}else if(input[i] == 'CC' || input[i] == 'cC' || input[i] == 'Cc' || input[i] == 'cc' ||){
		numberOfTypeCC++;
	}else if(input[i] == 'CG' || input[i] == 'cG' || input[i] == 'Cg' || input[i] == 'cg' ||){
		numberOfTypeCG++;
	}else if(input[i] == 'GA' || input[i] == 'gA' || input[i] == 'Ga' || input[i] == 'ga' ||){
		numberOfTypeGA++;
	}else if(input[i] == 'GT' || input[i] == 'gT' || input[i] == 'Gt' || input[i] == 'gt' ||){
		numberOfTypeGT++;
	}else if(input[i] == 'GC' || input[i] == 'gC' || input[i] == 'Gc' || input[i] == 'gc' ||){
		numberOfTypeGC++;
	}else if(input[i] == 'GG' || input[i] == 'gG' || input[i] == 'Gg' || input[i] == 'gg' ||){
		numberOfTypeGG++;
	}

	int probabilityOfAA = numberOfTypeAA/newCount;
	int probabilityOfAC = numberOfTypeAT/newCount;
	int probabilityOfAT = numberOfTypeAC/newCount;
	int probabilityOfAG = numberOfTypeAG/newCount;
	int probabilityOfTA = numberOfTypeTA/newCount;
	int probabilityOfTC = numberOfTypeTT/newCount;
	int probabilityOfTT = numberOfTypeTC/newCount;
	int probabilityOfTG = numberOfTypeTG/newCount;
	int probabilityOfCA = numberOfTypeCA/newCount;
	int probabilityOfCC = numberOfTypeCT/newCount;
	int probabilityOfCT = numberOfTypeCC/newCount;
	int probabilityOfCG = numberOfTypeCG/newCount;
	int probabilityOfGA = numberOfTypeGA/newCount;
	int probabilityOfGC = numberOfTypeGT/newCount;
	int probabilityOfGT = numberOfTypeGC/newCount;
	int probabilityOfGG = numberOfTypeGG/newCount;

	cout << "The probability of AA showing up in your file is:" << probabilityOfA << endl;
	cout << "The probability of AT showing up in your file is:" << probabilityOfT << endl;
	cout << "The probability of AC showing up in your file is:" << probabilityOfC << endl;
	cout << "The probability of AG showing up in your file is:" << probabilityOfG << endl;
	cout << "The probability of TA showing up in your file is:" << probabilityOfA << endl;
	cout << "The probability of TT showing up in your file is:" << probabilityOfT << endl;
	cout << "The probability of TC showing up in your file is:" << probabilityOfC << endl;
	cout << "The probability of TG showing up in your file is:" << probabilityOfG << endl;
	cout << "The probability of CA showing up in your file is:" << probabilityOfA << endl;
	cout << "The probability of CT showing up in your file is:" << probabilityOfT << endl;
	cout << "The probability of CC showing up in your file is:" << probabilityOfC << endl;
	cout << "The probability of CG showing up in your file is:" << probabilityOfG << endl;
	cout << "The probability of GA showing up in your file is:" << probabilityOfA << endl;
	cout << "The probability of GT showing up in your file is:" << probabilityOfT << endl;
	cout << "The probability of GC showing up in your file is:" << probabilityOfC << endl;
	cout << "The probability of GG showing up in your file is:" << probabilityOfG << endl;

}