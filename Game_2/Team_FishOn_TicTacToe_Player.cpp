#include "Team_FishOn_TicTacToe_Player.h"

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


