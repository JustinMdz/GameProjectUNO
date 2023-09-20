#include "Player.h"
#include "Graphics.h"

Player::Player()
{
	playerDeckCardList = new DeckCardList();
}

void Player::setName(string nameOfPlayer)
{
	this->playerName = nameOfPlayer;

}

string Player::getName()
{
	return playerName;
}

void Player::setPlayerDeck(DeckCardList* deckOfPlayer)
{
	this->playerDeckCardList = deckOfPlayer;
}

DeckCardList* Player::getPlayerDeck()
{
	return playerDeckCardList;
}

bool Player::checkIsPossibleTrowNormalCard(DeckCardList*& discardMaze)
{
	string idOfCardToCheck;
	string colorOfCardToCheck;

	string discardCardColor = discardMaze->getFirstNode()->getUnoCard()->getCardColor();
	string discardCardId = discardMaze->getFirstNode()->getUnoCard()->getCardId();

	bool cardFound = false;

	Node* auxCurrentNode = playerDeckCardList->getFirstNode();

	while ((cardFound != true) || (auxCurrentNode != NULL)) {

		colorOfCardToCheck = auxCurrentNode->getUnoCard()->getCardColor();
		idOfCardToCheck = auxCurrentNode->getUnoCard()->getCardId();

		if ((discardCardColor == colorOfCardToCheck) || (discardCardId == idOfCardToCheck)) {
			cardFound = true;
		}
		auxCurrentNode = auxCurrentNode->getNextNode();
	}
	return cardFound;
}

bool Player::checkIsPossibleTrowSpecialCard()
{
	bool specialCardFound = false;
	string idOfCardToCheck;

	string specialCardChangueColor = "ChangeColor";
	string specialCardGrabFour = "+4";

	Node* auxCurrentNode = playerDeckCardList->getFirstNode();

	while ((specialCardFound != true) || (auxCurrentNode != NULL)) {

		idOfCardToCheck = auxCurrentNode->getUnoCard()->getCardId();

		if ((specialCardChangueColor == idOfCardToCheck) || (specialCardGrabFour == idOfCardToCheck)) {
			specialCardFound = true;
		}
		auxCurrentNode = auxCurrentNode->getNextNode();
	}
	return specialCardFound;
}

bool Player::checkIsTrowPossible(DeckCardList*& discardMaze)
{
	bool isTrowPossible = false;
	if (checkIsPossibleTrowNormalCard(discardMaze) ||
		(checkIsPossibleTrowSpecialCard() == true))
	{
		isTrowPossible = true;
	}
	return isTrowPossible;
}


void Player::grabCard(int cardsToDraw, DeckCardList*& deckOfGame)
{
	for (int index = 0; index < cardsToDraw; index++) {
		playerDeckCardList->moveFirstCardOnList(playerDeckCardList, deckOfGame);
	}
}

void Player::printPlayerDeck()
{
	playerDeckCardList->printList();
}

Player::~Player() {}