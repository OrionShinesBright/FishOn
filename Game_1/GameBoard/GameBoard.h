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

	Card getCards() {
		return cards;
	}
	inline int getRows() { return rows; }
	inline int getCols() { return cols; }

	void setCards(int row, int col, int val)
		//Sets one element of the cards array, by taking matrix indices
	{
		if (!(row < MAX_SIZE && row >= 0 && col >= 0 && col < MAX_SIZE)) {
			std::cout << "Enter a valid matrix address!\n";
			return;
		}
		cards[row][col] = val;
	}
	inline void setRows(int row) { rows = row; }
	inline void setCols(int col) { cols = col; }
};

