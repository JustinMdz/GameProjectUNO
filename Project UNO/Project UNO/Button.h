#pragma once
#include <SFML/Graphics.hpp>
#include "Librarys.h"
#include "Game.h"
using namespace sf;

class Button
{
private:
    RectangleShape buttonShape;
    Text buttonText;
    Font buttonFont;
    bool buttonTouched = false;


public:

    Button(float x, float y, float width, float height);
    void draw(RenderWindow& window);
    bool contains(Vector2f point);
    bool startUnoGame();
    bool getButtonTouched();
};