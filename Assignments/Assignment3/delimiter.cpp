/*
 Zach Jagoda
 Student ID: 2274813
 Student Email: jagod101@mail.chapman.edu
 CPSC 350-02

 Assignment 3: Syntax Checker

 Purpose: take input in the form of a file and check for all Brackets throughout it
 */

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "delimiter.h"
#include "GenStack.h"

using namespace std;

//Constructor
delimiter::delimiter() {

}

//Destructor
delimiter::~delimiter() {

}

//Method to check all Brackets with input file (from main)
int delimiter::checkBrackets(string file) {
    bool continued = true;

    GenStack<char> s(10);

    while (continued) {
        string fullCode; 
        int lineNum = 1; 

        ifstream inputStream; 
        inputStream.open(file.c_str());

        while (inputStream >> fullCode) {
            for (int i = 0; i < fullCode.size(); ++i) {
                if ((fullCode[i] == '(')||(fullCode[i] == ')')||(fullCode[i] == '[')||(fullCode[i] == ']')||(fullCode[i] == '{')||(fullCode[i] == '}')) {
                    //If statement looking for '(' and ')' Brackets
                    if ((s.peek() == '(')&&(fullCode[i] == ')')) {
                        s.pop();
                    }
                    //Else If statement looking for '[' and ']' Brackets
                    else if ((s.peek() == '[')&&(fullCode[i] == ']')) {
                        s.pop();
                    }
                    //Else If statement looking for '{' and '}' Brackets
                    else if ((s.peek() == '{')&&(fullCode[i] == '}')) {
                        s.pop();
                    }
                    //Else If statement looking for Mismatched Brackets
                    else if ((s.peek() == '(')&&(fullCode[i] == ']' || fullCode[i] == '}')) {
                        cout << "ERROR: Line " << lineNum << ": ')' expected and found '" << fullCode[i] << "' instead" << endl;
                        return 0;
                    }
                    //Else If statement looking for Mismatched Brackets
                    else if ((s.peek() == '[')&&(fullCode[i] == ')' || fullCode[i] == '}')) {
                        cout << "ERROR: Line " << lineNum << ": ']' expected and found '" << fullCode[i] << "' instead" << endl;
                        return 0;
                    }
                    //Else If statement looking for Mismatched Brackets
                    else if ((s.peek() == '{')&&(fullCode[i] == ']' || fullCode[i] == ')')) {
                        cout << "ERROR: Line " << lineNum << ": '}' expected and found '" << fullCode[i] << "' instead" << endl;
                        return 0;
                    }
                    else if ((fullCode[i] == '(')||(fullCode[i] == '[')||(fullCode[i] == '{')) {
                        s.push(fullCode[i]);
                    }
                }
            }
            ++lineNum;
        }
        //if isEmpty returns as false (0) there are extra Brackets in program (stored at the top/peek) - throws ERROR
        if (s.isEmpty() == 0) {
            cout << "ERROR: End of File. Missing: " << s.peek() << endl;
            return 0;
        }
        //if isEmpty returns as true (1) there are no ERRORS
        else if (s.isEmpty() == 1) {
            char repeat;

            cout << "Procesing Complete: no errors \nCheck another File [Y/N]" << endl;
            cin >> repeat;

            if ((repeat == 'Y')||(repeat == 'y')) {
                cout << "Name of New File? ";
                cin >> file;
                cout << "\n" << endl;
                continue;
            }
            else {
                continued = false;
            }
        }
    }
    return 0;
}
