#pragma once
#include "Librarys.h"
#include "DeckCardList.h"
class Dealer
{
private:
	DeckCardList* cardDeckList;
public:
	Dealer(DeckCardList*);
	~Dealer();

	void setCardList(DeckCardList* ptrCardList);
	DeckCardList* getCardList();

	int countNodes(DeckCardList* deckOfCards);
	void swapCardsOnNodes(Node*, Node*);
	void shufleMaze(DeckCardList*);
};