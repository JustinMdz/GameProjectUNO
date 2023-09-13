#include "Player.h"

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

bool Player::checkPlayerWrittenCard(string idOfCardToCheck, string colorOfCardToCheck, DeckCardList*& discardMaze)
{
	bool wrritenIsOk = false;

	if ((idOfCardToCheck == discardMaze->getFirstNode()->getUnoCard()->getCardId()) ||
		(colorOfCardToCheck == discardMaze->getFirstNode()->getUnoCard()->getCardColor())) {

		wrritenIsOk = true;
	}

	if ((idOfCardToCheck != discardMaze->getFirstNode()->getUnoCard()->getCardId()) &&
		(colorOfCardToCheck != discardMaze->getFirstNode()->getUnoCard()->getCardColor())) {
		cout << "Error, enter the card ID and color again please";
	}

	return wrritenIsOk;
}

void Player::selectCardToTrow(DeckCardList*& discardMaze)
{
	string colorOfCardToCheck;
	string idOfCardToCheck;

	bool stringError = true;
	Card* cardToMove;

	while (stringError == true) {

		cout << "\n\nEnter the ID of the card to trow: ";
		cin >> idOfCardToCheck;

		cout << "\n\nNow enter the color of card to trow: ";
		cin >> colorOfCardToCheck;

		if ((checkPlayerWrittenCard(idOfCardToCheck, colorOfCardToCheck, discardMaze)) == true) {

			cardToMove = playerDeckCardList->getCardToMove(idOfCardToCheck, colorOfCardToCheck);
			discardMaze->insertFirstNode(cardToMove);

			playerDeckCardList->deleteNode(cardToMove);
			stringError = false;
		}
	}
}

void Player::grabCard(int cardsToDraw, DeckCardList*& deckOfGame)//supongo que en una clase futuro game o rules tendra este metodo por parametro
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