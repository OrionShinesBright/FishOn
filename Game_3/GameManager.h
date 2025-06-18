#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once
const int MAX_ROWS = 20;
const int MAX_COLS = 20;
class GameManager
{
private:
	int xBricks;
	int yBricks;
	Ball ball;
	Paddle paddle;
	Brick bricks[MAX_ROWS][MAX_COLS];
	Player player;
	bool gameOver;

	int xBrickMargin;
	int yBrickMargin;
	int xBrickSpacing;
	int yBrickSpacing;


public:

	GameManager(int xBricks, int yBricks)
	{
		this->xBricks = xBricks;
		this->yBricks = yBricks;

		float screenWidth = 1920.f;
		float screenHeight = 1080.f;

		// Desired total horizontal and vertical padding space
		float totalHorizontalPadding = screenWidth * 0.1f;  // 10% horizontal padding
		float totalVerticalPadding = screenHeight * 0.1f;   // 10% vertical padding (top area)

		// Spacing between bricks (arbitrary ratio of brick width)
		xBrickSpacing = 5;
		yBrickSpacing = 5;

		// Calculate available area after padding
		float usableWidth = screenWidth - totalHorizontalPadding;
		float usableHeight = screenHeight * 0.3f; // top 30% of screen for bricks

		// Compute brick sizes based on number and spacing
		float brickWidth = (usableWidth - (xBricks - 1) * xBrickSpacing) / xBricks;
		float brickHeight = (usableHeight - (yBricks - 1) * yBrickSpacing) / yBricks;

		// Margins to center the brick grid
		xBrickMargin = (screenWidth - (brickWidth * xBricks + (xBricks - 1) * xBrickSpacing)) / 2.f;
		yBrickMargin = totalVerticalPadding / 2.f;

		for (int row = 0; row < yBricks; ++row)
		{
			for (int col = 0; col < xBricks; ++col)
			{
				// Assign type
				if (row < 2)
					bricks[row][col].setBrickType(Brick::GOLD_BRICK);
				else if (row < 5)
					bricks[row][col].setBrickType(Brick::METAL_BRICK);
				else
					bricks[row][col].setBrickType(Brick::WOOD_BRICK);

				// Size and position
				bricks[row][col].getBrickRect().setSize(Vector2f(brickWidth, brickHeight));
				float x = xBrickMargin + col * (brickWidth + xBrickSpacing);
				float y = yBrickMargin + row * (brickHeight + yBrickSpacing);
				bricks[row][col].getBrickRect().setPosition(x, y);
			}
		}

		ball.reset(); // Master’s ball, centered as ordered
	}
	GameManager()
	{
		xBricks = 20;
		yBricks = 5;

		xBrickMargin = 5;
		yBrickMargin = 5;

		xBrickSpacing = 2;
		yBrickSpacing = 2;

		gameOver = false;

		// Initialize brick grid
		for (int row = 0; row < yBricks; ++row)
		{
			for (int col = 0; col < xBricks; ++col)
			{
				bricks[row][col].setBrickType(Brick::WOOD_BRICK);

				if (row < 2)
					bricks[row][col].setBrickType(Brick::GOLD_BRICK);
				else if (row < 5)
					bricks[row][col].setBrickType(Brick::METAL_BRICK);


				float x = xBrickMargin + col * (bricks[row][col].getWidth() + xBrickSpacing);
				float y = yBrickMargin + row * (bricks[row][col].getHeight() + yBrickSpacing);

				bricks[row][col].getBrickRect().setPosition(x, y);
			}
		}

		
		ball.reset(); // sets ball to center and stops it
	}
	void updateGame();
	void handleCollisions();
	void draw(RenderWindow& window);
	void checkWinCondition();
	void startLevel();



	// Setters
	void setBall(const Ball& b) { ball = b; }
	void setPaddle(const Paddle& p) { paddle = p; }
	void setBrick(int row, int col, const Brick& brick) {
		if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS)
			bricks[row][col] = brick;
	}
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

