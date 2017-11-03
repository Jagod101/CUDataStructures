/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar’s Office Simulation 
*/

#include <iostream>

using namespace std;

class Students {
    private:

    public:
        Students();
        Students(int t, int e);
        ~Students();

        int windowTime;
        int entryTime;
        int queueTime;
        int idleTime;
};