#include "Node.h"

Node::Node(Card* ptrCard = NULL, Node* ptrNextNode = NULL) {
	unoCard = ptrCard;
	nextNode = ptrNextNode;
}

void Node::setUnoCard(Card* ptrCard)
{
	unoCard = ptrCard;
}

void Node::setNextNode(Node* ptrNextNode)
{
	nextNode = ptrNextNode;
}

Card* Node::getUnoCard()
{
	return unoCard;
}

Node* Node::getNextNode()
{
	return nextNode;
}

string Node::toString()
{
	stringstream ss;
	ss << unoCard->toString();
	return ss.str();
}

Node::~Node()
{
	delete unoCard;
}