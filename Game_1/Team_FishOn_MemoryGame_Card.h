#pragma once
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;


/*****************************************************
* TEAM: FishOn										                   
* MEMBERS:		1. SYED HAIDER ALI JAFRI		24L-0882
*			2. WALEED BIN OMER			24L-0571		
*			3. MUHAMMAD RAFAY			24L-0649	 
*	   MEMORY MATCHING GAME - IDEAL HACKATHON		
*****************************************************/
  
class Card
{
private:
	int value;
	bool isFlipped;
	bool isMatched;


	Texture faceUpTexture;
	Texture faceDownTexture;
	RectangleShape cardRect;


	bool isFlipping = false;
	bool isShrinking = true;
	float currentScale = 1.0f;


	

public:

	const int CARD_WIDTH = 216;
	const int CARD_HEIGHT = 270;


	Card();
	Card(int val);
	void operator=(const Card& other);

	void update();

	void flip();
	bool checkMatch(Card& other);
	void draw(RenderWindow& window);
  
	inline void setValue(int val) { value = val; }
	inline void setIsFlipped(bool isFlip) { isFlipped = isFlip; }
	inline void setIsMatched(bool isMat) { isMatched = isMat; }
	inline void setPosition(Vector2f position) { cardRect.setPosition(position); }
	inline void setScale(float x, float y) { cardRect.setScale(x, y); }
	inline void setCardPosition(const sf::Vector2f& position) { cardRect.setPosition(position); }
	inline void setCardScale(float x, float y) { cardRect.setScale(x, y); }

	inline int getValue() const { return value; }
	inline bool getIsFlipped() const { return isFlipped; }
	inline bool getIsMatched() const { return isMatched; }
	inline RectangleShape getSprite() const { return cardRect; }
	inline const Texture& getFaceUpTexture() const { return faceUpTexture; }
	inline const Texture& getFaceDownTexture() const { return faceDownTexture; }

	
};
