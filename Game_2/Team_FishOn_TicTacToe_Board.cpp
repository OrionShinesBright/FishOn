#include "Team_FishOn_TicTacToe_Board.h"


int Board::getDimension() const
{
    return dimension;
}

void Board::setDimension(int newDimension)
{
    dimension = newDimension;
}

char Board::getGrid(int row, int col) const
{
    if (row < 0 || row >= dimension || col < 0 || col >= dimension)
        return -1; // Invalid cell
    return grid[row][col];
}

void Board::setGrid(int row, int col, char value)
{
    if (row >= 0 && row < dimension && col >= 0 && col < dimension)
    {
        grid[row][col] = value;
    }
}

bool Board::isFull() const
{
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            if (grid[i][j] == '-') 
                return false;
        }
    }
    return true;
}

bool Board::checkRow(int row, int player) const
{
    for (int col = 0; col < dimension; ++col)
    {
        if (grid[row][col] != player)
            return false;
    }
    return true;
}

bool Board::checkColumn(int col, int player) const
{
    for (int row = 0; row < dimension; ++row)
    {
        if (grid[row][col] != player)
            return false;
    }
    return true;
}

bool Board::checkDiagonal(int player) const
{
    for (int i = 0; i < dimension; ++i)
    {
        if (grid[i][i] != player)
            return false;
    }
    return true;
}

bool Board::checkAntiDiagonal(int player) const
{
    for (int i = 0; i < dimension; ++i)
    {
        if (grid[i][dimension - 1 - i] != player)
            return false;
    }
    return true;
}

bool Board::checkWin(int player) const
{
    // Check rows and columns
    for (int i = 0; i < dimension; ++i)
    {
        if (checkRow(i, player) || checkColumn(i, player))
            return true;
    }
    
    // Check diagonals
    return checkDiagonal(player) || checkAntiDiagonal(player);
}

bool Board::isEmpty(int i, int j)
{
        if (grid[i][j] == '-') return true;
        return false;
}

void Board::drawMark(int, int, int)
{

}

void Board::draw(sf::RenderWindow& window)
{
        window.draw(boardSprite);
}

void Board::initializePositions()
{
        for (int i = 0; i < 3; i++)
        {

                for (int j = 0; j < 3; j++)
                {
                        positions[i][j] = Vector2f(boardSprite.getPosition().x - (boardTexture.getSize().x / 2) + 50, boardSprite.getPosition().y - (boardTexture.getSize().y / 2) + 50);
                        positions[i][j] += Vector2f(j * cellWidth, i * cellHeight);
                }
        }
}
