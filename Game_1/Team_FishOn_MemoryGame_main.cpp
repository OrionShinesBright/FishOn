#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_MemoryGame_GameManager.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
int main() {


        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
        window.setFramerateLimit(60);

        sf::Vector2i globalPosition = sf::Mouse::getPosition();



        // Prepare loading text
        sf::Font loadingFont;
        loadingFont.loadFromFile("Roboto-Black.ttf");
        sf::Text loadingText;
        loadingText.setFont(loadingFont);
        loadingText.setString("Loading game, please wait...");
        loadingText.setCharacterSize(80);
        loadingText.setFillColor(sf::Color::White);
        loadingText.setPosition((WINDOW_WIDTH - loadingText.getLocalBounds().width) / 2,
                (WINDOW_HEIGHT - loadingText.getLocalBounds().height) / 2);

        window.clear(sf::Color(0, 0, 0)); // black background
        window.draw(loadingText);
        window.display();

        GameManager manager;
        manager.startGame(4,4);

        int card1Row, card1Col, card2Row, card2Col;
        card1Row = card1Col = card2Row = card2Col = -1;
        bool firstSelected = false;


        while (window.isOpen() && !manager.isGameOver())
        {

                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close(); 
                        
                        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        {
                                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                                //if (card1.getSprite().getGlobalBounds().contains(mousePos))
                                //{
                                //        card1.flip();
                                //}
                                for (int i = 0; i < manager.getBoard().getRows(); i++)
                                {
                                        for (int j = 0; j < manager.getBoard().getCols(); j++)
                                        {
                                                if (manager.getBoard().getCards(i, j).getSprite().getGlobalBounds().contains(mousePos))
                                                {
                                                        //manager.getBoard().getCards(i, j).flip();
                                                        if (!firstSelected)
                                                        {
                                                                card1Row = i;
                                                                card1Col = j;
                                                                firstSelected = true;
                                                        }
                                                        else
                                                        {
                                                                card2Row = i;
                                                                card2Col = j;
                                                                firstSelected = false;
                                                                if (card1Row == card2Row && card1Col == card2Col)
                                                                {
                                                                        firstSelected = true;
                                                                        continue;
                                                                }
                                                                manager.processMove(card1Row, card1Col, card2Row, card2Col);
                                                        }


                                                       
                                                }
                                        }

                                     
                                }
                        }
                }

                
              






                for (int i = 0; i < manager.getBoard().getRows(); i++)
                {
                        for (int j = 0; j < manager.getBoard().getCols(); j++)
                        {
                                manager.getBoard().getCards(i, j).update();
                        }
                }
                
                
                window.clear();
                manager.drawGame(window);
                window.display();


        }

        return 0;
}