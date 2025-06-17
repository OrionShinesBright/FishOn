#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_TicTacToe_GameManager.h"
#include <iostream>


const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;




int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

        //Initialize Game
        GameManager manager;
        
        


        // Loading background texture
        sf::Texture backgroundTexture;
        backgroundTexture.loadFromFile("notebook.png");

        sf::Sprite background;
        background.setTexture(backgroundTexture);
        background.setScale(
                (float)WINDOW_WIDTH / backgroundTexture.getSize().x,
                (float)WINDOW_HEIGHT / backgroundTexture.getSize().y
        );


        manager.getBoard().draw(window);

        


        //Initializing Positions
        manager.getBoard().initializePositions();
      


        





       

        // Loading font for scoring or messages
        sf::Font font;
        font.loadFromFile("Roboto-Black.ttf");
        
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(60);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setPosition(10, 10);
        scoreText.setString("Player 1's Turn");


        
        while (window.isOpen() && !manager.getGameEnd())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();


                        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && !manager.getGameEnd())
                        {
                                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                                sf::Vector2f boardPos = manager.getBoard().getBoardSprite().getPosition();
                                sf::FloatRect boardBounds = manager.getBoard().getBoardSprite().getGlobalBounds();

                                float cellWidth = boardBounds.width / 3;
                                float cellHeight = boardBounds.height / 3;

                                int col = static_cast<int>((mousePos.x - boardBounds.left) / cellWidth);
                                int row = static_cast<int>((mousePos.y - boardBounds.top) / cellHeight);

                                if (row >= 0 && row < 3 && col >= 0 && col < 3 && manager.getBoard().isEmpty(row, col))
                                {
                                        manager.setCurrentCellX(col);
                                        manager.setCurrentCellY(row);
                                        manager.updateWindow(window);
                                }
                        }
                }



                window.clear();
                window.draw(background);
                manager.getBoard().draw(window);
                system("cls");
                for (int i = 0; i < 3; i++)
                {
                        for (int j = 0; j < 3; j++)
                        {
                                std::cout << manager.getBoard().getGrid(i, j) << "\t";
                        }
                        std::cout << "\n";
                }
                for (int i = 0; i < 5; i++)
                {
                        window.draw(manager.getXSprite(i));
                        window.draw(manager.getYSprite(i));
                }
                window.draw(scoreText);
                window.display();
        }

        return 0;
}