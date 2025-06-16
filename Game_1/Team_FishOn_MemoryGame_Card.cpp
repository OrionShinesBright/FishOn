#include "Team_FishOn_MemoryGame_Card.h"



Card::Card(int val) : value(val), isFlipped(false), isMatched(false)
{

	cardRect.setSize(Vector2f(CARD_WIDTH, CARD_HEIGHT));

	//prepare face-up texture
	string cardPath = "CardTextures/";
	cardPath.append(to_string(value));
	cardPath.append(".png");


	//load pngs into textures
	faceDownTexture.loadFromFile("CardTextures/cardBackBlue.png");
	faceUpTexture.loadFromFile(cardPath);

	//apply texture to card sprite
	cardRect.setTexture(&faceDownTexture);


	cardRect.setOrigin(CARD_WIDTH / 2, CARD_HEIGHT / 2);
	cardRect.setPosition(CARD_WIDTH / 2, CARD_HEIGHT/2);

}

void Card::operator=(const Card& other)
{
	value = other.value;
	isFlipped = other.isFlipped;
	isMatched = other.isMatched;
	cardRect = other.cardRect;
}




void Card::update()
{
	if (isFlipping)
	{
		if (isShrinking)
		{
			currentScale -= 0.002f;
			if (currentScale <= 0.0f)
			{
				currentScale = 0.0f;

				// Swap texture here
				isFlipped = !isFlipped;
				if (isFlipped)
					cardRect.setTexture(&faceUpTexture);
				else
					cardRect.setTexture(&faceDownTexture);

				isShrinking = false;
			}
		}
		else // growing back
		{
			currentScale += 0.002f;
			if (currentScale >= 1.0f)
			{
				currentScale = 1.0f;
				isFlipping = false;
			}
		}
		cardRect.setScale(currentScale, 1.0f);
	}
}

void Card::flip()
{
	if (!isFlipping) // start a new flip
	{
		isFlipping = true;
		isShrinking = true;
		currentScale = 1.0f;
		cardRect.setScale(1.0f, 1.0f);

	}
}






bool Card::checkMatch(Card& other)
{
	if (value == other.value) {
		isMatched = true;
		other.isMatched = true;
		return true;
	}
	return false;
}

void Card::draw(RenderWindow& window)
{
	window.draw(cardRect);
	//if (isFlipped) {
	//	//draw sprite using SFML
	//}
	//else if (isMatched) {
	//	//draw matched sprite
	//}
	//else {
	//	//maybe load first and...
	//	//draw the general sprite
	//}
}
