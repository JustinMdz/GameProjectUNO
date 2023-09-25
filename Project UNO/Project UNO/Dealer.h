#pragma once
#include "Librarys.h"
#include "DeckCardList.h"

class Dealer
{
private:

	DeckCardList* cardDeckList;
public:

	Dealer();
	Dealer(DeckCardList*);
	~Dealer();

	void setCardList(DeckCardList* ptrCardList);
	DeckCardList* getCardList();

	int countNodes(DeckCardList* deckOfCards);
	void swapCardsOnNodes(Node*, Node*);
	void shuffleCardDeckList(DeckCardList*);
};