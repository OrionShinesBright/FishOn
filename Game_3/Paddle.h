#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

#pragma once
class Paddle
{
private:
	
	RectangleShape paddle;
	float x, y;
	float width, height;
	float speed;

public:
	Paddle()
	{
		width = 150.f;
		height = 20.f;
		x = 1920 / 2;
		y = 1000;
		speed = 10.f;

		paddle.setSize(Vector2f(width, height));
		paddle.setOrigin(width / 2.f, height / 2.f);
		paddle.setPosition(x, y);
	}

	void moveLeft();
	void moveRight();
	void draw(RenderWindow& window);
	float getBounceAngle(float ballX);
	void update();


	// Setters
	void setX(float val) { x = val; }
	void setY(float val) { y = val; }
	void setWidth(float val) { width = val; }
	void setHeight(float val) { height = val; }
	void setSpeed(float val) { speed = val; }

	// Getters
	float getX() { return x; }
	float getY() { return y; }
	float getWidth() { return width; }
	float getHeight() { return height; }
	float getSpeed() { return speed; }
	RectangleShape& getRect() { return paddle; }
};

