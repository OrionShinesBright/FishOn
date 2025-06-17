#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_TicTacToe_GameManager.h"
#include <iostream>
#include <string>


const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;




//Initialize Game
 GameManager manager;





void updateWinScreen(RenderWindow& window)
{
        RectangleShape background(Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
        background.setFillColor(manager.getPlayer(manager.getCurrentPlayer()).getAvatarColor());

        Font winFont;
        winFont.loadFromFile("Roboto-Black.ttf");

        Text winText;
        winText.setFont(winFont);
        winText.setFillColor(Color::White);
        string name = manager.getPlayer(manager.getCurrentPlayer()).getName();
        winText.setString(name + " Wins!");
        winText.setCharacterSize(260);
        winText.setOrigin(winText.getGlobalBounds().getSize().x / 2, winText.getGlobalBounds().getSize().y / 2);
        winText.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        window.draw(background);
        window.draw(winText);
}


      
int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

        
        


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
       


        sf::Text nameText;
        nameText.setFont(font);
        nameText.setCharacterSize(60);
        nameText.setFillColor(sf::Color::Black);
        nameText.setPosition(10, 80);


        sf::Text avatarText;
        avatarText.setFont(font);
        avatarText.setCharacterSize(120);
        avatarText.setPosition(10, 160);


        
        while (window.isOpen())
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

                //update text
                if (manager.getCurrentPlayer() == 0)
                {
                        scoreText.setString("Player 1's Turn");
                }
                else
                {
                        scoreText.setString("Player 2's Turn");
                }

                string name = manager.getPlayer(manager.getCurrentPlayer()).getName();
                nameText.setString("Name:\t" + name);

                avatarText.setFillColor(manager.getPlayer(manager.getCurrentPlayer()).getAvatarColor());
                avatarText.setString(manager.getPlayer(manager.getCurrentPlayer()).getAvatarSymbol());





                window.clear();

                if (!manager.getGameEnd()) //if game is running
                {
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
			window.draw(nameText);
			window.draw(avatarText);
                }
                else //if game has ended (win or draw)
                {
                        if (manager.checkWinPlayer1() || manager.checkWinPlayer2()) updateWinScreen(window);
                        //else if (manager.checkWinPlayer2()) updateWinScreen2(window);
                        //else updateDrawScreen(window);
                }
                window.display();
        }

        return 0;
}