#pragma once
constexpr int MAX_SIZE = 8;
class Card
{
private:
	int value;
	bool isFlipped;
	bool isMatched;

public:
	Card(int val = -1) : value(val), isFlipped(false), isMatched(false) {}
	void flip();
	bool checkMatch(Card& other);
	void draw();
	inline void setValue(int val) { value = val; }
	inline void setIsFlipped(bool isFlip) { isFlipped = isFlip; }
	inline void setIsMatched(bool isMat) { isMatched = isMat; }

	inline int getValue() const { return value; }
	inline bool getIsFlipped() const { return isFlipped; }
	inline bool getIsMatched() const { return isMatched; }
};
