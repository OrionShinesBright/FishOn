#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#pragma once
class Ball
{
private:
	float x, y;
	float velocityX, velocityY;
	float radius;
	bool isActive;

public:

	Ball();
	void updatePosition();
	void handleCollision();
	void draw();
	void reset();
};

