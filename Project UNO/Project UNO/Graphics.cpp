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

void Graphics::drawGameDiscardList()
{
    float cardScale = 0.060;
    int margen = 15; // Este es el margen deseado
    int posCardX = 650; // Posición inicial en X de la primera carta
    int posCardY = 250; // Posición en Y constante para todas las cartas
    cardSprite.setScale(cardScale, cardScale);

    Node* auxCurrentNode = gameDiscardCardList->getFirstNode();

    string cardColorToInput;
    string cardIdToInput;

    while (auxCurrentNode != NULL) {
        cardColorToInput = auxCurrentNode->getUnoCard()->getCardColor();
        cardIdToInput = auxCurrentNode->getUnoCard()->getCardId();

        loadCardTexture(cardIdToInput, cardColorToInput);
        createCardSprite(cardTexture);

        // Configura la posición de la carta
        cardSprite.setPosition(posCardX, posCardY);

        backgroundWindow.draw(cardSprite);

        // Incrementa la posición en X para la siguiente carta
        posCardX += margen; // Incremento fijo de margen en X

        auxCurrentNode = auxCurrentNode->getNextNode();
    }
}

void Graphics::drawGameDeckCardList()
{
    float cardScale = 0.060;
    float margen = 1;
    int posCardX = 15;
    int posCardY = 250;
    cardSprite.setScale(cardScale, cardScale);

    Node* auxCurrentNode = gameDeckCardList->getFirstNode();

    while (auxCurrentNode != NULL) {

        loadBackCardTexture();
        createCardSprite(cardTexture);

        cardSprite.setPosition(posCardX, posCardY);
        backgroundWindow.draw(cardSprite);

        posCardY += margen;
        auxCurrentNode = auxCurrentNode->getNextNode();
    }
}

void Graphics::drawPlayerDeckList()
{
    float cardScale = 0.075;
    int margen = 40; // Este es el margen deseado
    int posCardX = 5; // Posición inicial en X de la primera carta
    int posCardY = 525; // Posición en Y constante para todas las cartas
    cardSprite.setScale(cardScale, cardScale);

    Node* auxCurrentNode = playerDeckCardList->getFirstNode();

    string cardColorToInput;
    string cardIdToInput;

    while (auxCurrentNode != NULL) {
        cardColorToInput = auxCurrentNode->getUnoCard()->getCardColor();
        cardIdToInput = auxCurrentNode->getUnoCard()->getCardId();

        loadCardTexture(cardIdToInput, cardColorToInput);
        createCardSprite(cardTexture);

        // Configura la posición de la carta
        cardSprite.setPosition(posCardX, posCardY);

        backgroundWindow.draw(cardSprite);

        // Incrementa la posición en X para la siguiente carta
        posCardX += margen; // Incremento fijo de margen en X

        auxCurrentNode = auxCurrentNode->getNextNode();
    }
}

// drawPlayer2Deck = drawPlayer deck pero camnbiamos la Y nada mas

void Graphics::setPlayerDeckToShow(DeckCardList*& playerDeckInGame)
{
    this->playerDeckCardList = playerDeckInGame;
}

void Graphics::setDiscardListToShow(DeckCardList*& discardCardListInGame)
{
    this->gameDiscardCardList = discardCardListInGame;
}

void Graphics::setGameDeckCardListToShow(DeckCardList*& deckCardsListInGame)
{
    this->gameDeckCardList = deckCardsListInGame;
}

void Graphics::runMenuOptions()
{
    int pressedItem = mainMenu->getPressedItem();

    if (pressedItem == 0) {
        mainMenu->setOffOption();
        menuOptionOneSelected = true; // Opción uno está seleccionada
        render();
    }
    else {
        menuOptionOneSelected = false; // Opción uno ya no está seleccionada
    }

    if (pressedItem == 1) {
        mainMenu->setOffOption();
        render();
        cout << "Options pressed";
    }
    if (pressedItem == 2) {
        backgroundWindow.close();
    }
}

void Graphics::runMenuMoves(Event& menuEvent)
{
    if (menuEvent.key.code == Keyboard::Up) {
        mainMenu->moveOptionUp();
    }
    if (menuEvent.key.code == Keyboard::Down) {
        mainMenu->moveOptionDown();
    }
}

void Graphics::processMenuEvents(Event& menuEvent)
{
    if (menuEvent.type == Event::KeyReleased) {
        runMenuMoves(menuEvent);
    }

    if (menuEvent.key.code == Keyboard::Return) {
        runMenuOptions();
    }
}

void Graphics::handleMouseClick(Event& buttonEvent)
{
    if (buttonEvent.type == Event::MouseButtonPressed &&
        buttonEvent.mouseButton.button == Mouse::Left) {
        Vector2i mousePos = Mouse::getPosition(backgroundWindow);
        Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        if (startGame->contains(mousePosF)) {
            menuOptionOneSelected = false;
        }
    }
}