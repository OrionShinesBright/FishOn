#pragma once
#include <SFML/System.hpp>

class AIPlayer {
public:
    AIPlayer(char aiSymbol, char playerSymbol);
    sf::Vector2i getBestMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);

private:
    char aiSymbol, playerSymbol;
    int boardSize;

    bool isWinningMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int row, int col, char symbol);
    int evaluatePosition(int row, int col);
};
