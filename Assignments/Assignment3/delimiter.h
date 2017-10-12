/*
 Zach Jagoda
 Student ID: 2274813
 Student Email: jagod101@mail.chapman.edu
 CPSC 350-02

 Assignment 3: Syntax Checker

 Purpose: declare the delimiter class and it's methods for delimiter.cpp
 */

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

class delimiter {
    private:

    public:
        delimiter(); //Constructor
        ~delimiter(); //Destructor

        int checkBrackets(string file); //checkBrackets takes in string file from main.cpp
};
