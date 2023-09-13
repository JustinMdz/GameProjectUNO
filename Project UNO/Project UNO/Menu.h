#pragma once
#include "Librarys.h"
#include <SFML/Graphics.hpp>
using namespace sf;

const int static MENU_OPTIONS = 3;
class Menu
{
private:

	Font fontType;
	Text mainMenuOptions[MENU_OPTIONS];
	int selectedOptionMenuIndex;
	bool inOption = true;

public:

	Menu(float, float);

	int getPressedItem();
	bool getOption();
	void setOnOption();
	void setOffOption();

	void moveOptionUp();
	void moveOptionDown();

	void isPosibleToDraw(RenderWindow& menuBackgroundWindow);
	void drawMenu(RenderWindow&);
	~Menu();
};