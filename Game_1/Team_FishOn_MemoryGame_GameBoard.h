#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;

#include "Team_FishOn_MemoryGame_Card.h"
#include <cstdlib>
#include <ctime>

using namespace std;

/*****************************************************
* TEAM: FishOn										 
* MEMBERS:		1. SYED HAIDER ALI JAFRI		24L-0882		 
*			2. WALEED BIN OMER			24L-0571		 
*			3. MUHAMMAD RAFAY			24L-0649	 
*	   MEMORY MATCHING GAME - IDEAL HACKATHON		 
*****************************************************/

const int MAX_SIZE = 8;

class GameBoard
{
private:
	Card cards[MAX_SIZE][MAX_SIZE];
	int rows, cols; //both of these variables depend on the difficulty. Initialized using setters

public:
	GameBoard(int r = 0, int c = 0) : rows(r), cols(c) {}
	void initializeBoard();
	void shuffleCards();
	bool checkWin();
	void Draw(RenderWindow& window); //SFML

	Card& getCards(int r, int c) {
		return cards[r][c];
	}
	inline int getRows() { return rows; }
	inline int getCols() { return cols; }

	/*
	void setCards(int row, int col, int val)
		//Sets one element of the cards array, by taking matrix indices
	{
		if (!(row < MAX_SIZE && row >= 0 && col >= 0 && col < MAX_SIZE)) {
			std::cout << "Enter a valid matrix address!\n";
			return;
		}
		cards[row][col] = Card(val);
	}
	*/
	inline void setRows(int row) { rows = row; }
	inline void setCols(int col) { cols = col; }
};

