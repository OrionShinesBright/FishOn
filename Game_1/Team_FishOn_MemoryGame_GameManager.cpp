#include "Team_FishOn_MemoryGame_GameManager.h"

GameManager::GameManager() : currentPlayer(0){
    players[0] = Player();
    players[1] = Player();
    board = GameBoard();
}

void GameManager::startGame()
{
    board.initializeBoard();
    currentPlayer = 0;
}

void GameManager::processMove()
{
    //idk what this is
}

void GameManager::switchPlayer()
{
    if (currentPlayer == 0) currentPlayer = 1;
    else currentPlayer = 0;
}

bool GameManager::isGameOver()
{
    bool hasLost = false;
    if (hasLost)
        return true;
    else false;
}
