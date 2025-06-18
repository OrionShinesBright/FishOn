#pragma once
#include "Ball.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Brick
{
private:
	RectangleShape brickRect;
	float x, y;
	int strength;
	int brickType;
	bool isDestroyed;
	int pointValue;

public:
	
	static const int BRICK_WIDTH = 100;
	static const int BRICK_HEIGHT = 50;
	
	static const int WOOD_BRICK = 1;
	static const int METAL_BRICK = 2;
	static const int GOLD_BRICK = 3;

	const Color WOOD_RGB = Color(115, 19, 10);
	const Color METAL_RGB = Color(173, 178, 186);
	const Color GOLD_RGB = Color(212, 187, 23);

	Brick()
	{
		brickRect.setSize(Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
		brickRect.setFillColor(WOOD_RGB);
		brickRect.setPosition(-100, -100);

		brickType = WOOD_BRICK;
		strength = 1;
		pointValue = 10;
		isDestroyed = false;
		
	}

	Brick& operator=(const Brick& other);


	Brick(int type)
	{
		if (type != WOOD_BRICK && type != METAL_BRICK && type != GOLD_BRICK) return;
		brickType = type;

		brickRect.setSize(Vector2f(BRICK_WIDTH, BRICK_HEIGHT));


		if (type == WOOD_BRICK)
		{
			brickRect.setFillColor(WOOD_RGB);
			strength = 1;
			pointValue = 10;
		}
		else if (type == METAL_BRICK)
		{
			brickRect.setFillColor(METAL_RGB);
			strength = 2;
			pointValue = 20;
		}
		else if (type == GOLD_BRICK)
		{
			brickRect.setFillColor(GOLD_RGB);
			strength = 3;
			pointValue = 50;
		}

		isDestroyed = false;
	}
	bool takeDamage();
	void draw(RenderWindow& window);
	bool checkCollision(Ball& ball);
	void update();

	// Setters
	void setX(float val) { x = val; }
	void setY(float val) { y = val; }
	void setStrength(int val) { strength = val; }
	void setBrickType(int val)
	{
		if (val != WOOD_BRICK && val != METAL_BRICK && val != GOLD_BRICK) return;

		brickType = val;


		if (val == WOOD_BRICK)
		{
			brickRect.setFillColor(WOOD_RGB);
			strength = 1;
			pointValue = 10;
		}
		else if (val == METAL_BRICK)
		{
			brickRect.setFillColor(METAL_RGB);
			strength = 2;
			pointValue = 20;
		}
		else if (val == GOLD_BRICK)
		{
			brickRect.setFillColor(GOLD_RGB);
			strength = 3;
			pointValue = 50;
		}
	}
	void setIsDestroyed(bool val) { isDestroyed = val; }
	void setPointValue(int val) { pointValue = val; }

	// Getters
	float getX() { return x; }
	float getY() { return y; }
	int getStrength() { return strength; }
	int getBrickType() { return brickType; }
	bool getIsDestroyed() { return isDestroyed; }
	int getPointValue() { return pointValue; }
	RectangleShape& getBrickRect() { return brickRect; }
	int getWidth() { return BRICK_WIDTH; }
	int getHeight() { return BRICK_HEIGHT; }
};

