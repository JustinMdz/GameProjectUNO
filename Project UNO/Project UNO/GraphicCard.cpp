#include "GraphicCard.h"

GraphicCard::GraphicCard(){}

void GraphicCard::loadCardTexture(string cardId, string cardColor)
{
    if (!cardTexture.loadFromFile(cardId + cardColor + ".jpg")) {
        cout << "Load card texture error";
    }
}

void GraphicCard::loadBackCardTexture()
{
    if (!cardTexture.loadFromFile("Back.jpg")) {
        cout << "Load card texture error";
    }
}

void GraphicCard::createCardSprite()
{
    cardSprite.setTexture(cardTexture);
}

void GraphicCard::setCardTexture(Texture& newCardTexture)
{
    this->cardTexture = newCardTexture;
}

void GraphicCard::setCardSprite(Sprite& newCardSprite)
{
    this->cardSprite = newCardSprite;
}

void GraphicCard::setPositionInX(int& newPositionInX) 
{
    this->positionInX = newPositionInX;
}

void GraphicCard::setPositionInY(int& newPositionInY)
{
    this->positionInY = newPositionInY;
}

Texture GraphicCard::getCardTexture()
{
    return cardTexture;;
}

Sprite GraphicCard::getCardSprite()
{
    return cardSprite;
}

int GraphicCard::getPositionInX()
{
    return positionInX;
}

int GraphicCard::getPositionInY()
{
    return positionInY;
}