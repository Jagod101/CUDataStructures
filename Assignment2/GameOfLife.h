/*  Ashley Wood and Zachary Jagoda
    Student ID: 2271425 and Student ID: 2274813
    Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)
*/

#include <iostream>

using namespace std;

class Game {
    private:
        int boardLength, boardWidth;
        string outputType = "";
        string outString = "";
        ofstream outputFile;
        
    public:
        Game(); //Constructor
        ~Game(); //Deconstructor

        void selectSettings();
        void selectMode(); //Select Game Mode
        
        int classicMode(int boardLength, int boardWidth, char**& board); //Classic Game Mode
        int donutMode(int boardLength, int boardWidth, char**& board); //Donut Game Mode
        int mirrorMode(int boardLength, int boardWidth, char**& board); //Mirror Game Mode

        void createRandomBoard(int& boardLength, int& boardWidth, char**& board); //Create Game Board
        void createFileBoard(ifstream& inputFile, char**& board);

        void printOptions(); 
};
