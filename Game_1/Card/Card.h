#pragma once
class Card
{
private:
	int value;
	bool isFlipped;
	bool isMatched;

public:
	void flip();
	bool checkMatch(Card other);
	void draw();
};
