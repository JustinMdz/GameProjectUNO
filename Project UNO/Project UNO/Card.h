#pragma once
#include "Librarys.h"
class Card
{
private:
	string cardId;
	string cardColor;
	
public:
	Card();
	Card(string idOfCard, string colorOfCard);
	string getCardColor();
	string getCardId();
	void setColor(string);
	void setCardId(string);
	string toString();
};