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
};

