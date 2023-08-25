#include "Graphics.h"

Graphics::Graphics() : backgroundWindow(VideoMode(1080, 720), "SFML Image Upload") {
    if (!backgroundTexture.loadFromFile("gameBackground.jpg")) {
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);
}

void Graphics::processEvents()
{
    Event event;
    while (backgroundWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            backgroundWindow.close();
        }
    }
}

void Graphics::extendBackground()
{
    Vector2u windowSize = backgroundWindow.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );
}

void Graphics::render() {
    backgroundWindow.clear();
    backgroundWindow.draw(backgroundSprite);
    backgroundWindow.display();
}

void Graphics::runBackground() {
    while (backgroundWindow.isOpen()) {
        processEvents();
        extendBackground();
        render();
    }
}