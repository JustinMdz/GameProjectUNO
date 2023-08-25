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
	~DeckCardList();

	void insertFirstNode(Card* ptrCard);
	void deleteFirstNode();
	void insertLastNode(Card* ptrCard);
	void deleteLastNode();

	void insertCeroes();
	void insertSpecialCards();
	void insertNormalCards();

	void runList();

	void printList();
};

