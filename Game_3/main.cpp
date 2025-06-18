#include <SFML/Graphics.hpp>
#include "GameManager.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick Breaker");
        window.setFramerateLimit(60);

        GameManager manager(15, 10);

        while (window.isOpen())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }



                if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
                {
                        manager.getPaddle().moveLeft();
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
                {
                        manager.getPaddle().moveRight();
                }




                manager.updateGame();


                window.clear();
                manager.draw(window);
                window.display();
        }

        return 0;
}