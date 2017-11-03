/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar’s Office Simulation 
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Simulate.cpp"

using namespace std;

int main(int argc, char** argv) {
    //INSERT CONSTRUCTOR
    Operation o;
    
    //If no file specified when running a.out
    if(argc < 2) {
        cout << "ERROR: Please Enter Valid File Input\n" << endl;
    }
    
    //If file is specified when running a.out
    else if(argc >= 2) {
        string file = argv[1];
        o.runSimulation(file);
    }
    return 0;
}