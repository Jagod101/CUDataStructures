#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Game {
	private:

    public:
        //Constructor
        Game();
        //Deconstructor
		~Game();

        
		void gameSettings(string& inputFile, int& boardLength, int& boardWidth);

        //
		void createBoard(int& boardLength, int& boardWidth, double& density);
        //Takes in intergers from given File
        void createBoard(string inputFile, int& rows, int& boardWidth);

        //Sets the Board from variables given by user
        void setBoard(int boardLength, int boardWidth, double density, char**& board);
        //Sets the Board from a File
        void setBoard(string inputFile, char**& board);

        //Classic Mode
        int classicMode(int boardLength, int boardWidth, char**& board);
        //Donut (Doughnut) Mode
        int donutMode(int boardLength, int boardWidth, char**& board);
        //Mirror Mode
		int mirrorMode(int boardLength, int boardWidth, char**& board);

        void startGame(int& boardLength, int& boardWidth, char**& board);
        //Prints the Board in the Terminal
        void printBoardIn(int boardLength, int boardWidth, char** board);
        //Prints the Board OUT to a File
		void printBoardOut(int boardLength, int boardWidth, char** board, ofstream& outputFile);
};