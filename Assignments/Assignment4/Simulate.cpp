/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar’s Office Simulation 
*/

#include <iostream>
#include "Simulate.h"
#include "assign4.cpp"

using namespace std;

Operation::Operation() {

}

Operation::~Operation() {

}

int Operation::runSimulation(string file) {
    Simulation s;

    int currTime = 0;
    int openWindows = 0;

    bool running = true;

    s.importFile(file);

    while(running) {
        if(s.studentQueue.isEmpty()) {
            int temp = 0;

            for(int i = 0; i < s.totalWindows; ++i) {
                if((s.windowArray[i]->windowTime) < 1) {
                    temp++;
                }
            }
            if(temp = s.totalWindows) {
                running = false;
            }
        }
        for(int i = 0; i < s.totalWindows; ++i) {
            if(s.windowArray[i]->windowTime < 1) {
                if(!s.studentQueue.isEmpty()) {
                    Students* student = s.studentQueue.vFront();

                    if(student->entryTime <= currTime) {
                        if(s.windowArray[i]->idleTime > 0) {
                            s.idleStats.enqueue(s.windowArray[i]->idleTime);
                        }
                        //Move from Queue to Window Array
                        s.windowArray[i] = s.studentQueue.dequeue();
                        s.waitStats.enqueue(s.windowArray[i]->queueTime);
                    }
                }
            }
        }
        currTime++;
        s.timeTracker(currTime);
    }

    for(int i = 0; i < s.totalWindows; ++i) {
        if(s.windowArray[i]->idleTime > 0) {
            s.idleStats.enqueue(s.windowArray[i]->idleTime);
        }
    }

    cout << "\n<------------SIMULATION COMPLETE------------>" << endl;
    cout << "STUDENT Calculations" << endl;
    cout << "Mean Student Wait Time: " << s.meanTime() << endl;
    cout << "Median Student Wait Time: " << s.medianTime() << endl;
    cout << "Longest Student Wait Time: " << s.longestTime() << endl;
    cout << "Students Waiting Over Ten Minutes: " << s.overTenTime() << endl;
    cout << "\nWINDOW Calculations" << endl;
    cout << "Mean Window Idle Time: " << s.meanIdleTime() << endl;
    cout << "Longest Window Idle Time: " << s.longestIdleTime() << endl;
    cout << "Idle Time Over Five Minutes: " << s.idleOverFiveTime() << endl;

    return 0;
}