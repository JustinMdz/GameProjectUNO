#include "Menu.h"

Menu::Menu()
{
	if (!fontType.loadFromFile("Fonts/arial.ttf")) {
		cout << "No font is here";
	}

	int indexPositionInY = 0;
	for (int index = 0; index < MENU_OPTIONS; index++) {
		indexPositionInY += 200;
		mainMenuOptions[index].setFont(fontType);
		mainMenuOptions[index].setFillColor(Color::White);
		mainMenuOptions[index].setCharacterSize(70);
		mainMenuOptions[index].setPosition(400, indexPositionInY);
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

void Menu::setOnOption()
{
	inOption = true;
}

void Menu::setOffOption()
{
	inOption = false;
}

void Menu::moveOptionUp()
{
	if (selectedOptionMenuIndex - 1 >= 0) {
		mainMenuOptions[selectedOptionMenuIndex].setFillColor(Color::White);
		selectedOptionMenuIndex--;

		if (selectedOptionMenuIndex == -1) {
			selectedOptionMenuIndex = 2;
		}
		mainMenuOptions[selectedOptionMenuIndex].setFillColor(Color::Blue);
	}
}

void Menu::moveOptionDown()
{
	if (selectedOptionMenuIndex + 1 <= MENU_OPTIONS) {
		mainMenuOptions[selectedOptionMenuIndex].setFillColor(Color::White);
		selectedOptionMenuIndex++;

		if (selectedOptionMenuIndex == MENU_OPTIONS) {
			selectedOptionMenuIndex = 0;
		}
		mainMenuOptions[selectedOptionMenuIndex].setFillColor(Color::Blue);
	}
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

Menu::~Menu()
{}
