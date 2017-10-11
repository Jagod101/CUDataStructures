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

    while (continued) {
        string fullCode;
        int lineNum = 0;

        ifstream inputStream;
        inputStream.open(file.c_str());

        while (inputStream >> fullCode) {
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
                        cout << "ERROR: Line " << lineNum << ": ')' expected and found '" << fullCode[i] << "' instead" << endl;
                        return 0;
                    }
                    else if ((s.peek() == '[')&&(fullCode[i] == ')' || fullCode[i] == '}')) {
                        cout << "ERROR: Line " << lineNum << ": ']' expected and found '" << fullCode[i] << "' instead" << endl;
                        return 0;
                    }
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

        if (s.isEmpty() == 0) {
            cout << "ERROR: End of File. Missing: " << s.peek() << endl;
            return 0;
        }
        else if (s.isEmpty() == 1) {
            char repeat;

            cout << "Procesing Complete: no errors \nCheck another File [Y/N]" << endl;
            cin >> repeat;

            if ((repeat == 'Y')||(repeat == 'y')||(repeat == 'yes')||(repeat == 'Yes')||(repeat == 'YES')) {
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