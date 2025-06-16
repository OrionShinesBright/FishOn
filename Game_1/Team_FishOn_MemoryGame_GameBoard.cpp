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
            cards[i][j] = Card(temp[index++]);
        }
    }
}

void GameBoard::shuffleCards()
{
    //I think I've already done it in the previous function
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

void GameBoard::draw()
{
    //Using SFML
}
