#include "Player.h"

void Player::loadHighScore()
{
	ifstream file(HIGH_SCORE_FILE_PATH);
	if (file >> highScore) file.close();
	else highScore = 0;
}

void Player::writeHighScore()
{

	std::ofstream outFile(HIGH_SCORE_FILE_PATH);
	if (outFile)
		outFile << highScore;

}
