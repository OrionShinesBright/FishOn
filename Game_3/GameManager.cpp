#include "GameManager.h"

void GameManager::updateGame()
{
	paddle.update();
	ball.updatePosition();
	
	for (int i = 0; i < xBricks; ++i)
	{
		for (int j = 0; j < yBricks; ++j)
		{
			bricks[i][j].update();
		}
	}

	handleCollisions();
}

void GameManager::handleCollisions()
{
	//ball and paddle
	// get the bounding box of the entity
	sf::FloatRect ballBox = ball.getCircle().getGlobalBounds();

	// check collision with another box (like the bounding box of another entity)
	sf::FloatRect paddleBox = paddle.getRect().getGlobalBounds();
	Vector2f collisionPoint;
	if (ballBox.intersects(paddleBox))
	{
		// Collision point is the ball's center X
		float ballCenterX = ball.getCircle().getPosition().x;

		// Calculate the bounce angle
		float angle = paddle.getBounceAngle(ballCenterX);

		// Reflect the ball using the bounce angle
		float speed = sqrt(ball.getVelocityX() * ball.getVelocityX() + ball.getVelocityY() * ball.getVelocityY());
		ball.setVelocityX(speed * cos(angle));
		ball.setVelocityY(-speed * sin(angle)); // Going upward

		// Adjust position so it doesn't get stuck inside paddle
		ball.getCircle().setPosition(ball.getCircle().getPosition().x, paddleBox.top - ball.getCircle().getRadius());
	}





	//ball and brick
	for (int i = 0; i < yBricks; ++i)
{
	for (int j = 0; j < xBricks; ++j)
	{
		Brick& brick = bricks[i][j];
		if (brick.getIsDestroyed()) continue;

		sf::FloatRect brickBox = brick.getBrickRect().getGlobalBounds();

		if (ballBox.intersects(brickBox))
		{
			// Mark the brick as destroyed
			brick.setIsDestroyed(true);

			// Reflect the ball depending on where it hits

			// Determine the sides
			float ballLeft   = ballBox.left;
			float ballRight  = ballBox.left + ballBox.width;
			float ballTop    = ballBox.top;
			float ballBottom = ballBox.top + ballBox.height;

			float brickLeft   = brickBox.left;
			float brickRight  = brickBox.left + brickBox.width;
			float brickTop    = brickBox.top;
			float brickBottom = brickBox.top + brickBox.height;

			// Find overlap distances
			float overlapLeft   = ballRight - brickLeft;
			float overlapRight  = brickRight - ballLeft;
			float overlapTop    = ballBottom - brickTop;
			float overlapBottom = brickBottom - ballTop;

			// Choose smallest overlap to determine collision side
			bool fromLeft   = overlapLeft < overlapRight;
			bool fromTop    = overlapTop < overlapBottom;

			float minOverlapX = fromLeft ? overlapLeft : overlapRight;
			float minOverlapY = fromTop  ? overlapTop  : overlapBottom;

			// Bounce
			if (minOverlapX < minOverlapY)
			{
				ball.setVelocityX(-ball.getVelocityX());
			}
			else
			{
				ball.setVelocityY(-ball.getVelocityY());
			}

			break; // One brick per frame
		}
	}
}
}

void GameManager::draw(RenderWindow& window)
{
	ball.draw(window);
	paddle.draw(window);
	
	for (int i = 0; i < yBricks; i++)
	{
		for (int j = 0; j < xBricks; j++)
		{
			bricks[i][j].draw(window);
		}
	}

}

void GameManager::checkWinCondition()
{
	for (int i = 0; i < yBricks; i++)
	{
		for (int j = 0; j < xBricks; j++)
		{
			if (!bricks[i][j].getIsDestroyed())
			{
				player.setWinStatus(false);
			}
		}
	}
	player.setWinStatus(true);
}

void GameManager::startLevel()
{
}
