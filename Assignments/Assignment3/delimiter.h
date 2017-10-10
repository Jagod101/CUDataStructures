/*
 Zach Jagoda
 Student ID: 2274813
 Student Email: jagod101@mail.chapman.edu
 CPSC 350-02

 Assignment 3: Syntax Checker
 */

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

class delimiter {
    private:

    public:
        delimiter();
        ~delimiter();

        void filePath();
        void checkBrackets(ifstream& file);
}