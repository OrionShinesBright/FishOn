#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Team_FishOn_MemoryGame_GameBoard.h"
#include "Team_FishOn_MemoryGame_Player.h"

using namespace sf;

/*****************************************************
* TEAM: FishOn										 
* MEMBERS:		1. SYED HAIDER ALI JAFRI		24L-0882		 
*			2. WALEED BIN OMER			24L-0571		 
*			3. MUHAMMAD RAFAY			24L-0649	 
*	   MEMORY MATCHING GAME - IDEAL HACKATHON		 
*****************************************************/


class GameManager
{
private:
	GameBoard board;
	Player players[2];
	int attempts[2]; //Number of attempts per player (till matching pair found)
	int currentPlayer;

public:
	GameManager() : currentPlayer(0) {
		players[0] = Player();
		players[1] = Player();
		attempts[0] = 0;
		attempts[1] = 0;
		board = GameBoard();
	}
	void startGame(int r, int c);
	void processMove(int r1, int c1, int r2, int c2);
	void switchPlayer();
	bool isGameOver();

	GameBoard& getBoard() {
		return board;
	}
	Player* getPlayers() {
		return players;
	}
	inline int getCurrentPlayer() { return currentPlayer; }

	void setPlayers(int index, Player& player) {
		players[index] = player;
	}
	void setCurrentPlayer(int num) {
		if (!(num < 2 && num >= 0)) { std::cout << "Invalid Player!\n"; return; }
		currentPlayer = num;
	}
};
