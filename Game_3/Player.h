#pragma once
class Player
{
	int score;
	int lives;
	int currentLevel;

public:
	Player();
	inline void setScore(int score) { this->score = score; }
	inline void setLives(int lives) { this->lives = lives; }
	inline void setCurrentLevel(int level) { currentLevel = level; }

	inline int getScore() { return score; }
	inline int getLives() { return lives; }
	inline int getCurrentLevel() { return currentLevel; }

	inline void incrementScore();
	inline void incrementLives() { lives++; }
	inline void incrementLevel() { currentLevel++; }

	inline void decrementScore();
	inline void decrementLives() { lives--; }
	inline void decrementCurrentLevel() { currentLevel--; }
};

