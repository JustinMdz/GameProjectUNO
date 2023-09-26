#pragma once
#include "Librarys.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class GraphicCard
{
private: 

	Texture cardTexture;
	Sprite cardSprite;
	int positionInX = 0;
	int positionInY = 0;

public:
	GraphicCard();

	void loadCardTexture(string, string);
	void loadBackCardTexture();
	void createCardSprite();

	void setCardTexture(Texture&);
	void setCardSprite(Sprite&);
	void setPositionInX(int&);
	void setPositionInY(int&);
	Texture getCardTexture();
	Sprite getCardSprite();
	int getPositionInX();
	int getPositionInY();
};