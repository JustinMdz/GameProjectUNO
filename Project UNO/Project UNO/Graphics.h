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

	DeckCardList* gameDeckCardList;
	DeckCardList* gameDiscardCardList;
	DeckCardList* playerDeckCardList;

	Button* startGame = new Button(100, 200, 300, 400);
	Menu* mainMenu = new Menu(200, 300);
	bool menuOptionOneSelected = false;

public:
	Graphics();

	void processEvents();
	void render();
	void extendBackground();
	void runBackground();

	void loadCardTexture(string, string);
	void loadBackCardTexture();
	void createCardSprite(Texture&);

	void drawPlayerDeckList();
	void drawGameDeckCardList();
	void drawGameDiscardList();

	void setPlayerDeckToShow(DeckCardList*&);
	void setDiscardListToShow(DeckCardList*&);
	void setGameDeckCardListToShow(DeckCardList*&);

	void runMenuOptions();
	void runMenuMoves(Event&);
	void processMenuEvents(Event&);

	void handleMouseClick(Event&);
};