#pragma once
class Paddle
{
private:
	float x, y;
	float width, height;
	float speed;

public:
	Paddle();
	void moveLeft();
	void moveRight();
	void draw();
	float getBounceAngle(float ballX);


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
};

