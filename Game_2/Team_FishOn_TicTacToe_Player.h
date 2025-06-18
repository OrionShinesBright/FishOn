#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player {
private:

	string name;
	char avatarSymbol;
	sf::Color avatarColor;
	fstream statsFile;
	fstream achievementsFile;
	string statsFilePath;
	string achievementsFilePath;


	//stats
	int gamesPlayed;
	int wins;
	int losses;
	int draws;
public:
	static int playerCount;
	Player()
	{
		playerCount++;
		name = "Player " + playerCount;
		statsFilePath = "Player " + to_string(playerCount) + "_stats.txt";
		achievementsFilePath = "Player " + to_string(playerCount) + "_achievements.txt";
		statsFile.open(statsFilePath, ios::in | ios::out | ios::app);
		achievementsFile.open(achievementsFilePath, ios::in | ios::out | ios::app);

		wins = losses = draws = 0;
	}
	Player(const string& playerName, char symbol, const sf::Color& color)
		: Player()
	{
		name = playerName;
		avatarSymbol = symbol;
		avatarColor = color;
	}
	~Player() {
		if (statsFile.is_open()) statsFile.close();
		if (achievementsFile.is_open()) achievementsFile.close();
	}
	void setName(const string&);
	void setAvatarSymbol(char);
	void setAvatarColor(const sf::Color&);
	string getName() const;
	char getAvatarSymbol() const;
	sf::Color getAvatarColor() const;

	string readStats();
	string readAchievements();
	void updateStats();
	void updateAchievements(const string& newAchievement);

	void logWin();
	void logLoss();
	void logDraw();

	static void initializePlayerCount();

};