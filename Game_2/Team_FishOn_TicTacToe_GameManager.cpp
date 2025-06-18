#include "Team_FishOn_TicTacToe_GameManager.h"

GameManager::GameManager()
{
	gameEnd = false;
	currentPlayer = 0;

	//initialize players
	players[0].setAvatarSymbol('X');
	players[0].setAvatarColor(Color::Red);
	players[0].setName("Player 1");

	players[1].setAvatarSymbol('O');
	players[1].setAvatarColor(Color::Blue);
	players[1].setName("Player 2");

	currentCellX = currentCellY = -1;


	//Loading X
	xTexture.loadFromFile("cross.png");

	for (int i = 0; i < 5; i++)
	{
		crossSprites[i].setTexture(xTexture);
		crossSprites[i].setOrigin(xTexture.getSize().x / 2, xTexture.getSize().y / 2);
		crossSprites[i].setPosition(board.getPosition(currentCellY,currentCellX));
	}



        //Loading O
        oTexture.loadFromFile("circle.png");

	for (int i = 0; i < 5; i++)
	{
		circleSprites[i].setTexture(oTexture);
		circleSprites[i].setOrigin(oTexture.getSize().x / 2, oTexture.getSize().y / 2);
		circleSprites[i].setPosition(board.getPosition(currentCellY, currentCellX));
	}

	xUsed = oUsed = 0;
}



void GameManager::updateWindow(RenderWindow& window)
{


	char symbol = players[currentPlayer].getAvatarSymbol();
	int row = currentCellY;
	int col = currentCellX;
	
	makeMove(window); //makes move, does win checks and switches to next player



	//draw
	if (symbol == 'X')
	{
		crossSprites[xUsed].setPosition(board.getPosition(row, col));
		window.draw(crossSprites[xUsed]);
		xUsed++;
	}
	else if (symbol == 'O')
	{
		circleSprites[oUsed].setPosition(board.getPosition(row, col));
		window.draw(circleSprites[oUsed]);
		oUsed++;
	}

	


}

void GameManager::makeMove(RenderWindow& window)
{
	//input

	//check if grid cell empty
	//if filled, return
	if (board.getGrid(currentCellY, currentCellX) != '-')
	{
		return;
	}




	board.setGrid(currentCellY, currentCellX, players[currentPlayer].getAvatarSymbol()); //mark grid cell with player symbol


	if (checkWinPlayer1())
	{
		endGameWin(0);
		return;
	}
	if (checkWinPlayer2())
	{
		endGameWin(1);
		return;
	}
	if (checkDraw())
	{
		endGameDraw();
		return;
	}

	//if game doesn't end, switch player
	switchPlayer();

}

void GameManager::endGameWin(int playerIndex)
{
	gameEnd = true;
	players[playerIndex].logWin();
	players[!playerIndex].logLoss();
	//player wins


}

void GameManager::endGameDraw()
{
	gameEnd = true;
	players[0].logDraw();
	players[1].logDraw();
	//draw
}

void GameManager::switchPlayer()
{
	if (currentPlayer == 0) currentPlayer = 1;
	else currentPlayer = 0;
}

bool GameManager::checkWinPlayer1() const
{
	return board.checkWin(players[0].getAvatarSymbol());
}

bool GameManager::checkWinPlayer2() const
{
	return board.checkWin(players[1].getAvatarSymbol());
}



bool GameManager::checkDraw() const
{
	if (board.isFull() && !(checkWinPlayer1()) && !(checkWinPlayer2()))
		return true;
	return false;

}


