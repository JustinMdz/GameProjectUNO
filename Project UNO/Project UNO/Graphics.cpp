#include "Graphics.h"

Graphics::Graphics() : backgroundWindow(VideoMode(1080, 720), "UNO_WINDOW") {
    startGame = new Button(450, 320, 200, 100);
    mainMenu = new Menu();
    gameDeckCardList = new DeckCardList();
    gameDiscardCardList = new DeckCardList();
    playerOneDeckCardList = new DeckCardList();
    playerTwoDeckCardList = new DeckCardList();

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
        processMenuEvents(event);
        handleMouseClick(event);
    }
}

void Graphics::render() {
    backgroundWindow.clear();
    backgroundWindow.draw(backgroundSprite);
    renderOptions();
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
    extendBackground();
    while (backgroundWindow.isOpen()) {
        render();
        processEvents();
    }
}

void Graphics::renderMainMenuAndStartButton()
{
    bool isButtonTouched = startGame->getButtonTouched();

    mainMenu->isPosibleToDraw(backgroundWindow);
    if (menuOptionOneSelected) {
        startGame->draw(backgroundWindow);
    }

    if (isButtonTouched == true) {
        drawAllDecksInGame();
    }
}

void Graphics::drawAllDecksInGame()
{
    drawGameDiscardList();
    drawGameDeckCardList();
    drawPlayersDecksList();
}

void Graphics::renderOptions() {
    renderMainMenuAndStartButton();
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

void Graphics::drawGameDeckCardList()
{
    float cardScale = 0.060;
    int posCardX = 15;
    int posCardY = 250;

    cardSprite.setScale(cardScale, cardScale);

    Node* auxCurrentNode = gameDeckCardList->getFirstNode();

    while (auxCurrentNode != NULL) {

        loadBackCardTexture();
        createCardSprite(cardTexture);

        cardSprite.setPosition(posCardX, posCardY);
        backgroundWindow.draw(cardSprite);
        auxCurrentNode = auxCurrentNode->getNextNode();
    }
}

void Graphics::drawGameDiscardList()
{
    float cardScale = 0.060;
    int margen = 15;
    int posCardX = 650; 
    int posCardY = 250; 
    cardSprite.setScale(cardScale, cardScale);

    Node* auxCurrentNode = gameDiscardCardList->getFirstNode();

    string cardColorToInput;
    string cardIdToInput;

    while (auxCurrentNode != NULL) {
        cardColorToInput = auxCurrentNode->getUnoCard()->getCardColor();
        cardIdToInput = auxCurrentNode->getUnoCard()->getCardId();

        loadCardTexture(cardIdToInput, cardColorToInput);
        createCardSprite(cardTexture);
       
        cardSprite.setPosition(posCardX, posCardY);

        backgroundWindow.draw(cardSprite);

        posCardX += margen; 

        auxCurrentNode = auxCurrentNode->getNextNode();
    }
}

void Graphics::drawPlayerDeckList(DeckCardList*& playerDeckList, int deckYPos)
{
    float cardScale = 0.075;
    int margen = 38;
    int posCardX = 5;
    int posCardY = deckYPos;
    cardSprite.setScale(cardScale, cardScale);

    Node* auxCurrentNode = playerDeckList->getFirstNode();

    string cardColorToInput;
    string cardIdToInput;

    while (auxCurrentNode != NULL) {
        cardColorToInput = auxCurrentNode->getUnoCard()->getCardColor();
        cardIdToInput = auxCurrentNode->getUnoCard()->getCardId();

        loadCardTexture(cardIdToInput, cardColorToInput);
        createCardSprite(cardTexture);

        cardSprite.setPosition(posCardX, posCardY);

        backgroundWindow.draw(cardSprite);

        posCardX += margen;

        auxCurrentNode = auxCurrentNode->getNextNode();
    }
}

void Graphics::drawPlayersDecksList()
{
    int yPosDeckPlayerOne = 525;
    int yPosDeckPlayerTwo = 20;

    drawPlayerDeckList(playerOneDeckCardList, yPosDeckPlayerOne);
    drawPlayerDeckList(playerTwoDeckCardList, yPosDeckPlayerTwo);
}

void Graphics::setPlayerOneDeckToShow(DeckCardList*& playerDeckInGame)
{
    this->playerOneDeckCardList = playerDeckInGame;
}

void Graphics::setPlayerTwoDeckToShow(DeckCardList*& playerDeckInGame)
{
    this->playerTwoDeckCardList = playerDeckInGame;
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
        menuOptionOneSelected = true;
        render();
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
            startGame->startUnoGame();
        }
    }
}

Button* Graphics::getStartGameButton() {
    return startGame;
}

RenderWindow& Graphics::getWindow()
{
    return backgroundWindow;
}