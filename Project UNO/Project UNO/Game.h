#pragma once
#include "Librarys.h"
#include "Player.h"
#include "Dealer.h"

class Graphics;

class Game {

private:

	Player* playerOne;
	Player* playerTwo;
	DeckCardList* gameCardDeckList;
	DeckCardList* gameDiscardDeckList;
	Dealer* gameDealer;
	Graphics* gameGraphics;

	int actualPlayer = 1;
	int indexPlayerTurn = 0;

public:
	Game();

	void processGamePrincipalMenuOptions();
	void fillPlayerName();
	void start();
	bool isGameFinished(Player*&);
	void loadGraphicCardLists();

	void firstPlayByDefault();
	void playerTurn(Player*&);
	Player*& getPlayerOnTurn();
	~Game();
};