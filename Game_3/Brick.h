#pragma once
#include "Ball.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Brick
{
private:
	float x, y;
	int strength;
	int brickType;
	bool isDestroyed;
	int pointValue;

public:
	Brick();
	bool takeDamage();
	void draw();
	bool checkCollision(Ball& ball);

	// Setters
	void setX(float val) { x = val; }
	void setY(float val) { y = val; }
	void setStrength(int val) { strength = val; }
	void setBrickType(int val) { brickType = val; }
	void setIsDestroyed(bool val) { isDestroyed = val; }
	void setPointValue(int val) { pointValue = val; }

	// Getters
	float getX() { return x; }
	float getY() { return y; }
	int getStrength() { return strength; }
	int getBrickType() { return brickType; }
	bool getIsDestroyed() { return isDestroyed; }
	int getPointValue() { return pointValue; }
};

