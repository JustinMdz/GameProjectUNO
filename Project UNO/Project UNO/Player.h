#pragma once
#include "Librarys.h"
#include "DeckCardList.h"
#include "Node.h"
class Player
{
private:
	string playerName;
	DeckCardList* playerDeckCardList;

public:

	Player();

	void setName(string);
	string getName();

	void setPlayerDeck(DeckCardList* deckOfPlayer);
	DeckCardList* getPlayerDeck();

	void printPlayerDeck();

	~Player();
};