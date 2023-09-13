#pragma once
#include "Librarys.h"
#include "Player.h"
#include "Dealer.h"

class Game {

private:
	Player* playerOne;
	Player* playerTwo;
	DeckCardList* gameCardDeckList;
	DeckCardList* gameDiscardDeckList;
	Dealer* gameDealer;

	int actualPlayer = 1;
	int indexPlayerTurn = 0;

public:
	Game();

	void fillPlayerName();
	void start();
	bool isGameFinished(Player*&);

	void firstPlayByDefault();
	void playerTurn(Player*&);
	Player*& getPlayerOnTurn();
};