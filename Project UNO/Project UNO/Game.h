#pragma once
#include "Librarys.h"
#include "Player.h"
#include "Dealer.h"

class Game
{
private:
	Player* playerOne;
	Player* playerTwo;
	DeckCardList* gameCardDeckList;
	DeckCardList* gameDiscardDeckList;
	Dealer* gameDealer;

public:
	Game();
	void fillPlayerName();
	void start();
	bool isGameFinished(Player*&);
	~Game();
};
