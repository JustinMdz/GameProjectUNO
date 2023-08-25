#pragma once
#include "Librarys.h"
#include "DeckCardList.h"
class Dealer
{
private:
	DeckCardList* cardDeckList;
public:
	Dealer();
	~Dealer();

	void setCardList(DeckCardList* ptrCardList);
	DeckCardList* getCardList();

	void shufleMaze();

};

