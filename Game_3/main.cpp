#include <SFML/Graphics.hpp>
#include "GameManager.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick Breaker");
        window.setFramerateLimit(60);

        GameManager manager(15, 10);

        Font font;
        font.loadFromFile("Roboto-Black.ttf");

        Text scoreText;
        scoreText.setFont(font);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(0, 0);

        Text highScoreText;
        highScoreText.setFont(font);
        highScoreText.setFillColor(Color::White);
        highScoreText.setPosition(WINDOW_WIDTH - 100, 0);

        while (window.isOpen())
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
                        manager.getPaddle().moveLeft();
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
                {
                        manager.getPaddle().moveRight();
                }





                //update score text
                scoreText.setString("Score:\t" + std::to_string(manager.getPlayer().getScore()));
                highScoreText.setString("High Score:\t" + std::to_string(manager.getPlayer().getHighScore()));
                highScoreText.setPosition(WINDOW_WIDTH - highScoreText.getGlobalBounds().getSize().x - 100, 0);



                manager.updateGame();


                window.clear();
                manager.draw(window);
                window.draw(scoreText);
                window.draw(highScoreText);
                window.display();
        }

        return 0;
}