#pragma once
#include "DeckCardList.h"
#include "Dealer.h"
#include "Player.h"
class Rule
{
private:

public:

	Rule();

	void reverseCardAndBlockCard(int&, Player*&, DeckCardList*&);
	void zeroRule(Player*&, Player*&, DeckCardList*&);
	void changeColor(Player*&, DeckCardList*&, DeckCardList*&);
	void grabCards(Player*& , DeckCardList*&, DeckCardList*&);
};

