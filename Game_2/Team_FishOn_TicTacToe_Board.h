#pragma once
#include <string>
#include <stdexcept>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
const int MAX_SIZE = 5;
class Board {
public:
	int dimension;
	char grid[MAX_SIZE][MAX_SIZE];
	sf::RectangleShape rectangle;
	Texture boardTexture;
	Sprite boardSprite;
	Vector2f positions[3][3];
	sf::Text text;

	double cellWidth;
	double cellHeight;
public:
	Board()
	{
		//initialize grid
		dimension = 3;
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				grid[i][j] = '-';
			}
		}


		//Loading Board
		boardTexture.loadFromFile("board.png");

		boardSprite.setTexture(boardTexture);
		boardSprite.setScale(
			(float)1080 / boardTexture.getSize().y,
			(float)1080 / boardTexture.getSize().y
		);
		boardSprite.setOrigin(boardTexture.getSize().x / 2, boardTexture.getSize().y / 2);
		boardSprite.setPosition(1920 / 2, 1080 / 2);


		//Initializing cell width and height
		cellWidth = ((boardTexture.getSize().x) / 3) + 50;
		cellHeight = (((boardTexture.getSize().y)) / 3) + 50;


		//Initializing positions
		initializePositions();
	}

	int getDimension() const;
	void setDimension(int);
	char getGrid(int, int) const;
	void setGrid(int, int, char);
	bool isFull() const;
	bool checkRow(int, int) const;
	bool checkColumn(int, int) const;
	bool checkDiagonal(int) const;
	bool checkAntiDiagonal(int) const;
	bool checkWin(int) const;
	bool isEmpty(int i, int j);
	void drawMark(int, int, int);
	void draw(sf::RenderWindow& window);
	void initializePositions();

	inline double getCellWidth() { return cellWidth; }
	inline double getCellHeight() { return cellHeight; }
	inline Vector2f getPosition(int i, int j) { return positions[i][j]; }
	inline Sprite& getBoardSprite() { return boardSprite; }
};