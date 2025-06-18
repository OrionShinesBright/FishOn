#include "Brick.h"

Brick& Brick::operator=(const Brick& other)
{
        if (this != &other)
        {
                x = other.x;
                y = other.y;
                strength = other.strength;
                brickType = other.brickType;
                isDestroyed = other.isDestroyed;
                pointValue = other.pointValue;

                // Copy SFML shape
                brickRect = other.brickRect;
        }
        return *this;
}


bool Brick::takeDamage()
{
    return false;
}

void Brick::draw(RenderWindow& window)
{
        if (!isDestroyed)
        {
                window.draw(brickRect);
        }
}

bool Brick::checkCollision(Ball& ball)
{
	return false;
}

void Brick::update()
{
        if (strength <= 0) isDestroyed == true;
}
