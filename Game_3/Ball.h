#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
using namespace sf;
#pragma once
class Ball
{
private:
	CircleShape ball;
	float x, y;
	float velocityX, velocityY;
	float radius;
	bool isActive;

public:

	Ball()
	{
		radius = 20.f;
		x = 1920 / 2;
		y = 900;
		velocityX = 5.f;
		velocityY = -5.f;
		isActive = true;

		ball.setRadius(radius);
		ball.setFillColor(Color::Green); // default color, change if needed
		ball.setOrigin(radius, radius);  // center origin
		ball.setPosition(x, y);
	}



	// Setters
	void setX(float val) { x = val; ball.setPosition(x, y); }
	void setY(float val) { y = val; ball.setPosition(x, y); }
	void setVelocityX(float val) { velocityX = val; }
	void setVelocityY(float val) { velocityY = val; }
	void setRadius(float val) {
		radius = val;
		ball.setRadius(radius);
		ball.setOrigin(radius, radius);
	}
	void setActive(bool val) { isActive = val; }

	// Getters
	float getX() const { return x; }
	float getY() const { return y; }
	float getVelocityX() const { return velocityX; }
	float getVelocityY() const { return velocityY; }
	float getRadius() const { return radius; }
	bool getActive() const { return isActive; }
	CircleShape& getCircle() { return ball; }





	void updatePosition();
	void draw(RenderWindow& window);
	void reset();

};

