#include "Team_FishOn_MemoryGame_GameManager.h"

void GameManager::startGame()
{
	board.initializeBoard();
	currentPlayer = 0;
}

void GameManager::processMove()
{

}

void GameManager::switchPlayer()
{
	if (currentPlayer == 0) currentPlayer = 1;
	else currentPlayer = 0;
}

bool GameManager::isGameOver()
{
	bool gameEnded = false;
	if (gameEnded) {
		return true;
	}
	return false;
}
