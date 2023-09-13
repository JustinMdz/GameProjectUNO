#include "Card.h"

Card::Card() {}

Card::Card(string idOfCard, string colorOfCard)
{
	this->cardId = idOfCard;
	this->cardColor = colorOfCard;
}

string Card::getCardId()
{
	return cardId;
}

string Card::getCardColor()
{
	return cardColor;
}

void Card::setCardId(string idOfCard)
{
	this->cardId = idOfCard;
}

void Card::setColor(string cardColor)
{
	this->cardColor = cardColor;
}

string Card::toString()
{
	stringstream ss;
	ss << "Card ID = " << cardId
		<< ", Card Color = " << cardColor;
	return ss.str();
}