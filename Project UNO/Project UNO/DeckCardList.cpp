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