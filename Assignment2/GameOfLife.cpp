/*  Zachary Jagoda
    Student ID: 2274813
    Student Email: jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)

*/
#include "GameOfLife.h"
#include <iostream>

using namespace std;

Game::Game() {

}

Game::~Game() {

}

void Game::selectMode() {

}

void Game::classicMode() {

}

void Game::donutMode() {

}

void Game::mirrorMode() {

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