#include "Card.h"

Card::Card(string idOfCard)
{
	cardId = idOfCard;
}

Card::Card(string idOfCard, string colorOfCard)
{
	cardId = idOfCard;
	cardColor = colorOfCard;
}

string Card::getCardColor()
{
	return cardColor;
}

string Card::getCardId()
{
	return cardId;
}

void Card::setColor(string cardColor)
{
	this->cardColor = cardColor;
}

void Card::setCardId(string idOfCard)
{
	this->cardId = idOfCard;
}

string Card::toString()
{
	stringstream ss;
	ss << "Card ID = " << cardId
		<< ", Card Color = " << cardColor;
	return ss.str();
}