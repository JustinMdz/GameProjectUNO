#pragma once
#include "Librarys.h"
#include "Card.h"

class Node {

private: 
	Card* unoCard;
	Node* nextNode;
public:
	Node(Card*, Node*);
	~Node();
	void setCard(Card* ptrCard);
	void setNextNode(Node* ptrNextNode);
	Card* getCard();
	Node* getNextNode();
	string toString();
};

