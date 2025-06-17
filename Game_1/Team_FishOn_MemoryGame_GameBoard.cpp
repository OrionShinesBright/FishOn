#include "Team_FishOn_MemoryGame_GameBoard.h"

void GameBoard::initializeBoard()
{
	//window loaded using row and cols values
    int totalCards = rows * cols;
    int totalPairs = totalCards / 2;

    int temp[64]; // flat array to hold card values (we could modify it with ascii)
    int index = 0;

    for (int i = 0; i < totalPairs; ++i) {
        temp[index++] = i;
        temp[index++] = i;
    }

    // Values Shuffled using Fisher-Yates (searched it up online)
    std::srand(static_cast<unsigned>(std::time(0)));
    for (int i = totalCards - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        int tmp = temp[i];
        temp[i] = temp[j];
        temp[j] = tmp;
    }

    // Fill 2D cards array
    index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
                Card tempCard(temp[index++]);
                cards[i][j] = tempCard;
                cout << cards[i][j].getValue() << "\n";
        }
    }
}

void GameBoard::shuffleCards()
{
        int totalCards = rows * cols;
        int totalPairs = totalCards / 2;
        int temp[64]; // flat array to hold card values (we could modify it with ascii)

        // Values Shuffled using Fisher-Yates (searched it up online)
        std::srand(static_cast<unsigned>(std::time(0)));
        for (int i = totalCards - 1; i > 0; --i) {
                int j = std::rand() % (i + 1);
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
        }
}

bool GameBoard::checkWin()
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!cards[i][j].getIsMatched()) {
                return false;
            }
        }
    }
    return true;
}

void GameBoard::Draw(RenderWindow& window)
{


        //draw cards
        int padding = 20;
        float scale = 0.75f;
        int cardWidth = static_cast<int>(216 * scale);
        int cardHeight = static_cast<int>(270 * scale);
        int totalWidth = cols * (cardWidth + padding);
        int totalHeight = rows * (cardHeight + padding);
        int startX = (1920 - totalWidth) / 2 + padding / 2;
        int startY = (1080 - totalHeight) / 2 + padding / 2;

        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        //RectangleShape cardRect = cards[i][j].getSprite();

                        //cardRect.setPosition(startX + j * (cardRect.getSize().x + padding), startY + i * (cardRect.getSize().y + padding));
                        //cards[i][j].getSprite().setScale(0.7f, 0.7f);
                        cards[i][j].setCardPosition(Vector2f(startX + j * (cardWidth + padding), startY + i * (cardHeight + padding)));
                        cards[i][j].setCardScale(scale, scale);

                        if (cards[i][j].getIsFlipped()) {
                                cards[i][j].getSprite().setTexture(&cards[i][j].getFaceUpTexture());
                        }
                        else {
                                cards[i][j].getSprite().setTexture(&cards[i][j].getFaceDownTexture());
                        }

                        cards[i][j].update();
                        cards[i][j].draw(window);
                }
        }
}


