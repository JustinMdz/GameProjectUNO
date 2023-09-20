#include "DeckCardList.h"

DeckCardList::DeckCardList()
{
	firstNode = currentNode = NULL;
}

DeckCardList::~DeckCardList()
{
	while (firstNode != NULL) {
		currentNode = firstNode;
		firstNode = firstNode->getNextNode();
		delete currentNode;
	}
}

void DeckCardList::setFirstNode(Node* ptrFirstNode)
{
	firstNode = ptrFirstNode;
}

Node* DeckCardList::getFirstNode()
{
	return firstNode;
}

void DeckCardList::insertFirstNode(Card* ptrCard)
{
	firstNode = new Node(ptrCard, firstNode);
}

void DeckCardList::deleteFirstNode()
{
	currentNode = firstNode;
	if (firstNode != NULL) {
		firstNode = currentNode->getNextNode();
		delete currentNode;
	}
}

void DeckCardList::deleteNode(Card*& cardToMove)
{
	string colorCardInDeck = firstNode->getUnoCard()->getCardColor();
	string idCardInDeck = firstNode->getUnoCard()->getCardId();
	string cardId = cardToMove->getCardId();
	string cardColor = cardToMove->getCardColor();

	Node* auxDeleteNode;
	Node* previuosNode = NULL;

	auxDeleteNode = firstNode;

	if (auxDeleteNode != NULL) {

		while ((auxDeleteNode != NULL) || ((cardId != idCardInDeck) && (cardColor != colorCardInDeck))) {
			previuosNode = auxDeleteNode;
			auxDeleteNode->getNextNode();
			colorCardInDeck = auxDeleteNode->getUnoCard()->getCardColor();
			idCardInDeck = auxDeleteNode->getUnoCard()->getCardId();
		}

		if (previuosNode == NULL) {
			deleteFirstNode();
		}

		else {
			previuosNode->setNextNode(auxDeleteNode->getNextNode());
			delete auxDeleteNode;
		}
	}
}

void DeckCardList::insertZeros()
{
	string auxCardColors[] = { "Red", "Blue", "Green", "Yellow" };
	string ceroesId = "0";

	int cardColors = 4;
	Card* card; 

	for (int index = 0; index < cardColors; index++) {
		card = new Card(ceroesId, auxCardColors[index]);
		insertFirstNode(card);
	}
}

void DeckCardList::insertSpecialCards()
{
	Card* specialCard;
	string specialCards[] = { "ChangeColor", "+4" };
	string colorOfSpecialCard = "Black";
	int quantitySpecialsCards = 2;
	int specialCardsCopies = 4;

	for (int index1 = 0; index1 < quantitySpecialsCards; index1++) {
		for (int index2 = 0; index2 < specialCardsCopies; index2++) {
			specialCard = new Card(specialCards[index1], colorOfSpecialCard);
			insertFirstNode(specialCard);
		}
	}
}

void DeckCardList::insertNormalCards()
{
	string cardColors[] = { "Red", "Blue", "Green", "Yellow" };
	string cardValuesId[] = { "1","2", "3", "4", "5", "6", "7", "8", "9", "Block", "Reverse", "+2" };
	Card* normalCard;

	for (const string& colorIndex : cardColors) {
		for (const string& valueIdIndex : cardValuesId) {
			normalCard = new Card(valueIdIndex, colorIndex);
			insertFirstNode(normalCard);
		}
	}
}

void DeckCardList::runList()
{
	insertZeros();
	insertSpecialCards();
	insertNormalCards();
	insertNormalCards();
}

void DeckCardList::printList()
{
	currentNode = firstNode;
	while (currentNode != NULL) {
		cout << currentNode->toString() << endl;
		currentNode = currentNode->getNextNode();
	}
}

void DeckCardList::moveFirstCardOnList(DeckCardList*& playerDeck, DeckCardList*& cardDeck)
{
	string  colorToMove = cardDeck->getFirstNode()->getUnoCard()->getCardColor();
	string  idToMove = cardDeck->getFirstNode()->getUnoCard()->getCardId();
	Card* cardToMove = new Card(idToMove, colorToMove);

	playerDeck->insertFirstNode(cardToMove);
	cardDeck->deleteFirstNode();
}

Card* DeckCardList::getCardToMove(string idOfCard, string colorOfCard)
{
	Card* cardToMove = new Card();
	string idOfCardToMove;
	string colorOfCardToMove;

	currentNode = firstNode;

	while ((idOfCard != idOfCardToMove) && (colorOfCard != colorOfCardToMove)) {

		idOfCardToMove = currentNode->getUnoCard()->getCardId();
		colorOfCardToMove = currentNode->getUnoCard()->getCardColor();

		if ((idOfCard == idOfCardToMove) && (colorOfCard == colorOfCardToMove)) {
			cardToMove = new Card(idOfCard, colorOfCard);
		}
		currentNode = currentNode->getNextNode();
	}
	return cardToMove;
}

bool DeckCardList::isListEmpty()
{
	bool listEmpty = false;
	if (firstNode == NULL) {
		listEmpty = true;
	}
	return listEmpty;
}