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
	int attempts[2]; //Number of attempts per player (till matching pair found)
	int currentPlayer;

public:
<<<<<<< HEAD
	GameManager() : currentPlayer(0) {
		players[0] = Player();
		players[1] = Player();
		attempts[0] = 0;
		attempts[1] = 0;
		board = GameBoard();
	}
	void startGame(int r, int c);
	void processMove(int r1, int c1, int r2, int c2);
=======
	GameManager();
  
	void startGame();
	void processMove();
>>>>>>> 6722309473f9e89e0326b1eb9147a29b8a8350d8
	void switchPlayer();
	bool isGameOver();

	GameBoard& getBoard() {
		return board;
	}
	Player& getPlayers(int i) {
		return players[i];
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
