#pragma once
#include <SFML/System.hpp>

#define MAX_BOARD_SIZE 5

class AIPlayer {
private:
    char aiSymbol, playerSymbol;
    int boardSize;
    //I know what you're thinking.. yes.. these are private funcs.. stop nosing around..
    //functions have the right to privaxcy too
    bool isWinningMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int row, int col, char symbol);
    int evaluatePosition(int row, int col);

public:
    AIPlayer(char aiSymbol, char playerSymbol);
    //this function is beyond me.. but it was necessary.. i had to do it
    sf::Vector2i getBestMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);
};
