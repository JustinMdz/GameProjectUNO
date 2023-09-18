#include "Button.h"

Button::Button(float xPos, float yPos, float width, float height)
{
	buttonShape.setPosition(Vector2f(xPos, yPos));
	buttonShape.setSize(Vector2f(width, height));
	buttonShape.setFillColor(Color::Black);

	if (!buttonFont.loadFromFile("Fonts//arial.ttf")) {
		cout << "No se pudo cargar la fuente" << endl;
	}

	buttonText.setFont(buttonFont);
	buttonText.setString("Start Game");
	buttonText.setCharacterSize(10);
	buttonText.setFillColor(Color::Red);
	buttonText.setStyle(Text::Bold);
	FloatRect textBounds = buttonText.getLocalBounds();
	buttonText.setPosition(xPos + width / 2 - textBounds.width / 2, yPos + height / 2 - textBounds.height / 2);
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
