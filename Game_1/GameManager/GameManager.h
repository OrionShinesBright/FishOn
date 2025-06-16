#pragma once
#include "GameBoard/GameBoard.h"
#include "Player/Player.h"

class GameManager
{
private:
	GameBoard board;
	Player players[2];
	int currentPlayer;

public:
	void startGame();
	void processMove();
	void switchPlayer();
	bool isGameOver();
};

