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

void Player::printPlayerDeck()
{
	playerDeckCardList->printList();
}

Player::~Player() {}