/*  Zachary Jagoda
    Student ID: 2274813
    Student Email: jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)

*/
#include "GameOfLife.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    Game g;

    g.selectSettings();
    
    g.createBoard();

    return 0;
}