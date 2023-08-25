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

void DeckCardList::insertLastNode(Card* ptrCard)
{
	if (firstNode == NULL) {
		firstNode = new Node(ptrCard, firstNode);
	}
	else {
		currentNode = firstNode;
		while (currentNode->getNextNode() != NULL) {
			currentNode = currentNode->getNextNode();
		}
		currentNode->setNextNode(new Node(ptrCard, NULL));
	}
}

void DeckCardList::deleteLastNode()
{
	currentNode = firstNode;
	Node* lastNode = currentNode;
	if (firstNode != NULL) {
		if (firstNode->getNextNode() == NULL) {
			delete firstNode;
			firstNode = NULL;
		}
		else {
			while (currentNode->getNextNode() != NULL) {
				lastNode = currentNode;
				currentNode = currentNode->getNextNode();
			}
			lastNode->setNextNode(NULL);
			delete  currentNode;
		}
	}
}

void DeckCardList::insertCeroes()
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
			normalCard = new Card(colorIndex, valueIdIndex);
			insertFirstNode(normalCard);
		}
	}
}

void DeckCardList::runList()
{
	insertCeroes();
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