#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Team_FishOn_TicTacToe_Board.h"
#include "Team_FishOn_TicTacToe_Player.h"
#include "Team_FishOn_TicTacToe_AIPlayer.h"

using namespace sf;

class GameManager
{
private:
	Board board;
	Player players[2];
	int currentPlayer;
	int currentCellX;
	int currentCellY;
	bool gameEnd;

	Texture xTexture;
	Texture oTexture;
	Sprite crossSprites[5];
	Sprite circleSprites[5];
	int xUsed;
	int oUsed;


public:
	GameManager();

	void updateWindow(RenderWindow& window);

	void makeMove(RenderWindow& window);

	void endGameWin(int playerIndex);
	void endGameDraw();

	void switchPlayer();

	bool checkWinPlayer1() const;
	bool checkWinPlayer2() const;
	bool checkDraw() const;

	inline Board& getBoard() { return board; }
	inline Player& getPlayer(int code) { return players[code]; }
	inline int getCurrentPlayer() { return currentPlayer; }
	inline int getCurrentCellX() { return currentCellX; }
	inline int getCurrentCellY() { return currentCellY; }
	inline bool getGameEnd() { return gameEnd; }

	inline void setCurrentCellX(int x)
	{
		if (x < 0 || x > 2) return;
		currentCellX = x;
	}
	inline void setCurrentCellY(int y)
	{
		if (y < 0 || y > 2) return;
		currentCellY = y;
	}
	inline void setGameEnd(bool x) { gameEnd = x; }
	
	inline Sprite& getXSprite(int index) { return crossSprites[index]; }
	inline Sprite& getYSprite(int index) { return circleSprites[index]; }
	


};

