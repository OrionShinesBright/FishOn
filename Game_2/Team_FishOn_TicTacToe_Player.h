#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player {
private:
	string name;
	char avatarSymbol;
	sf::Color avatarColor;
	fstream statsFile;
	fstream achievementsFile;
public:
	Player(const string& playerName, char symbol, const sf::Color& color)
		: name(playerName), avatarSymbol(symbol), avatarColor(color) {
		statsFile.open("stats.txt", ios::in | ios::out | ios::app);
		achievementsFile.open("achievements.txt", ios::in | ios::out | ios::app);
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

};