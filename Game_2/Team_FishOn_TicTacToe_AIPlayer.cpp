#include "AIPlayer.h"
#include <cstdlib>
#include <ctime>

AIPlayer::AIPlayer(char aiSymbol, char playerSymbol)
    : aiSymbol(aiSymbol), playerSymbol(playerSymbol) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

sf::Vector2i AIPlayer::getBestMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size) {
    boardSize = size;
    sf::Vector2i bestMove(-1, -1);
    int bestScore = -1;

    // Priority 1: Win
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardSize; ++c) {
            if (board[r][c] == ' ') {
                if (isWinningMove(board, r, c, aiSymbol))
                    return {r, c};
            }
        }
    }

    // Priority 2: Block opponent
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardSize; ++c) {
            if (board[r][c] == ' ') {
                if (isWinningMove(board, r, c, playerSymbol))
                    return {r, c};
            }
        }
    }

    // Priority 3: Strategic
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardSize; ++c) {
            if (board[r][c] == ' ') {
                int score = evaluatePosition(r, c);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {r, c};
                }
            }
        }
    }

    // Priority 4: Random fallback
    if (bestMove.x == -1) {
        sf::Vector2i emptyCells[MAX_BOARD_SIZE * MAX_BOARD_SIZE];
        int count = 0;
        for (int r = 0; r < boardSize; ++r) {
            for (int c = 0; c < boardSize; ++c) {
                if (board[r][c] == ' ')
                    emptyCells[count++] = {r, c};
            }
        }
        if (count > 0)
            return emptyCells[std::rand() % count];
    }

    return bestMove;
}

bool AIPlayer::isWinningMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int row, int col, char symbol) {
    char tempBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    for (int r = 0; r < boardSize; ++r)
        for (int c = 0; c < boardSize; ++c)
            tempBoard[r][c] = board[r][c];

    tempBoard[row][col] = symbol;

    // Check row
    bool win = true;
    for (int c = 0; c < boardSize; ++c)
        if (tempBoard[row][c] != symbol)
            win = false;
    if (win) return true;

    // Check column
    win = true;
    for (int r = 0; r < boardSize; ++r)
        if (tempBoard[r][col] != symbol)
            win = false;
    if (win) return true;

    // Check main diagonal
    if (row == col) {
        win = true;
        for (int i = 0; i < boardSize; ++i)
            if (tempBoard[i][i] != symbol)
                win = false;
        if (win) return true;
    }

    // Check anti-diagonal
    if (row + col == boardSize - 1) {
        win = true;
        for (int i = 0; i < boardSize; ++i)
            if (tempBoard[i][boardSize - 1 - i] != symbol)
                win = false;
        if (win) return true;
    }

    return false;
}

int AIPlayer::evaluatePosition(int row, int col) {
    if (row == boardSize / 2 && col == boardSize / 2)
        return 3; // center
    if ((row == 0 || row == boardSize - 1) && (col == 0 || col == boardSize - 1))
        return 2; // corners
    return 1; // edges/sides
}
