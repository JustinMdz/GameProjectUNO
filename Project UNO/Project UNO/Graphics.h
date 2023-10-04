#pragma once
#include "Menu.h"
#include "Button.h"
#include "DeckCardList.h"
#include "GraphicCard.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Graphics
{
private:

	RenderWindow backgroundWindow;
	Texture backgroundTexture;
	Sprite backgroundSprite;

	Texture cardTexture;
	Sprite cardSprite;

	GraphicCard** graphicCard;

	DeckCardList* gameDeckCardList;
	DeckCardList* gameDiscardCardList;
	DeckCardList* playerOneDeckCardList;
	DeckCardList* playerTwoDeckCardList;

	Button* startGame;
	Button* skipTurn;
	Menu* mainMenu;
	bool menuOptionOneSelected = false;

public:
	Graphics();

	void processEvents();
	void render();
	void extendBackground();
	void runBackground();

	void renderOptions();
	void renderMainMenuAndStartButton();//Puede que no pertenezca a esta clase
	void drawAllDecksInGame();

	void loadCardTexture(string, string);
	void loadBackCardTexture();
	void createCardSprite(Texture&);

	void drawPlayerDeckList(DeckCardList*&, int);
	void drawPlayersDecksList();

	void drawGameDeckCardList();
	void drawGameDiscardList();

	void setPlayerOneDeckToShow(DeckCardList*&);
	void setPlayerTwoDeckToShow(DeckCardList*&);

	void setDiscardListToShow(DeckCardList*&);//Puede que no pertenezca a esta clase
	void setGameDeckCardListToShow(DeckCardList*&);//Puede que no pertenezca a esta clase

	void runMenuOptions();
	void runMenuMoves(Event&);
	void processMenuEvents(Event&);
	void handleMouseClick(Event&);

	Button* getStartGameButton();
	RenderWindow& getWindow();
};