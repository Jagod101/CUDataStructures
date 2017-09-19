/*  Zachary Jagoda
    Student ID: 2274813
    Student Email: jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)

*/
#include "GameOfLife.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game() {

}

Game::~Game() {

}

void Game::selectMode() {
    string mode = "";
    bool contunieOn = true;

    while ( continueOn == true ) {

        cout << "Select Game Mode\n1. Classic\n2. Donut\n3. Mirror\n";
        cin >> string;

        if ((mode == "classic")||(mode == "Classic")) {
            classicMode();
            continueOn = false;
        }

        else if ((mode == "donut")||(mode == "Donut")) {
            donutMode();
            continueOn = false;
        }

        else if ((mode == "mirror")||(mode == "Mirror")) {
            mirrorMode();
            continueOn = false;
        }

        else {
            cout << "Please Enter a Valid Option Using the Spelling as Listed\n";
            continue;
        }
    }
}

void Game::classicMode() {
    cout << "Classic Mode\n";
    return 0;
}

void Game::donutMode() {
    cout << "Donut Mode\n";
    return 0;
}

void Game::mirrorMode() {
    cout << "Mirror Mode";
    return 0;
}

void Game::createBoard() {
    int boardLength = 0;
    int boardWidth = 0;

    cout << "What is the Length of your Board?\n";
    cin >> boardLength;

    cout << "What is the Width of your Board?\n";
    cin >> boardWidth;

    for (int i = 0; i < boardLength; i++) {
        for (int j = 0; j < boardWidth; j++) {
            cout << " - ";
        }
        cout << "\n";
    }
}