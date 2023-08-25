#pragma once
#include "Librarys.h"
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

