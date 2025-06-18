#include "Paddle.h"

void Paddle::moveLeft()
{
	if (paddle.getPosition().x - width / 2 <= 0) return;
	x -= speed ;
}

void Paddle::moveRight()
{
	if (paddle.getPosition().x + width / 2 >= 1920) return;
	x += speed ;
}

void Paddle::draw(RenderWindow& window)
{
	window.draw(paddle);
}

float Paddle::getBounceAngle(float ballX)
{
	float relativeIntersect = ballX - x; // x = center of paddle
	float normalized = relativeIntersect / (width / 2.0f); // range: -1 to 1

	// Clamp
	if (normalized < -1.f) normalized = -1.f;
	if (normalized > 1.f)  normalized = 1.f;

	float minAngle = 15.f * 3.1415926535f / 180.f;
	float maxAngle = 60.f * 3.1415926535f / 180.f;

	float angle = normalized * maxAngle;

	// Clamp angle to avoid too-horizontal (e.g. -5° or +5°)
	if (angle < 0)
		angle = std::min(-minAngle, angle); // make sure it's at least -minAngle
	else
		angle = std::max(minAngle, angle);  // at least +minAngle

	return angle;
}

void Paddle::update()
{
	paddle.setPosition(x, y);
}
