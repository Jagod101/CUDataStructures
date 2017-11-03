/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar’s Office Simulation 
*/

#include <iostream>
#include "Students.h"

using namespace std;

Students::Students() {
    windowTime = 0;
    entryTime = 0;
    queueTime = 0;
    idleTime = 0;
}

Students::Students(int t, int e) {
    windowTime = t;
    entryTime = e;
    queueTime = 0;
    idleTime = 0;
}

Students::~Students() {}