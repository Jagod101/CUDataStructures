/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#ifndef included
#define included

using namespace std;

class Member
{
    public:
        int ID;
        string name;
        string level;

        Member();
        ~Member();

        int getID();
        void setID(int value);

        string getName();
        string getLevel();
};

#endif
