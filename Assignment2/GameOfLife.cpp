/*  Ashley Wood and Zachary Jagoda
    Student ID: 2271425 and Student ID: 2274813
    Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)
*/

#include <iostream>
#include "GameOfLife.h"
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;

Game::Game() {
    string outputType = "";
    string outString = "";
    ofstream outputFile;
}
Game::~Game() {

}
//creates a board that will be used when the user wants a random board
void Game::createRandomBoard(int& boardLength, int& boardWidth, double& densityNumber){
    double densityNumber = 0.0;
    bool correctInput = false;
    int numOfCells = 0;
    int randLength = 0;
    int randWidth = 0;

    //Ask the User for Board Length (Rows)
    cout << "\nWhat is the length of your board? " << endl;
    cin >> boardLength;

    //If the User inputs a number less than or equal to One, ask for a greater number
    while (boardLength <= 1) {
        cout << "\nPlease Enter a Number Greater Than One: ";
        cin >> boardLength;
    }

    //Ask the User for Board Width (Columns)
    cout << "\nWhat is the width of your board? " << endl;
    cin >> boardWidth;
    
    //If the User inputs a number less than or equal to One, ask for a greater number
    while (boardWidth <= 1) {
        cout << "\nPlease Enter a Number Greater Than One: ";
        cin >> boardWidth;
    }

    //Ask the User for Density with Invalid Input Catch 
    while (correctInput == false){
        cout << "\nEnter the density of the board (between 0 and 1): " << endl;
        cin >> densityNumber;
        if((densityNumber >= 0.0) && (densityNumber <= 1.0)){
            correctInput = true;
        }
        else {
            cout << "\nPlease Enter a Valid Number";
            correctInput = false;
        }
    }

    //Declare Board Dimensions for Array 'board'
    char board[boardLength][boardWidth];
    //Declare numOfCells for later calculation of Cell Population
    numOfCells = round((boardLength*boardWidth)*densityNumber);

    //Initialize board with Blank Spaces
    for (int i = 0; i < boardLength; i++){
        for (int j = 0; j < boardWidth; j++){
            board[i][j] = '-';
        }
    }

    srand(time(NULL));

    for (int k = 0; k < numOfCells; k++){
        
        randLength = rand() % (boardLength);
        randWidth = rand() % (boardWidth);
        int numCells = 1;

        while(numCells > 0){
            if(board[randLength][randWidth] == '-'){
                board[randLength][randWidth] = 'X';
                numCells--;
            }else{
                randLength = rand() % (boardLength);
                randWidth = rand() % (boardWidth);
            }
        }   
    }
    selectMode();
    // for (int l = 0; l < boardLength; l++){
    //  for (int m = 0; m < boardWidth; m++){
    //      cout << board[l][m];
    //  }
    //  cout << "\n";
    // }    
}

void Game::createFileBoard(ifstream& inputfile){
    int boardLength = 0;
    int boardWidth = 0;
    

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
            continueOn = true;
        }
    }
}
//asks the user if they want a random board or to submit a map
//choose how you want the game to be printed (in a file, with a pause, or by enter key)
void Game::printOptions() {
    if ((outputType == "pause")||(outputType == "Pause")||(outputType == "1")) {
        sleep(1);
    }
    else if ((outputType == "enter")||(outputType == "Enter")||(outputType == "2")) {
        cout << "Please Press ENTER to Continue\n";
        cin.ignore();
    }
    else if ((outputType == "file")||(outputType == "File")||(outputType == "3")) {
       
    }
}

int Game::classicMode() {
//Need to Create Second Board to Base Off First Board
    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            int count = 0;
            if (i == 0 && j == 0) {
                if (board[i+1][j] == 'X') count++;
                if (board[i][j+1] == 'X') count++;
                if (board[i+1][j+1] == 'X') count++;
            }
            else if (i == 0 && j == (boardWidth - 1)) {
                if (board[i+1][j] == 'X') count++;
                if (board[i][j-1] == 'X') count++;
                if (board[i+1][j-1] == 'X') count++;
            }
            else if (i == (boardLength - 1) && j == 0) {
                if (board[i-1][j] == 'X') count++;
                if (board[i][j+1] == 'X') count++;
                if (board[i-1][j+1] == 'X') count++;
            }
            else if (i == (boardLength - 1) && j == (boardWidth - 1)) {
                if (board[i-1][j] == 'X') count++;
                if (board[i][j-1] == 'X') count++;
                if (board[i-1][j-1] == 'X') count++;
            }
            //Checks the Sides of the Board
            else if (i == 0) {
                if (board[i+1][j] == 'X') count++;
                if (board[i][j+1] == 'X') count++;
                if (board[i+1][j+1] == 'X') count++;
                if (board[i][j-1] == 'X') count++;
                if (board[i+1][j-1] == 'X') count++;
            }
            else if (j == 0) {
                if (board[i-1][j] == 'X') count++;
                if (board[i+1][j] == 'X') count++;
                if (board[i][j+1] == 'X') count++;
                if (board[i+1][j+1] == 'X') count++;
                if (board[i-1][j+1] == 'X') count++;
            }
            else if (i == (boardLength - 1)) {
                if (board[i-1][j] == 'X') count++;
                if (board[i][j+1] == 'X') count++;
                if (board[i-1][j+1] == 'X') count++;
                if (board[i][j-1] == 'X') count++;
                if (board[i-1][j-1] == 'X') count++;
            }
            else if(j == (boardWidth - 1)) {
                if (board[i-1][j] == 'X') count++;
                if (board[i+1][j] == 'X') count++;
                if (board[i][j-1] == 'X') count++;
                if (board[i+1][j-1] == 'X') count++;
                if (board[i-1][j-1] == 'X') count++;
            }
            else {
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i-1][j] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i+1][j-1] =='X') count++;
				if(board[i-1][j+1] == 'X') count++;
			}
        }
    }
}

int Game::donutMode() {
    for(int i = 0; i < boardLength; ++i){
		for(int j = 0; j < boardWidth; ++j){
			int count = 0; 								
			if (i == 0 && j == 0) { 						
				if(board[i+1][j] == 'X') count++; 		
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[boardLength-1][j] == 'X') count++; //Bottom of Row (boardLength), same Column (boardWidth)
				if(board[boardLength-1][j+1] == 'X') count++; //Bottom Row (boardLength) Bottom Column+1 (boardWidth+1)
				if(board[boardLength-1][boardWidth-1] == 'X') count++; //Opposite Corner
				if(board[i][boardWidth-1] == 'X') count++; //Opposite Side
				if(board[i+1][boardWidth-1] == 'X') count++; //Opposite Side and Down One
			}
			else if (i == 0 && j == (boardWidth - 1)) {
				if(board[i+1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i+1][j-1] == 'X') count++;
				if(board[boardLength-1][j] == 'X') count++;
				if(board[boardLength-1][j-1] == 'X') count++;
				if(board[boardLength-1][0] == 'X') count++;
				if(board[i][0] == 'X') count++; //Opposite Corner
				if(board[i+1][0] == 'X') count++;
			}
			else if (i == (boardLength - 1 ) && j == (boardWidth - 1)) {
				if(board[i-1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[0][j-1] == 'X') count++;
				if(board[0][j] == 'X') count++;
				if(board[0][0] == 'X') count++;
				if(board[i][0] == 'X') count++;
				if(board[i-1][0] == 'X') count++;
			}
			else if (i == (boardLength - 1) && j == 0) {
				if(board[i-1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
				if(board[0][j] == 'X') count++;
				if(board[0][j+1] == 'X') count++;
				if(board[0][boardWidth-1] == 'X') count++;
				if(board[i-1][boardWidth-1] == 'X') count++;
				if(board[i][boardWidth-1] == 'X') count++;
			}
			else if (j == 0) { 							
				if(board[i-1][j] == 'X') count++;
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
				if(board[i-1][boardWidth-1] == 'X') count++;
				if(board[i][boardWidth-1] == 'X') count++;
				if(board[i+1][boardWidth-1] == 'X') count++;
			}
			else if (i == 0) {
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i+1][j-1] == 'X') count++;
				if(board[boardLength-1][j-1] == 'X') count++;
				if(board[boardLength-1][j] == 'X') count++;
				if(board[boardLength-1][j+1] == 'X') count++;
            }
            else if (i == (boardLength - 1)) {
				if(board[i-1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[0][j-1] == 'X') count++;
				if(board[0][j] == 'X') count++;
				if(board[0][j+1] == 'X') count++;
			}
			else if (j == (boardWidth - 1)) {
				if(board[i-1][j] == 'X') count++;
				if(board[i+1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i+1][j-1] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i-1][0] == 'X') count++;
				if(board[i][0] == 'X') count++;
				if(board[i+1][0] == 'X') count++;
			}
			else {
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i-1][j] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i+1][j-1] =='X') count++;
				if(board[i-1][j+1] == 'X') count++;
			}
        }
    }
}

int Game::mirrorMode() {
    for(int i = 0; i < boardLength; ++i){
		for(int j = 0; j < boardWidth; ++j){
            int count = 0; 	
            						
            /* If count is ++ there is a singular neighbor with no reflection
             * If count is += 2 this accounts for the neighbor and the reflection of neighbor
             * If count is += 3 this accounts for own reflection in the corner
             */

			if (i == 0 && j == 0) { 						
				if(board[i+1][j] == 'X') count+=2; 		
				if(board[i][j+1] == 'X') count+=2;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j] == 'X') count+=3;
			}
			else if (i == 0 && j == (boardWidth - 1)) {
				if(board[i+1][j] == 'X') count+=2;
				if(board[i][j-1] == 'X') count+=2;
				if(board[i+1][j-1] == 'X') count++;
				if(board[i][j] == 'X') count+=3;
			}
			else if (i == (boardLength - 1 ) && j == (boardWidth - 1)) {
				if(board[i-1][j] == 'X') count+=2;
				if(board[i][j-1] == 'X') count+=2;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i][j] == 'X') count+=3;
			}
			else if (i == (boardLength - 1) && j == 0) {
				if(board[i-1][j] == 'X') count+=2;
				if(board[i][j+1] == 'X') count+=2;
				if(board[i-1][j+1] == 'X') count++;
				if(board[i][j] == 'X') count+=3;
            }
            else if (i == 0) {
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count+=2;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count+=2;
				if(board[i+1][j-1] == 'X') count++;
				if(board[i][j] == 'X') count++;
            }
			else if (j == 0) { 							
				if(board[i-1][j] == 'X') count+=2;
				if(board[i+1][j] == 'X') count+=2;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
				if(board[i][j] == 'X') count++;
			}
            else if (i == (boardLength - 1)) {
				if(board[i-1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count+=2;
				if(board[i-1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count+=2;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i][j] == 'X') count++;
			}
			else if (j == (boardWidth - 1)) {
				if(board[i-1][j] == 'X') count+=2;
				if(board[i+1][j] == 'X') count+=2;
				if(board[i][j-1] == 'X') count++;
				if(board[i+1][j-1] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i][j] == 'X') count++;
			}
			else {
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i-1][j] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i+1][j-1] =='X') count++;
				if(board[i-1][j+1] == 'X') count++;
            }
        }
    }
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
