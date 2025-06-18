#include "Team_FishOn_TicTacToe_Player.h"

int Player::playerCount = 0;

void Player::setName(const string& n)
{
	name = n;
}

void Player::setAvatarSymbol(char s)
{
	avatarSymbol = s;
}

void Player::setAvatarColor(const sf::Color& c)
{
	avatarColor = c;
}

string Player::getName() const
{
	return name;
}

char Player::getAvatarSymbol() const
{
	return avatarSymbol;
}

sf::Color Player::getAvatarColor() const
{
	return avatarColor;
}




string Player::readStats()
{
	statsFile.clear();
	statsFile.seekg(0, ios::beg);

	string statStr, statLine;

	while (getline(statsFile, statLine))
	{
		statStr += statLine + "\n";
	}

	return statStr;
}

string Player::readAchievements()
{
	string achieveStr, achieveLine;
	while (getline(achievementsFile, achieveLine))
	{
		achieveStr += achieveLine + "\n";
	}
	
	return achieveStr;
}

void Player::updateStats()
{
	ofstream truncFile(statsFilePath, ios::trunc);

	if (truncFile.is_open())
	{
		truncFile <<
			"Games played:\t" << gamesPlayed << "\n" <<
			"Total Wins:\t" << wins << "\n" <<
			"Total Losses:\t" << losses << "\n" <<
			"Total draws:\t" << draws << "\n";


		
		truncFile.close();
	}
}

void Player::updateAchievements(const string& newAchievement)
{
	if (achievementsFile.is_open())
	{
		achievementsFile.clear();
		achievementsFile.seekp(0, ios::end); //end of file
		achievementsFile << newAchievement << "\n";
	}
}

void Player::logWin()
{
	gamesPlayed++;
	wins++;
	updateStats();
}

void Player::logLoss()
{
	gamesPlayed++;
	losses++;
	updateStats();
}

void Player::logDraw()
{
	gamesPlayed++;
	draws++;
	updateStats();
}

void Player::initializePlayerCount()
{
	playerCount = 0;
}

