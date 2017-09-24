/*  Zachary Jagoda
    Student ID: 2274813
    Student Email: jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)
*/
#include "GameOfLife.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Game::Game() {
    string outputType = "";
}

Game::~Game() {
}

void Game::createRandomBoard() {
    int boardLength = 0;
    int boardWidth = 0;
    double densityNumber = 0.0;
    int numOfCells = 0;
    bool correctInput = false;

    cout << "What is the length of your board? \n" << endl;
    cin >> boardLength;

    cout << "What is the width of your board? \n" << endl;
    cin >> boardWidth;

    while (correctInput == false) {
        cout << "Give me a number between 0 and 1 \n" << endl;
        cin >> densityNumber;

        if ((densityNumber >= 0.0) && (densityNumber <= 1.0)) {
            correctInput = true;
        }
        else {
            correctInput = false;
        }
    }

    numOfCells = (boardLength * boardWidth) * densityNumber;

    for (int i = 0; i < boardLength; i++) {
        for (int j = 0; j < boardWidth; j++) {
            char board[i][j] = {{-}};
        }
    }

    for (int k = 0; k < numOfCells; k++) {

    }
}

void Game::createFileBoard(ifstream& inputFile) {
    int boardLength = 0;
    int boardWidth = 0;

    //Assign Items from File to Variables
}

void Game::selectMode() {
    string mode = "";
    bool continueOn = true;

    while ( continueOn == true ) {

        cout << "Select Game Mode\n1. Classic\n2. Donut\n3. Mirror\n";
        cin >> mode;

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

void Game::printOptions() {
    if ((outputType == "pause")||(outputType == "Pause")||(outputType == "1")) {
        system("pause");
    }
    else if ((outputType == "enter")||(outputType == "Enter")||(outputType == "2")) {
        cout << "Please Press ENTER to Continue\n";
        cin.ignore();
    }
    else if ((outputType == "file")||(outputType == "File")||(outputType == "3")) {
       
    }
}

void Game::classicMode() {
    cout << "Classic Mode\n";
}

void Game::donutMode() {
    cout << "Donut Mode\n";
}

void Game::mirrorMode() {
    cout << "Mirror Mode\n";
}

void Game::selectSettings() {
    string setting = "";
    bool correctAnswer = false;
    bool wrongChoice = true;
    
    while(wrongChoice == true) {
        cout << "How would you like your data to be printed?\n";
        cout << "1. Pause\n 2. Enter\n 3. File\n";
        cin >> outputType;

        if ((outputType == "pause")||(outputType == "Pause")|| (outputType == "1")) {
            wrongChoice = false;
        }
        else if ((outputType == "enter")||(outputType == "Enter")||(outputType == "2")) {
            wrongChoice = false;
        }
        else if ((outputType == "file")||(outputType == "File")||(outputType == "3")) {
            wrongChoice = false;
        }
        else {
            cout << "Please Enter a Valid Option\n";
            wrongChoice = true;
        }
    }

    while(correctAnswer == false){
        cout << "Would you like to have a random board or submit your own file? (type 'random' or 'file') \n" << endl;
        cin >> setting;
    
        if ((setting == "random") || (setting == "Random")) {
            createRandomBoard();
            correctAnswer = true;
        }
        else if ((setting == "file")||(setting == "File")) {
            string fileName;
            cout << "What is the name of the .txt file you want to use\n";
            cin >> fileName;
            
            ifstream inputFile
            inputFile.open(fileName.c_str());

            createFileBoard(inputFile);
            correctAnswer = true;
        }
        else {
            cout << "That selection is not applicable. Try one of the given selections \n" << endl;
            correctAnswer = false;
        }
    }
}
