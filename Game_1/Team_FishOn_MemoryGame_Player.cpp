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

void Player::displayStats()
{
	cout << "Player: " << name << "\n";
	cout << "Score: " << score << "\n";
	cout << "Games Won: " << gamesWon << "\n";
}
