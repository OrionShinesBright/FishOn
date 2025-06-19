#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick Breaker");
	window.setFramerateLimit(60);

	GameManager managers[3] = {
		GameManager(10, 5, Color(71, 52, 233)),
		GameManager(12, 7, Color(57, 82, 100)),
		GameManager(15, 10, Color(85, 255, 200))
	};

	Font font;
	font.loadFromFile("Roboto-Black.ttf");


	Text scoreText;
	scoreText.setFont(font);
	scoreText.setPosition(0, 0);

	Text highScoreText;
	highScoreText.setFont(font);
	highScoreText.setPosition(WINDOW_WIDTH - 100, 0);

	Text levelText;
	levelText.setFont(font);

	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::Black);
	gameOverText.setCharacterSize(260);

	Text endText;
	endText.setFont(font);
	endText.setFillColor(Color::Black);
	endText.setCharacterSize(80);


	RectangleShape gameOverBackground;
	gameOverBackground.setSize(Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	gameOverBackground.setFillColor(Color::White);
	gameOverBackground.setPosition(0, 0);


	for (int i = 0; i < 3; i++)
	{
		

		scoreText.setFillColor((managers[i].getBackground().getFillColor().r + managers[i].getBackground().getFillColor().g + managers[i].getBackground().getFillColor().b) / 3 > 128 ? sf::Color(30, 30, 30) : sf::Color(225, 225, 225));

		highScoreText.setFillColor((managers[i].getBackground().getFillColor().r + managers[i].getBackground().getFillColor().g + managers[i].getBackground().getFillColor().b) / 3 > 128 ? sf::Color(30, 30, 30) : sf::Color(225, 225, 225));

		levelText.setFillColor((managers[i].getBackground().getFillColor().r + managers[i].getBackground().getFillColor().g + managers[i].getBackground().getFillColor().b) / 3 > 128 ? sf::Color(30, 30, 30) : sf::Color(225, 225, 225));
		levelText.setString("Level " + std::to_string(i + 1));
		levelText.setOrigin(levelText.getGlobalBounds().getSize().x / 2, 0);
		levelText.setPosition(WINDOW_WIDTH / 2, 0);

		while (window.isOpen() && !managers[i].isGameOver())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}


			//input
			if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
			{
				managers[i].getPaddle().moveLeft();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
			{
				managers[i].getPaddle().moveRight();
			}





			//update score text
			scoreText.setString("Score:\t" + std::to_string(managers[i].getPlayer().getScore()));
			highScoreText.setString("High Score:\t" + std::to_string(managers[i].getPlayer().getHighScore()));
			highScoreText.setPosition(WINDOW_WIDTH - highScoreText.getGlobalBounds().getSize().x - 100, 0);

			//update end text
			endText.setString("Score:\t" + std::to_string(managers[i].getPlayer().getScore()) + "\nHigh Score:\t" + std::to_string(managers[i].getPlayer().getHighScore()) + "\nPress [ESCAPE] to Quit");
			endText.setOrigin(endText.getGlobalBounds().getSize().x / 2, endText.getGlobalBounds().getSize().y / 2);
			endText.setPosition(WINDOW_WIDTH / 2, 3 * WINDOW_HEIGHT / 4);

			managers[i].updateGame();


			window.clear();
			managers[i].draw(window);
			window.draw(scoreText);
			window.draw(highScoreText);
			window.draw(levelText);
			window.display();
		}

		while (window.isOpen() && managers[i].isGameOver())
		{
			if (managers[i].getPlayer().getWinStatus()) gameOverText.setString("You Win!");
			else gameOverText.setString("You Lose!");

			gameOverText.setOrigin(gameOverText.getGlobalBounds().getSize().x / 2, gameOverText.getGlobalBounds().getSize().y / 2);
			gameOverText.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3);


			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				return 0;
			}

			if (managers[i].getPlayer().getWinStatus()) //if status is win
			{
				if (i < 2) break;
			}


			window.clear();

			window.draw(gameOverBackground);
			window.draw(gameOverText);
			window.draw(endText);

			window.display();


		}
	}



	return 0;
}