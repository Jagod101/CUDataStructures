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

    public:
        Game(); //Constructor
        ~Game(); //Deconstructor

        void selectSettings();
        void selectMode(); //Select Game Mode
        
        int classicMode(); //Classic Game Mode
        int donutMode(); //Donut Game Mode
        int mirrorMode(); //Mirror Game Mode

        void createRandomBoard(); //Create Game Board
        void createFileBoard();

        void printOptions(); 
};
