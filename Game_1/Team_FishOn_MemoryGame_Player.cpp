#include "Team_FishOn_MemoryGame_Player.h"

void Player::updateScore(int points)
{
	score += points;
	ofstream out("scores.txt", std::ios::app);
	if (out.is_open()) {
		out << name << " updated score to " << score << endl;
		out.close();
	}
}

void Player::incrementWins()
{
	gamesWon++;
	std::ofstream out("scores.txt", std::ios::app);
	if (out.is_open()) {
		out << name << " won a game (total wins: " << gamesWon << ")\n";
		out.close();
	}
}

void Player::displayStats(RenderWindow& window, int playerNum)
{
	

	// Prepare text
	Font textFont;
	textFont.loadFromFile("Roboto-Black.ttf");
	Text scoreText;
	scoreText.setFont(textFont);
	scoreText.setString("Player: " + name + "\nScore: " + std::to_string(score) + "\nGames Won: " + std::to_string(gamesWon));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(Color::White);
	if (playerNum == 0)
	{
		scoreText.setPosition(50, 20);
	}
	else
	{
		scoreText.setPosition(1400, 20);
	}


	window.draw(scoreText);
}
