#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!fontType.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font is here";
	}

	int yPosIndex = 0;
	for (int index = 0; index < MENU_OPTIONS; index++) {
		yPosIndex += 200;
		mainMenuOptions[index].setFont(fontType);
		mainMenuOptions[index].setFillColor(Color::White);
		mainMenuOptions[index].setCharacterSize(70);
		mainMenuOptions[index].setPosition(400, yPosIndex);
	}
	mainMenuOptions[0].setString("Play");
	mainMenuOptions[1].setString("Options");
	mainMenuOptions[2].setString("Exit");

	selectedOptionMenuIndex = -1;
}

int Menu::getPressedItem()
{
	return selectedOptionMenuIndex;
}

bool Menu::getOption()
{
	return inOption;
}

void Menu::isPosibleToDraw(RenderWindow& menuBackgroundWindow)
{
	if (inOption == true) {
		drawMenu(menuBackgroundWindow);
	}
}

void Menu::drawMenu(RenderWindow& menuBackgroundWindow)
{
	for (int index = 0; index < MENU_OPTIONS; index++) {
		menuBackgroundWindow.draw(mainMenuOptions[index]);
	}
}