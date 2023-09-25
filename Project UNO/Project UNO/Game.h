#pragma once
#include "Librarys.h"
#include "Player.h"
#include "Dealer.h"
#include "Rule.h"

class Graphics;

class Game {

private:

	Player* playerOne;
	Player* playerTwo;
	DeckCardList* gameCardDeckList;
	DeckCardList* gameDiscardDeckList;
	Dealer* gameDealer;
	Graphics* gameGraphics;
	Rule* gameRules;

	int actualPlayer = 1;
	int indexPlayerTurn = 0;

public:
	Game();

	void fillPlayerName();
	void run();
	bool isGameFinished(Player*&);

	void firstPlayByDefault();
	void playerTurn(Player*&);
	Player*& getPlayerOnTurn();
	void loadAllGraphicsDecks();
	bool isButtonStarGamePressed();

	~Game();
};