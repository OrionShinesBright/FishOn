#include "Ball.h"

void Ball::updatePosition()
{
	if (!isActive) return; 
	
	if (ball.getPosition().x + radius >= 1920) velocityX *= -1;
	if (ball.getPosition().x - radius <= 0) velocityX *= -1;
	if (ball.getPosition().y - radius <= 0) velocityY *= -1;
	ball.move(velocityX, velocityY);


}

void Ball::draw(RenderWindow& window)
{
	window.draw(ball);
}

void Ball::reset()
{
	isActive = true;
	ball.setPosition(1920 / 2,900);
}
