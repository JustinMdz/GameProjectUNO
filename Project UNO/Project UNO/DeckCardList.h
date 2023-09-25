#pragma once
#include "Librarys.h"
#include "Node.h"

class DeckCardList
{
private:

	Node* firstNode;
	Node* currentNode;

public:

	DeckCardList();
	
	void setFirstNode(Node* ptrFirstNode);
	Node* getFirstNode();

	void insertFirstNode(Card* ptrCard);
	void deleteFirstNode();

	void deleteNode(Card*&);

	void insertZeros();
	void insertSpecialCards();
	void insertNormalCards();

	void runList();
	void printList();

	void moveFirstCardOnList(DeckCardList*&, DeckCardList*&);

	Card* getCardToMove(string, string);
	bool isListEmpty();

	~DeckCardList();
};