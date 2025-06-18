#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once
const int MAX_ROWS = 10;
const int MAX_COLS = 15;
class GameManager
{
private:
	Ball ball;
	Paddle paddle;
	Brick bricks[MAX_ROWS][MAX_COLS];
	Player player;
	bool gameOver;


public:
	void updateGame();
	void handleCollisions();
	void draw();
	void checkWinCondition();



	// Setters
	void setBall(const Ball& b) { ball = b; }
	void setPaddle(const Paddle& p) { paddle = p; }
	void setBrick(int row, int col, const Brick& brick) {
		if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS)
			bricks[row][col] = brick;
	}
	void setPlayer(const Player& p) { player = p; }
	void setGameOver(bool status) { gameOver = status; }

	// Getters
	Ball& getBall() { return ball; }
	const Ball& getBall() const { return ball; }

	Paddle& getPaddle() { return paddle; }

	Brick& getBrick(int row, int col) {
		return bricks[row][col]; // assumes valid indices
	}

	Player& getPlayer() { return player; }

	bool isGameOver() const { return gameOver; }

};

