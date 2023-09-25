#include "Rule.h"

Rule::Rule()
{
}

void Rule::reverseCardAndBlockCard(int& indexTurnsofPlayers, Player*& playerOnTurn, DeckCardList*& discardGameList)
{
	if (discardGameList->getFirstNode()->getUnoCard()->getCardId() == "Reverse" || "Block") {
		playerOnTurn->finishTurn();
	}
}

void Rule::zeroRule(Player*& playerOne, Player*& playerTwo, DeckCardList*& discardGameList)
{
	DeckCardList* auxDeck;
	if (discardGameList->getFirstNode()->getUnoCard()->getCardId() == "0") {
		auxDeck = playerOne->getPlayerDeck();
		playerOne->setPlayerDeck(playerTwo->getPlayerDeck());
		playerTwo->setPlayerDeck(auxDeck);
	}
}

void Rule::changeColor(Player*& playerOnTurn, DeckCardList*& discardGameList, DeckCardList*& deckGameCardList)
{
	if (playerOnTurn->checkIsTrowPossible(discardGameList)) {
		//playerOnTurn->selectCardToTrow();
	}
	if(!playerOnTurn->checkIsTrowPossible(discardGameList)) {
		playerOnTurn->grabCard(1,deckGameCardList);
		playerOnTurn->finishTurn();
	}
}

void Rule::grabCards(Player*& playerOnTurn, DeckCardList*& discardGameList,DeckCardList*& deckGameCardList)
{
	string colorCardPlus2 = "+2";
	string specialCardPlus4 = "+4";

	int cardsToGrabIfColorCardPlus2 = 2;
	int cardsToGrabIfSpecialCardPlus4 = 4;

	if (discardGameList->getFirstNode()->getUnoCard()->getCardId() == colorCardPlus2) {
		playerOnTurn->grabCard(cardsToGrabIfColorCardPlus2,deckGameCardList);
	}

	if (discardGameList->getFirstNode()->getUnoCard()->getCardId() == specialCardPlus4) {
		playerOnTurn->grabCard(cardsToGrabIfSpecialCardPlus4, deckGameCardList);
	}
}