/*
 Zach Jagoda
 Student ID: 2274813
 Student Email: jagod101@mail.chapman.edu
 CPSC 350-02

 Assignment 3: Syntax Checker
 */

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "GenStack.h"
#include "delimiter.h"

using namespace std;

int main(int argc, char** argv) {
    delimiter d;

    if (argc < 2) {
        cout << "ERROR: Please Enter Valid File Input" << endl;
    }
    else if (argc >= 2) {
        string file = argv[1];
        d.checkBrackets(file);
    }

    return 0;
}
