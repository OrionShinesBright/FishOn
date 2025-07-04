#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;

#include <iostream>
#include <fstream>
using namespace std;

/*****************************************************
* TEAM: FishOn										 
* MEMBERS:		1. SYED HAIDER ALI JAFRI		24L-0882		 
*			2. WALEED BIN OMER			24L-0571		 
*			3. MUHAMMAD RAFAY			24L-0649	 
*	   MEMORY MATCHING GAME - IDEAL HACKATHON		 
*****************************************************/

class Player
{
private:
	string name;
	int score;
	int gamesWon;

public:
	Player() : name(""), score(0), gamesWon(0) {}
	Player(string n, int s, int w) : name(n), score(s), gamesWon(w) {}
	void updateScore(int points);
	void incrementWins();
	void displayStats(RenderWindow& window, int playerNum);

	inline void setName(string NAME) { name = NAME; }
	inline void setScore(int SCORE) { score = SCORE; }
	inline void setGamesWon(int GAMES_WON) { gamesWon = GAMES_WON; }

	inline string getName() const { return name; }
	inline int getScore() const { return score; }
	inline int getGamesWon() const { return gamesWon; }
};

