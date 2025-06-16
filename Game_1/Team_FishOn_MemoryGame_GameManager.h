#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_MemoryGame_GameBoard.h"
#include "Team_FishOn_MemoryGame_Player.h"


/*****************************************************
* TEAM: FishOn										 
* MEMBERS:		1. SYED HAIDER ALI JAFFRI		24L-0		 
*			2. WALEED BIN OMER			24L-0		 
*			3. MUHAMMAD RAFAY			24L-0649	 
*	   MEMORY MATCHING GAME - IDEAL HACKATHON		 
*****************************************************/


class GameManager
{
private:
	GameBoard board;
	Player players[2];
	int currentPlayer;

public:
	GameManager();

	void startGame();
	void processMove();
	void switchPlayer();
	bool isGameOver();

	GameBoard getBoard() {
		return board;
	}
	Player getPlayers() {
		return *players;
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
