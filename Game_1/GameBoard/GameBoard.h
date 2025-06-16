#pragma once
#include "Card/Card.h"

class GameBoard
{
private:
	Card cards[MAX_SIZE][MAX_SIZE];
	int rows, cols;

public:
	void initializeBoard();
	void shuffleCards();
	bool checkWin();
	void draw();
};
