#include "Button.h"

Button::Button(float buttonPositionInX, float buttonPositionInY, float buttonWidth, float buttonHeight)
{
	buttonShape.setPosition(Vector2f(buttonPositionInX, buttonPositionInY));
	buttonShape.setSize(Vector2f(buttonWidth, buttonHeight));
	buttonShape.setFillColor(Color::White);

	if (!buttonFont.loadFromFile("Fonts//arial.ttf")) {
		cout << "Font Error" << endl;
	}

	buttonText.setFont(buttonFont);
	buttonText.setString("Start Game");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(Color::Cyan);
	buttonText.setStyle(Text::Bold);
	FloatRect textBounds = buttonText.getLocalBounds();
	buttonText.setPosition(buttonPositionInX + buttonWidth / 2 
		- textBounds.width / 2, buttonPositionInY + buttonHeight / 2 - textBounds.height / 2);
}

void Button::draw(RenderWindow& window)
{
	window.draw(buttonShape);
	window.draw(buttonText);
}


bool Button::contains(Vector2f point)
{
	return buttonShape.getGlobalBounds().contains(point);
}

bool Button::startUnoGame()
{
    this->buttonTouched = true;
	return buttonTouched;
}

bool Button::getButtonTouched()
{
	return buttonTouched;
}
