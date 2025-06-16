#include "Card.h"

void Card::flip()
{
	if (isFlipped == false) {
		//load sprite according to value
	}
	isFlipped = true;
	
}

bool Card::checkMatch(Card& other)
{
	if (value == other.value) {
		isMatched = true;
		other.isMatched = true;
		//load matched sprite for both
		return true;
	}
	return false;
}

void Card::draw()
{
	if (isFlipped) {
		//draw sprite using SFML
	}
	else if (isMatched) {
		//draw matched sprite
	}
	else {
		//maybe load first and...
		//draw the general sprite
	}
}
