#pragma once
#include <SFML/Graphics.hpp>
#include "Librarys.h"
using namespace sf;

class Graphics
{
private: 
	RenderWindow backgroundWindow;
	Texture backgroundTexture;
	Sprite backgroundSprite;

	void processEvents();
	void render();
	void extendBackground();

public:
	Graphics();
	void runBackground();
};