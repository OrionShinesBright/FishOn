#include <fstream>
using namespace std;
#pragma once
class Player
{
	int score;
	int lives;
	int currentLevel;
	bool winStatus;


	int highScore;

public:

	const string HIGH_SCORE_FILE_PATH = "highScore.txt";
	Player()
	{
		score = 0;
		lives = 3;
		currentLevel = 1;
		winStatus = false;

		loadHighScore();
	}

	inline void setScore(int score) { this->score = score; }
	inline void setLives(int lives) { this->lives = lives; }
	inline void setCurrentLevel(int level) { currentLevel = level; }

	inline int getScore() { return score; }
	inline int getLives() { return lives; }
	inline int getCurrentLevel() { return currentLevel; }
	inline int getWinStatus() { return winStatus; }
	inline int getHighScore() { return highScore; }

	inline void incrementScore(int value)
	{
		score += value;
		if (score > highScore)
		{
			highScore = score;
			writeHighScore(); // Save only if it beats high score
		}
	}
	inline void incrementLives() { lives++; }
	inline void incrementLevel() { currentLevel++; }

	inline void decrementScore(int value) { score -= value; }
	inline void decrementLives() { lives--; }
	inline void decrementCurrentLevel() { currentLevel--; }

	inline void setWinStatus(bool win) { winStatus = win; }

	void loadHighScore();
	void writeHighScore();


};

