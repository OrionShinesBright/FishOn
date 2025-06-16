#pragma once
#include <iostream>


/*****************************************************
* TEAM: FishOn										 *
* MEMBERS:	1. SYED HAIDER ALI JAFFRI	24L-0		 *
*			2. WALEED BIN OMER			24L-0		 *
*			3. MUHAMMAD RAFAY			24L-0649	 *
*	   MEMORY MATCHING GAME - IDEAL HACKATHON		 *
*****************************************************/


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
