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
#include "delimiter.h"
#include "GenStack.h"

using namespace std;

delimiter::delimiter() {

}

delimiter::~delimiter() {

}

int delimiter::checkBrackets(string file) {
    bool continued = true;

    GenStack<char> s(10);

    string file;

    while (continued) {
        string fullCode;
        int lineNum = 0;

        ifstream inputStream;
        inputStream.open(file.c_str());

        while (file >> fullCode) {
            for (int i = 0; i < fullCode.size(); ++i) {
                if ((fullCode[i] == '(')||(fullCode[i] == ')')||(fullCode[i] == '[')||(fullCode[i] == ']')||(fullCode[i] == '{')||(fullCode[i] == '}')) {
                    if ((s.peek() == '(')&&(fullCode[i] == ')')) {
                        s.pop();
                    }
                    else if ((s.peek() == '[')&&(fullCode[i] == ']')) {
                        s.pop();
                    }
                    else if ((s.peek() == '{')&&(fullCode[i] == '}')) {
                        s.pop();
                    }
                    else if ((s.peek() == '(')&&(fullCode[i] == ']' || fullCode[i] == '}')) {
                        cout << "ERROR: Line " << lineNum << ": ')' expected and found '" << fullCode[i] << "' instead\n" << endl;
                        return 0;
                    }
                    else if ((s.peek() == '[')&&(fullCode[i] == ')' || fullCode[i] == '}')) {
                        cout << "ERROR: Line " << lineNum << ": ']' expected and found '" << fullCode[i] << "' instead\n" << endl;
                        return 0;
                    }
                    else if ((s.peek() == '{')&&(fullCode[i] == ']' || fullCode[i] == ')')) {
                        cout << "ERROR: Line " << lineNum << ": '}' expected and found '" << fullCode[i] << "' instead\n" << endl;
                        return 0;
                    }
                    else if ((fullCode[i] == '(')||(fullCode[i] == '[')||(fullCode[i] == '{')) {
                        s.push(fullCode[i]);
                    }
                }
            }
            ++lineNum;
        }

        if (s.isEmpty() == 0) {
            cout << "ERROR: End of File. Missing: " << s.peek() << endl;
            return 0;
        }
        else if (s.isEmpty() == 1) {
            char repeat;

            cout << "Procesing Complete - No Errors. \Check another File [Y/N]\n" << endl;
            cin >> repeat;

            if ((repeat == 'Y')||(repeat == 'y')) {
                cout << "Name of New File?\n" << endl;
                cin >> file;
                continue;
            }
            else {
                continued = false;
            }
        }
    }
    return 0;
}