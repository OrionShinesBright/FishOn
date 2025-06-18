#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_TicTacToe_GameManager.h"
#include <string>
#include "Team_FishOn_TicTacToe_AIPlayer.h"


const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;




//Initialize Game
GameManager manager;


 

void updateWinScreen(RenderWindow& window, bool& gotoEndFlag)
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

        Text continueText;
        continueText.setFont(winFont);
        continueText.setFillColor(Color::White);
        continueText.setString("Press [Space] to Continue...");
        continueText.setCharacterSize(80);
        continueText.setOrigin(continueText.getGlobalBounds().getSize().x / 2, continueText.getGlobalBounds().getSize().y / 2);
        continueText.setPosition(Vector2f(WINDOW_WIDTH / 2, 3 * WINDOW_HEIGHT / 4));

        window.draw(background);
        window.draw(winText);
        window.draw(continueText);


        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
                gotoEndFlag = true;
        }
}

void updateDrawScreen(RenderWindow& window, bool& gotoEndFlag)
{
        RectangleShape background(Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
        background.setFillColor(Color::White);
        Font winFont;
        winFont.loadFromFile("Roboto-Black.ttf");

        Text drawText;
        drawText.setFont(winFont);
        drawText.setFillColor(Color::Black);
        drawText.setString("It's a draw!");
        drawText.setCharacterSize(260);
        drawText.setOrigin(drawText.getGlobalBounds().getSize().x / 2, drawText.getGlobalBounds().getSize().y / 2);
        drawText.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        Text continueText;
        continueText.setFont(winFont);
        continueText.setFillColor(Color::Black);
        continueText.setString("Press [Space] to Continue...");
        continueText.setCharacterSize(80);
        continueText.setOrigin(continueText.getGlobalBounds().getSize().x / 2, continueText.getGlobalBounds().getSize().y / 2);
        continueText.setPosition(Vector2f(WINDOW_WIDTH / 2, 3 * WINDOW_HEIGHT / 4));

        window.draw(background);
        window.draw(drawText);
        window.draw(continueText);


        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
                gotoEndFlag = true;
        }

}


bool waitingForAI = false;
AIPlayer ai('O', 'X');  // Only onceAIPlayer ai('O', 'X');

      
int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
        
        //game mode select
        Texture modeScreenTexture;
        modeScreenTexture.loadFromFile("notebook.png");
        Sprite modeScreenBackground;
        modeScreenBackground.setTexture(modeScreenTexture);
        modeScreenBackground.setScale(
                (float)WINDOW_WIDTH / modeScreenTexture.getSize().x,
                (float)WINDOW_HEIGHT / modeScreenTexture.getSize().y
        );
        bool isModeSelect = true;
        Font modeSelectFont;
        modeSelectFont.loadFromFile("Roboto-Black.ttf");
        Text modeSelectText;
        modeSelectText.setFont(modeSelectFont);
        modeSelectText.setFillColor(Color::Black);
        modeSelectText.setCharacterSize(60);
        modeSelectText.setString("TIC TAC TOE\nPress [1] to play against Player\nPress [2] to play against Computer");
        modeSelectText.setOrigin(modeSelectText.getGlobalBounds().getSize().x / 2, modeSelectText.getGlobalBounds().getSize().y / 2);
        modeSelectText.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 6);

        


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



        //game mode flags
        bool pvpFlag = false;
        bool aiFlag = false;


        //end assets
        
        bool gotoEndFlag = false;
        bool readFilesFlag = true;
        string stats1, stats2;


        Texture endBackgroundTexture;
        endBackgroundTexture.loadFromFile("notebook.png");
        Sprite endBackground;
        endBackground.setTexture(endBackgroundTexture);
        endBackground.setScale(
                (float)WINDOW_WIDTH / endBackgroundTexture.getSize().x,
                (float)WINDOW_HEIGHT / endBackgroundTexture.getSize().y
        );
       

        Font endFont;
        Text endText1;
        Text endText2;
        Text endInstructionText;

        
        bool initializeEndAssetsFlag = true;



        while (window.isOpen())
        {
                while (isModeSelect)
                {
                        sf::Event event;
                        while (window.pollEvent(event))
                        {
                                if (event.type == sf::Event::Closed)
                                        window.close();
                        }


                        //input
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                        {
                                pvpFlag = true;
                                isModeSelect = false;
                        }
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                        {
                                aiFlag = true;
                                isModeSelect = false;
                        }

                        //render
                        window.clear();
                        window.draw(modeScreenBackground);
                        window.draw(modeSelectText);
                        window.display();

                        
                }
                
                if (readFilesFlag & gotoEndFlag)
                {
                        stats1 = manager.getPlayer(0).getName() + "\n" + manager.getPlayer(0).readStats();
                        stats2 = manager.getPlayer(1).getName() + "\n" + manager.getPlayer(1).readStats();
                        readFilesFlag = false;

                }
                if (initializeEndAssetsFlag && gotoEndFlag)
                {

                        endFont.loadFromFile("Roboto-Black.ttf");

                        endText1.setFont(endFont);
                        endText1.setFillColor(manager.getPlayer(0).getAvatarColor());
                        endText1.setCharacterSize(60);
                        endText1.setString(stats1);
                        sf::FloatRect bounds1 = endText1.getLocalBounds();
                        endText1.setOrigin(bounds1.left + bounds1.width / 2, bounds1.top + bounds1.height / 2);
                        endText1.setPosition(Vector2f(WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2));

                        endText2.setFont(endFont);
                        endText2.setFillColor(manager.getPlayer(1).getAvatarColor());
                        endText2.setCharacterSize(60);
                        endText2.setString(stats2);
                        sf::FloatRect bounds2 = endText2.getLocalBounds();
                        endText2.setOrigin(bounds2.left + bounds2.width / 2, bounds2.top + bounds2.height / 2);
                        endText2.setPosition(Vector2f(2 * WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2));

                        endInstructionText.setFont(endFont);
                        endInstructionText.setFillColor(Color::Black);
                        endInstructionText.setCharacterSize(60);
                        endInstructionText.setString("Press [Escape] to Quit");
                        sf::FloatRect bounds3 = endInstructionText.getLocalBounds();
                        endInstructionText.setOrigin(bounds3.left + bounds3.width / 2, bounds3.top + bounds3.height / 2);
                        endInstructionText.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 6));

                        initializeEndAssetsFlag = false;
                }
               
                if (pvpFlag && !gotoEndFlag)
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
                                if (manager.checkWinPlayer1() || manager.checkWinPlayer2()) updateWinScreen(window, gotoEndFlag);
                                else updateDrawScreen(window, gotoEndFlag);

                        }
                }
                else if (aiFlag && !gotoEndFlag)
                {
                        bool isAiTurn = false;

                        sf::Event event;
                        while (window.pollEvent(event))
                        {
                                if (event.type == sf::Event::Closed)
                                        window.close();


                                if (event.type == sf::Event::MouseButtonReleased &&
                                        event.mouseButton.button == sf::Mouse::Left &&
                                        !manager.getGameEnd() &&
                                        manager.getCurrentPlayer() == 0)  // Only allow if it's player’s turn                                {
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


                                        // After player moves, check if it's AI's turn now
                                        if (manager.getCurrentPlayer() == 1)
                                                waitingForAI = true;
                                }
                        }

                      

                        manager.getPlayer(1).setName("Computer");



                        //update text
                        string name;
                        if (manager.getCurrentPlayer() == 0)
                        {
                                scoreText.setString("Player 1's Turn");
                                name = manager.getPlayer(0).getName();
                        }
                        else
                        {
                                scoreText.setString("Computer's Turn");
                                name = "Computer";
                        }

                        nameText.setString("Name:\t" + name);

                        avatarText.setFillColor(manager.getPlayer(manager.getCurrentPlayer()).getAvatarColor());
                        avatarText.setString(manager.getPlayer(manager.getCurrentPlayer()).getAvatarSymbol());





                      // AI move section
if (waitingForAI && manager.getCurrentPlayer() == 1 && !manager.getGameEnd())
{
    sf::sleep(sf::seconds(0.5f)); // Optional pause

    char grid[5][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = manager.getBoard().getGrid(i, j);
        }
    }

    Vector2i move = ai.getBestMove(grid, 3);
    manager.setCurrentCellX(move.x);
    manager.setCurrentCellY(move.y);
    manager.updateWindow(window);

    waitingForAI = false;
}









                        window.clear();

                        if (!manager.getGameEnd()) //if game is running
                        {
                                window.draw(background);
                                manager.getBoard().draw(window);
                                system("cls");
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
                                if (manager.checkWinPlayer1() || manager.checkWinPlayer2()) updateWinScreen(window, gotoEndFlag);
                                else updateDrawScreen(window, gotoEndFlag);

                        }









                }
                else
                {
                        sf::Event event;
                        while (window.pollEvent(event))
                        {
                                if (event.type == sf::Event::Closed)
                                        window.close();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                                exit(0);
                        }
                        



			window.clear();

			window.draw(endBackground);
			window.draw(endText1);
			window.draw(endText2);
                        window.draw(endInstructionText);

                      
                }
                window.display();
        }

        return 0;
}