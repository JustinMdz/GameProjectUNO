#include "Game.h"
#include "Graphics.h"

Game::Game()
{
    playerOne = new Player();
    playerTwo = new Player();
    gameCardDeckList = new DeckCardList();
    gameDiscardDeckList = new DeckCardList();
    gameDealer = new Dealer();
    gameGraphics = new Graphics();
    gameRules = new Rule();
}

void Game::fillPlayerName()
{
    string playerName;

    cout << "Enter a name for playerOne: ";
    cin >> playerName;
    playerOne->setName(playerName);

    cout << "\n\nEnter a name for playerTwo: ";
    cin >> playerName;
    playerTwo->setName(playerName);
}

bool Game::isGameFinished(Player*& playerOnTurn)
{
    bool gameFinished = false;

    if (playerOnTurn->getPlayerDeck()->isListEmpty()) {
        gameFinished = true;
    }

    return gameFinished;
}

void Game::firstPlayByDefault()
{
    int initialGameCardsToGrab = 8;
    gameCardDeckList->runList();
    gameDealer->shuffleCardDeckList(gameCardDeckList);
    playerOne->grabCard(initialGameCardsToGrab, gameCardDeckList);
    playerTwo->grabCard(initialGameCardsToGrab, gameCardDeckList);
    gameDiscardDeckList->moveFirstCardOnList(gameDiscardDeckList, gameCardDeckList);
    loadAllGraphicsDecks();
}

Player*& Game::getPlayerOnTurn()
{
    if (indexPlayerTurn % 2 == 0) {
        return playerOne;
    }

    if (indexPlayerTurn % 2 != 0) {
        return playerTwo;
    }
}

void Game::loadAllGraphicsDecks()
{
    gameGraphics->render();
    gameGraphics->processEvents();

    DeckCardList* playerOneGraphicDeck = playerOne->getPlayerDeck();
    DeckCardList* playerTwoGraphicDeck = playerTwo->getPlayerDeck();

    gameGraphics->setDiscardListToShow(gameDiscardDeckList);
    gameGraphics->setGameDeckCardListToShow(gameCardDeckList);
    gameGraphics->setPlayerOneDeckToShow(playerOneGraphicDeck);
    gameGraphics->setPlayerTwoDeckToShow(playerTwoGraphicDeck);
}

bool Game::isButtonStarGamePressed()
{
    if (gameGraphics->getStartGameButton()->getButtonTouched()==true) {
        return true;
    }
    else {
        return false;
    }
}

void Game::playerTurn(Player*& playerOnTurn)
{
    loadAllGraphicsDecks();
    //int defaultCardToGrab = 1;
    //if (playerOnTurn->checkIsTrowPossible(gameDiscardDeckList) == true) {
    //    //playerOnTurn->selectCardToTrow(gameDiscardDeckList);
    //}
    //else {
    //    playerOnTurn->grabCard(defaultCardToGrab, gameCardDeckList);
    //}

    //rules
}

void Game::run() {

    bool endOfTheGame = false;
    gameGraphics->extendBackground();

   // fillPlayerName();
    firstPlayByDefault();

    while (gameGraphics->getWindow().isOpen() && !endOfTheGame) {
       loadAllGraphicsDecks();

        if (isButtonStarGamePressed()) { 
            playerTurn(getPlayerOnTurn());
        }
        indexPlayerTurn++;
    }

    cout << "Fin del juego. Se han jugado " << indexPlayerTurn << " turnos." << endl;
}

Game::~Game()
{
    delete playerOne;
    delete playerTwo;
    delete gameCardDeckList;
    delete gameDiscardDeckList;
    delete gameDealer;
}