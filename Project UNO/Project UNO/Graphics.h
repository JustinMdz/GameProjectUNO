#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "DeckCardList.h"
using namespace sf;

class Graphics
{
private:

	RenderWindow backgroundWindow;
	Texture backgroundTexture;
	Sprite backgroundSprite;

	Texture cardTexture;
	Sprite cardSprite;

	
public:
	Graphics();

	void processEvents();
	void render();
	void extendBackground();
	void runBackground();

	void loadCardTexture(string, string);
	void loadBackCardTexture();
	void createCardSprite(Texture&);
};