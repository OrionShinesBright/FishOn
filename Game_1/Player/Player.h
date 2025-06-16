#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	int score;
	int gamesWon;

public:
	void updateScore(int points);
	void incrementWins();
	void displayStats();

	inline void setName(string NAME) { name = NAME; }
	inline void setScore(int SCORE) { score = SCORE; }
	inline void setGamesWon(int GAMES_WON) { gamesWon = GAMES_WON; }

	inline string getName() const { return name; }
	inline int getScore() const { return score; }
	inline int getGamesWon() const { return gamesWon; }
};

