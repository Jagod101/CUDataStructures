#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include "GameOfLife.h"

using namespace std;

Game::Game() {

}

Game::~Game() {

}

void Game::gameSettings(string& file, int& boardLength, int& boardWidth) {
    string setting = "";
    bool correctAnswer = false;

    while(correctAnswer == false){
        cout << "Would you like to have a random board or submit your own file? (type 'random' or 'file') \n" << endl;
        cin >> setting;
    
        if ((setting == "random") || (setting == "Random")) {
            double density;

            createBoard(boardLength, boardWidth, density);

            char** currentBoard = new char*[boardLength];
            for(int i = 0; i < boardLength; ++i) {
                currentBoard[i] = new char[boardWidth];
            }

            setBoard(boardLength, boardWidth, density, currentBoard);
            startGame(boardLength, boardWidth, currentBoard);

            correctAnswer = true;
        }
        else if ((setting == "file") || (setting == "File")) {
            cout << "What is the name of the .txt file you want to use\n";
            cin >> file;
            
            createBoard(file.c_str(), boardLength, boardWidth);

            char** currentBoard = new char*[boardLength];
            for(int i = 0; i < boardLength; ++i) {
                currentBoard[i] = new char[boardWidth];
            }

            setBoard(file.c_str(), currentBoard);
            startGame(boardLength, boardWidth, currentBoard);

            correctAnswer = true;
        }
        else {
            cout << "That selection is not applicable. Try one of the given selections \n" << endl;
            correctAnswer = false;
        }
    }
}

void Game::createBoard(int& boardLength, int& boardWidth, double& density) {
    bool correctInput = false;

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
        cin >> density;

        if((density >= 0.0) && (density <= 1.0)){
            correctInput = true;
        }
        else {
            cout << "\nPlease Enter a Valid Number";
            correctInput = false;
        }
    }
}

void Game::createBoard(string file, int& boardLength, int& boardWidth) {
    ifstream inputStream;
	inputStream.open(file.c_str());
	inputStream >> boardLength >> boardWidth;
	inputStream.close();
}

void Game::setBoard(int boardLength, int boardWidth, double density, char**& board) {
    int numOfCells = round((boardLength*boardWidth)*density);

    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            board[i][j] = '-';
        }
    }

    srand(time(NULL));

    for (int k = 0; k < numOfCells; ++k) {
        
        randLength = rand() % (boardLength);
        randWidth = rand() % (boardWidth);
        int numCells = 1;

        while(numCells > 0){
            if (board[randLength][randWidth] == '-') {
                board[randLength][randWidth] = 'X';
                numCells--;
            }
            else {
                randLength = rand() % (boardLength);
                randWidth = rand() % (boardWidth);
            }
        }   
    }
}

void Game::setBoard(string file, char**& board) {
    int a, z; //a (ashley) == boardLength AND z (zach) == boardWidth
    char c;

    ifstream inputStream;
    inputStream.open(file.c_str());
    inputStream >> a >> z;

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < z; ++j) {
            inputStream >> c;
            board[i][j] = c;
        }
    }

    inputStream.close();
}

int Game::classicMode(int boardLength, int boardWidth, char**& board) {
    //Creates Secondary Board based off of the First Board Dimensions
    char** nextGen = new char*[boardLength];
    
    for (int i = 0; i < boardLength; ++i) {
        nextGen[i] = new char[boardWidth];
    }

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
            if (count < 2) {
                //If there are One of Fewer Neighbors --> Death
                nextGen[i][j] = '-';
            }
            else if (count == 2) {
                //If there are exactly Two Neighbors --> No Change (Stablized)
                nextGen[i][j] = board[i][j];
            }
            else if (count == 3) {
                //If there are Three Neighbors + Empty Cell --> Birth of Cell
                nextGen[i][j] = 'X';
            }
            else if (count > 3) {
                //If there are Four or More Neighbors --> Death
                nextGen[i][j] = '-';
            }
        }
    }
    bool stable = true;

    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            if (nextGen[i][j] != board[i][j]) {
                stable = false;
            }
        }
    }

    if (stable == true) {
        cout << "The World has Stabilized" << endl;
        return 1;
    }
    else {
        for (int i = 0; i < boardLength; ++i) {
            for (int j = 0; j < boardWidth; ++j) {
                board[i][j] = nextGen[i][j];
            }
        }

        return 0;
    }
}

int Game::donutMode(int boardLength, int boardWidth, char**& board) {
    //Creates Secondary Board based off of the First Board Dimensions
    char** nextGen = new char*[boardLength];
    
    for (int i = 0; i < boardLength; ++i) {
        nextGen[i] = new char[boardWidth];
    }
    
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
                if(board[i][0] == 'X') count++;
                if(board[boardLength-1][j] == 'X') count++;
                if(board[boardLength-1][j-1] == 'X') count++;
                if(board[i][0] == 'X') count++;
                if(board[i+1][0] == 'X') count++;
			}
			else if (i == (boardLength - 1 ) && j == (boardWidth - 1)) {
				if(board[i-1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[0][j-1] == 'X') count++;
				if(board[0][j] == 'X') count++;
				if(board[0][0] == 'X') count++;
				if(board[boardLength-1][0] == 'X') count++;
				if(board[boardLength-2][0] == 'X') count++;
			}
			else if (i == (boardLength - 1) && j == 0) {
				if(board[i-1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
                if(board[i-1][j+1] == 'X') count++;
                if(board[0][0] == 'X') count++;
				if(board[0][1] == 'X') count++;
				if(board[0][boardWidth-1] == 'X') count++;
				if(board[boardLength-1][boardWidth-1] == 'X') count++;
				if(board[boardLength-1][boardWidth-2] == 'X') count++;
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
            if (count < 2) {
                //If there are One of Fewer Neighbors --> Death
                nextGen[i][j] = '-';
            }
            else if (count == 2) {
                //If there are exactly Two Neighbors --> No Change (Stablized)
                nextGen[i][j] = board[i][j];
            }
            else if (count == 3) {
                //If there are Three Neighbors + Empty Cell --> Birth of Cell
                nextGen[i][j] = 'X';
            }
            else if (count > 3) {
                //If there are Four or More Neighbors --> Death
                nextGen[i][j] = '-';
            }
        }
    }

    bool stable = true;
    
    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            if (nextGen[i][j] != board[i][j]) {
                stable = false;
            }
        }
    }

    if (stable == true) {
        cout << "The World has Stabilized" << endl;
        return 1;
    }
    else {
        for (int i = 0; i < boardLength; ++i) {
            for (int j = 0; j < boardWidth; ++j) {
                board[i][j] = nextGen[i][j];
            }
        }

        return 0;
    }
}

int Game::mirrorMode(int boardLength, int boardWidth, char**& board) {
    //Creates Secondary Board based off of the First Board Dimensions
    char** nextGen = new char*[boardLength];
    
    for (int i = 0; i < boardLength; ++i) {
        nextGen[i] = new char[boardWidth];
    }
    
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
            if (count < 2) {
                //If there are One of Fewer Neighbors --> Death
                nextGen[i][j] = '-';
            }
            else if (count == 2) {
                //If there are exactly Two Neighbors --> No Change (Stablized)
                nextGen[i][j] = board[i][j];
            }
            else if (count == 3) {
                //If there are Three Neighbors + Empty Cell --> Birth of Cell
                nextGen[i][j] = 'X';
            }
            else if (count > 3) {
                //If there are Four or More Neighbors --> Death
                nextGen[i][j] = '-';
            }
        }
    }

    bool stable = true;
    
    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            if (nextGen[i][j] != board[i][j]) {
                stable = false;
            }
        }
    }

    if (stable == true) {
        cout << "The World has Stabilized" << endl;
        return 1;
    }
    else {
        for (int i = 0; i < boardLength; ++i) {
            for (int j = 0; j < boardWidth; ++j) {
                board[i][j] = nextGen[i][j];
            }
        }

        return 0;
    }
}

void Game::startGame(int& boardLength, int& boardWidth, char**& board) {
    //string for Game Mode input
    string gameMode = "";
    //string for Print Option input
    string outputType = "";
    //continueOn boolean for Game Mode
    bool continueOn = true;
    //wrongChoice boolean for Print Options
    bool wrongChoice = true;

    while ( continueOn == true ) {
        cout << "Select Game Mode\n1. Classic\n2. Donut\n3. Mirror\n";
        cin >> gameMode;

        if ((gameMode == "classic")||(gameMode == "Classic")||(gameMode == "1")) {
            continueOn = false;
        }
        else if ((gameMode == "donut")||(gameMode == "Donut")||(gameMode == "2")) {
            continueOn = false;
        }
        else if ((gameMode == "mirror")||(gameMode == "Mirror")||(gameMode == "3")) {
            continueOn = false;
        }
        else {
            cout << "Please Enter a Valid Option Using the Spelling as Listed\n";
            continueOn = true;
        }
    }
    
    while(wrongChoice == true) {
        cout << "How would you like your data to be printed?\n";
        cout << "1. Pause\n2. Enter\n3. File\n";
        cin >> outputType;

        if ((outputType == "pause")||(outputType == "Pause")||(outputType == "1")) {
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
    
    if ((outputType == "pause")||(outputType == "Pause")||(outputType == "1")||(outputType == "enter")||(outputType == "Enter")||(outputType == "2")) {
        cout << "Gen 0" << endl;
        printBoardIn(boardLength, boardWidth, board);

        int stable = 0;
        int gen = 1;

        cout << "Press Enter to Start";

        while(stable == 0) {
            if ((gameMode == "classic")||(gameMode == "Classic")||(gameMode == "1")) {
                stable = classicMode(boardLength, boardWidth, board);
            }
            else if ((gameMode == "donut")||(gameMode == "Donut")||(gameMode == "2")) {
                stable = donutMode(boardLength, boardWidth, board);
            }
            else if ((gameMode == "mirror")||(gameMode == "Mirror")||(gameMode == "3")) {
                stable = mirrorMode(boardLength, boardWidth, board);
            }

            if (stable == 1) {
                cout << "The Simulation is Complete" << endl;
                break;
            }

            cout << "Generation: " << gen << endl;
            printBoardIn(boardLength, boardWidth, board);
            gen++;

            if ((outputType == "pause")||(outputType == "Pause")||(outputType == "1")) {
                sleep(2);
            }
            else if ((outputType == "enter")||(outputType == "Enter")||(outputType == "2")) {
                cout << "Press Enter to Continue" << endl;
                cin.get();
            }
        }
    }

    else if ((outputType == "file")||(outputType == "File")||(outputType == "3")) {
        ofstream outFile("GameOfLife.txt");
        int stable = 0;
        int gen = 1;

        while(stable == 0) {
            if ((gameMode == "classic")||(gameMode == "Classic")||(gameMode == "1")) {
                stable = classicMode(boardLength, boardWidth, board);
            }
            else if ((gameMode == "donut")||(gameMode == "Donut")||(gameMode == "2")) {
                stable = donutMode(boardLength, boardWidth, board);
            }
            else if ((gameMode == "mirror")||(gameMode == "Mirror")||(gameMode == "3")) {
                stable = mirrorMode(boardLength, boardWidth, board);
            }

            if (stable == 1) {
                cout << "The Simulation has been printed to the file" << endl;
                break;
            }

            outFile << "Gen " << gen << endl;
            printBoardOut(boardLength, boardWidth, board, outFile);
            gen++;
        }
    }
}

void Game::printBoardIn(int boardLength, int boardWidth, char** board) {
    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++i) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void Game::printBoardOut(int boardLength, int boardWidth, char** board, ofstream& file) {
    for (int i = 0; i < boardLength; ++i) {
        for (int j = 0; j < boardWidth; ++i) {
            file << board[i][j];
        }
        file << endl;
    }
}