#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main() {
        sf::RenderWindow window(sf::VideoMode(170, 225, 32), "Card");
        sf::Texture texture;
        texture.loadFromFile("card.png");
        sf::Sprite sprite(texture);
        while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                window.close();
                        }
                }
                for (int s = 100; s >= 0; s--) {
                        sprite.setScale(s * 0.01, 1);
                        sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2, 0);
                        window.clear();
                        window.draw(sprite);
                        window.display();
                }
        }
        return 0;
}