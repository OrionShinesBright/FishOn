#include "AIPlayer.h"
#include <cstdlib>
#include <ctime>

AIPlayer::AIPlayer(char aiSymbol, char playerSymbol)
    : aiSymbol(aiSymbol), playerSymbol(playerSymbol) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //randomizatiiioooooonnnnnnnnn
}

/* Ok so here goes basically the entire implemenattion of the AI
 * Everything, even the choice of ai difficulty is being handled here
 * You dont have to handle it in the caller functions.. rest easy
 * Also.. have left multiple comments throughout to help you..
 */
sf::Vector2i AIPlayer::getBestMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size) {
    //returns a vector of 2 ints.. corresponding to row and then column of the grid
    boardSize = size;
    sf::Vector2i bestMove(-1, -1);
    int bestScore = -1;

    // Priority 1: Win
    for (int r = 0; r < boardSize; r++) {
        for (int c = 0; c < boardSize; c++) {
            if (board[r][c] == ' ') {
                if (isWinningMove(board, r, c, aiSymbol)) //this is probably the best func I have written in my life
                    return {r, c};
            }
        }
    }

    // Priority 2: Block opponent
    for (int r = 0; r < boardSize; r++) {
        for (int c = 0; c < boardSize; c++) {
            if (board[r][c] == ' ') {
                if (isWinningMove(board, r, c, playerSymbol))
                    return {r, c};
            }
        }
    }

    // Priority 3: Strategic - noit so good really... my implememtation of this sucks
    for (int r = 0; r < boardSize; r++) {
        for (int c = 0; c < boardSize; c++) {
            if (board[r][c] == ' ') {
                int score = evaluatePosition(r, c);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {r, c};
                }
            }
        }
    }

    // Priority 4: Random lollllzzzzz
    if (bestMove.x == -1) {
        sf::Vector2i emptyCells[MAX_BOARD_SIZE * MAX_BOARD_SIZE];
        int count = 0;
        for (int r = 0; r < boardSize; r++) { //some realllly fancy iterations..
            for (int c = 0; c < boardSize; c++) {
                if (board[r][c] == ' ')
                    emptyCells[count++] = {r, c};
            }
        }
        if (count > 0)
            return emptyCells[std::rand() % count]; //seeded up above, in the constructor
    }

    return bestMove;
}

//This is EPIKKKKK
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

    //and now we check diagnoals.. dont forget to do this..
    //TODO: CHECK DISAGONALS
    
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

    //the general fallback false thingy
    return false;
}

//This was kinda cool, but I'm still unsure about the implementation, since maybe i should
//have evaluated for the other priority types too.. idk..
//if you want to, call it there too.. tho dont expectr much difference in playstyle..
int AIPlayer::evaluatePosition(int row, int col) {
    if (row == boardSize / 2 && col == boardSize / 2)
        return 3; // center
    if ((row == 0 || row == boardSize - 1) && (col == 0 || col == boardSize - 1))
        return 2; // corners
    return 1; // edges/sides
}
