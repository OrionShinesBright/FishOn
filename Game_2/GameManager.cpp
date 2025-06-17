#include "GameManager.h"

GameManager::GameManager()
{
	gameEnd = false;
	currentPlayer = 0;
}

void GameManager::updateWindow(RenderWindow& window)
{
	makeMove(window); //takes input, makes move, does win checks and switches to next player

}


void GameManager::makeMove(RenderWindow& window)
{
	//input

	//check if grid cell empty
	//if filled, return

	board.grid[i][j] = players[currentPlayer].getSymbol(); //mark grid cell with player symbol
	if (checkWinPlayer1())
	{
		endGameWin(0);
		return;
	}
	if (checkWinPlayer2())
	{
		endGameWin(1);
		return;
	}
	if (checkDraw())
	{
		endGameDraw();
		return;
	}

	//if game doesn't end, switch player
	switchPlayer();

}

void GameManager::endGameWin(int playerIndex)
{
	gameEnd = true;
	//player wins
}

void GameManager::endGameDraw()
{
	gameEnd = true;
	//draw
}

void GameManager::switchPlayer()
{
	if (currentPlayer == 0) currentPlayer = 1;
	else currentPlayer = 0;
}

bool GameManager::checkWinPlayer1() const
{
	return board.checkWin(players[0].getSymbol());
}

bool GameManager::checkWinPlayer2() const
{
	return board.checkWin(players[1].getSymbol());
}



bool GameManager::checkDraw() const
{
	if (board.isFull() && !(checkWinPlayer1()) && !(checkWinPlayer2()))
		return true;
	return false;

}


