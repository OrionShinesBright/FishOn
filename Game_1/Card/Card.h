#pragma once
#include <iostream>

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

	inline void setValue(int val) { value = val; }
	inline void setIsFlipped(bool isFlip) { isFlipped = isFlip; }
	inline void setIsMatched(bool isMat) { isMatched = isMat; }

	inline int getValue() const { return value; }
	inline bool getIsFlipped() const { return isFlipped; }
	inline bool getIsMatched() const { return isMatched; }
};
