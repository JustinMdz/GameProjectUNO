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
	void setUnoCard(Card* ptrCard);
	void setNextNode(Node* ptrNextNode);
	Card* getUnoCard();
	Node* getNextNode();
	string toString();
};