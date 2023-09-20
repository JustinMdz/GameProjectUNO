#pragma once
#include "Librarys.h"
#include "DeckCardList.h"
#include "Node.h"

class Graphics;

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

	bool checkIsPossibleTrowNormalCard(DeckCardList*&);
	bool checkIsPossibleTrowSpecialCard();
	bool checkIsTrowPossible(DeckCardList*&);

	void selectCardToTrow(Graphics*&, DeckCardList*&);

	void grabCard(int cardsToDraw, DeckCardList*& deckOfGame);

	void printPlayerDeck();

	~Player();
};