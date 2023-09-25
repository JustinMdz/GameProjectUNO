#include "Dealer.h"

Dealer::Dealer() {}

Dealer::Dealer(DeckCardList* deckOfCards)
{
    cardDeckList = deckOfCards;
}

void Dealer::setCardList(DeckCardList* ptrCardList)
{
    cardDeckList = ptrCardList;
}

DeckCardList* Dealer::getCardList()
{
    return cardDeckList;
}

int Dealer::countNodes(DeckCardList* deckOfCards)
{
    Node* indexNode = deckOfCards->getFirstNode();
    int numberCardsDeck = 0;

    while (indexNode != nullptr) {
        indexNode = indexNode->getNextNode();
        numberCardsDeck++;
    }
    return numberCardsDeck;
}

void Dealer::swapCardsOnNodes(Node* indexNode1, Node* indexNode2)
{
    Card* auxiliarCardNode1;
    Card* auxiliarCardNode2;

    auxiliarCardNode1 = indexNode1->getUnoCard();
    auxiliarCardNode2 = indexNode2->getUnoCard();

    indexNode1->setUnoCard(auxiliarCardNode2);
    indexNode2->setUnoCard(auxiliarCardNode1);
}

void Dealer::shuffleCardDeckList(DeckCardList* deckOfCards)
{
    srand(time(nullptr));

    Node* indexNode = deckOfCards->getFirstNode();
    Node* indexNode1 = indexNode;
    Node* indexNode2 = indexNode;

    int randomPosToMove = 0;
    int numberCardsDeck = countNodes(deckOfCards);

    for (int index1 = numberCardsDeck - 1; index1 > 0; --index1) {
        randomPosToMove = rand() % (index1 + 1);
        indexNode1 = indexNode;
        indexNode2 = indexNode;

        for (int index2 = 0; index2 < index1; ++index2) {
            indexNode1 = indexNode1->getNextNode();
        }
        for (int index3 = 0; index3 < randomPosToMove; ++index3) {
            indexNode2 = indexNode2->getNextNode();
        }
        swapCardsOnNodes(indexNode1, indexNode2);
    }
}

Dealer::~Dealer()
{
    delete cardDeckList;
}