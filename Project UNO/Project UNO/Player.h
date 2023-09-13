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

	bool checkIsPossibleTrowNormalCard(DeckCardList*&);
	bool checkIsPossibleTrowSpecialCard();
	bool checkIsTrowPossible(DeckCardList*&);

	bool checkPlayerWrittenCard(string, string, DeckCardList*&);
	void selectCardToTrow(DeckCardList*&);

	void trowNormalCard(DeckCardList*& discardMaze);
	void trowSpecialCard();
	void trowCard();

	void grabCard(int cardsToDraw, DeckCardList*& deckOfGame);

	void printPlayerDeck();

	~Player();
};