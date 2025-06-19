#include "GameManager.h"
#include <iostream>

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

	paddle.setSpeed(paddle.getSpeed() * 1.00015);
	ball.setVelocityX(ball.getVelocityX() * 1.00015);
	ball.setVelocityY(ball.getVelocityY() * 1.00015);

	checkWinCondition();
	checkLoseCondition();


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

			// Increment score
			if (brick.getBrickType() == Brick::WOOD_BRICK) player.incrementScore(100);
			else if (brick.getBrickType() == Brick::METAL_BRICK) player.incrementScore(200);
			else player.incrementScore(300);


			// Find sides
			double ballLeft   = ballBox.left;
			double ballRight  = ballBox.left + ballBox.width;
			double ballTop    = ballBox.top;
			double ballBottom = ballBox.top + ballBox.height;

			double brickLeft   = brickBox.left;
			double brickRight  = brickBox.left + brickBox.width;
			double brickTop    = brickBox.top;
			double brickBottom = brickBox.top + brickBox.height;

			// Find overlap distances
			double overlapLeft   = ballRight - brickLeft;
			double overlapRight  = brickRight - ballLeft;
			double overlapTop    = ballBottom - brickTop;
			double overlapBottom = brickBottom - ballTop;

			// Choose smallest overlap to determine collision side
			bool fromLeft   = overlapLeft < overlapRight;
			bool fromTop    = overlapTop < overlapBottom;

			double minOverlapX = fromLeft ? overlapLeft : overlapRight;
			double minOverlapY = fromTop  ? overlapTop  : overlapBottom;

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
	window.draw(background);
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
				return;
			}
		}
	}
	player.setWinStatus(true);
	gameOver = true;
}

void GameManager::checkLoseCondition()
{
	if (ball.getCircle().getPosition().y + ball.getRadius() >= 1080)
	{
		player.setWinStatus(false);
		gameOver = true;
	}

}

void GameManager::startLevel()
{
}
