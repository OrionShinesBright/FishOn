#pragma once
#include<iostream>
#include <string>
#include <stdexcept>
#include <SFML/Graphics.hpp>
using namespace std;
const int MAX_SIZE = 5;
class Board {
private:
	int dimension;
	int grid[MAX_SIZE][MAX_SIZE];
	sf::RectangleShape rectangle;
	sf::Text text;
public:
	Board(int dim) : dimension(dim) {
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				grid[i][j] = 0;
			}
		}
	}
	int getDimension() const;
	void setDimension(int);
	int getGrid(int, int) const;
	void setGrid(int, int, int);
	bool isFull() const;
	bool checkRow(int, int) const;
	bool checkColumn(int, int) const;
	bool checkDiagonal(int) const;
	bool checkAntiDiagonal(int) const;
	bool checkWin(int) const;
	void drawMark(int, int, int);
	void draw(sf::RenderWindow& window) const;
};