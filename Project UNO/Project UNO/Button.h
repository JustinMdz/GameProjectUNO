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

    Button(float, float, float, float);
    void draw(RenderWindow&);
    bool contains(Vector2f);
    bool startUnoGame();
    bool getButtonTouched();
};