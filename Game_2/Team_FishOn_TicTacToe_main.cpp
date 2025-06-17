#include <iostream>
#define MAX_BOARD_SIZE 5

int main() {
	std::cout << "Hello, World!\n";

	/*
 	GAME LOOP:
  	Now.. listen to me.. idk what condition is required to call the AI move, but, 
   	whenever that conditin is satisfied, this is how you must call the AI's move:
    		char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE]; //cuz its a square DUH
		// Fill in board with current game state
		AIPlayer ai('O', 'X');
		sf::Vector2i move = ai.getBestMove(board, currentBoardSize);
  	Also, don't worry about whether you need to call the easy medium or hard AI,
   	cuz I have already made this function check what szed board we have.. this is important
    	cuz smol board == weak ai.. so.. you dont need to handle that here. it is already
     	handled in the class itself.
  	*/
	
	return 0;
}
