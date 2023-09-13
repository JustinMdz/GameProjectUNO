#include "Graphics.h"

Graphics::Graphics() : backgroundWindow(VideoMode(1080, 720), "BackWindow") {
    if (!backgroundTexture.loadFromFile("gameBackground.jpg")) {
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);
}

void Graphics::processEvents()
{
    Event event;
    while (backgroundWindow.pollEvent(event)) {
        if (event.type == Event::Closed) {
            backgroundWindow.close();
        }
      
    }
}

void Graphics::render() {
    backgroundWindow.clear();
    backgroundWindow.draw(backgroundSprite);
    backgroundWindow.display();
}

void Graphics::extendBackground()
{
    Vector2u windowSize = backgroundWindow.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );
}

void Graphics::runBackground() {

    while (backgroundWindow.isOpen()) {
        extendBackground();
        render();
        processEvents();
    }
}

void Graphics::loadCardTexture(string cardId, string cardColor)
{
    if (!cardTexture.loadFromFile(cardId + cardColor + ".jpg")) {
        cout << "Load card texture error";
    }
}

void Graphics::loadBackCardTexture()
{
    if (!cardTexture.loadFromFile("Back.jpg")) {
        cout << "Load card texture error";
    }
}

void Graphics::createCardSprite(Texture& textureOfCard)
{
    cardSprite.setTexture(textureOfCard);
}