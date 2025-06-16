#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_MemoryGame_Card.h"
int main() {
        Card card1(1);




        sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

        sf::Vector2i globalPosition = sf::Mouse::getPosition();

        while (window.isOpen())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close(); 
                        
                        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        {
                                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                                if (card1.getSprite().getGlobalBounds().contains(mousePos))
                                {
                                        card1.flip();
                                }
                        }
                }






                card1.update();
                window.clear();
                card1.draw(window);
                window.display();
        }

        return 0;
}