#pragma once
class Player
{
	int score;
	int lives;
	int currentLevel;
	bool winStatus;

public:
	Player()
	{
		score = 0;
		lives = 3;
		currentLevel = 1;
		winStatus = false;
	}

	inline void setScore(int score) { this->score = score; }
	inline void setLives(int lives) { this->lives = lives; }
	inline void setCurrentLevel(int level) { currentLevel = level; }

	inline int getScore() { return score; }
	inline int getLives() { return lives; }
	inline int getCurrentLevel() { return currentLevel; }
	inline int getWinStatus() { return winStatus; }

	inline void incrementScore();
	inline void incrementLives() { lives++; }
	inline void incrementLevel() { currentLevel++; }

	inline void decrementScore();
	inline void decrementLives() { lives--; }
	inline void decrementCurrentLevel() { currentLevel--; }

	inline void setWinStatus(bool win) { winStatus = win; }
};

