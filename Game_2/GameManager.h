#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Board.h"
#include "Player.h"

using namespace sf;

class GameManager
{
private:
	Board board;
	Player players[2];
	int currentPlayer;
	bool gameEnd;

public:

	GameManager();

	void updateWindow(RenderWindow& window);

	void makeMove(RenderWindow& window);

	void endGameWin(int playerIndex);
	void endGameDraw();

	void switchPlayer();

	bool checkWinPlayer1() const;
	bool checkWinPlayer2() const;
	bool checkDraw() const;

};

