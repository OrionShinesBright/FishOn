#include "Team_FishOn_MemoryGame_GameManager.h"
#include <fstream>


void GameManager::startGame(int rows, int cols)
{
	board.setRows(rows);
	board.setCols(cols);
	board.initializeBoard();
	std::ofstream out("settings.txt");
	if (out.is_open()) {
		out << "Grid Size: " << rows << "x" << cols << "\n";
		out.close();
	}
	currentPlayer = 0;
}

void GameManager::processMove(int r1, int c1, int r2, int c2)
{

	Card& first = board.getCards(r1, c1);
	Card& second = board.getCards(r2, c2);

	if (first.getIsFlipped() || second.getIsFlipped()) return;

	first.flip();
	second.flip();

	if (first.checkMatch(second)) {
		players[currentPlayer].updateScore((100 / attempts[currentPlayer])); //Different value of scores can be done by considering number of attempts
		attempts[currentPlayer] = 0;
	}
	else {
		attempts[currentPlayer]++;
		switchPlayer();
	}
}

void GameManager::switchPlayer()
{
	if (currentPlayer == 0) currentPlayer = 1;
	else currentPlayer = 0;
}

bool GameManager::isGameOver()
{
	bool gameEnded = false;
	gameEnded = board.checkWin();
	if (gameEnded) {
		return true;
	}
	return false;
}
