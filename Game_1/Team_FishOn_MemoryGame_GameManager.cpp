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
		if (attempts[currentPlayer = 0]) players[currentPlayer].updateScore(100); //this line prevents integer division by zero
		else
		{
			players[currentPlayer].updateScore((100 / attempts[currentPlayer])); //Different value of scores can be done by considering number of attempts
			attempts[currentPlayer] = 0;
		}
	}
	else {
		attempts[currentPlayer]++;
		//sf::sleep(sf::seconds(2)); // 1-second delay to show the flipped cards
		//first.flip();
		//second.flip();
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


void GameManager::drawGame(RenderWindow& window)
{
	//draw background
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920, 1080));
	background.setPosition(0, 0);
	background.setFillColor(Color::Blue);
	window.draw(background);


	players[0].displayStats(window, 0);
	players[1].displayStats(window, 1);



	board.Draw(window);
}
