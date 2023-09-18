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
}

void Game::processGamePrincipalMenuOptions()
{
    gameGraphics->runBackground();
    bool isButtonTouched = gameGraphics->getStartGameButton()->getButtonTouched();
    if (isButtonTouched==true) {
        cout << "cart";
        start();
    }
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
}

void Game::loadGraphicCardLists()
{
    DeckCardList* deckPlayerOne = playerOne->getPlayerDeck();
    DeckCardList* deckPlayerTwo = playerTwo->getPlayerDeck();

    gameGraphics->setDiscardListToShow(gameDiscardDeckList);
    gameGraphics->setGameDeckCardListToShow(gameCardDeckList);
    gameGraphics->setPlayerOneDeckToShow(deckPlayerOne);
    gameGraphics->setPlayerTwoDeckToShow(deckPlayerTwo);
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

void Game::playerTurn(Player*& playerOnTurn)
{
     int defaultCardToGrab = 1;
     if (playerOnTurn->checkIsTrowPossible(gameDiscardDeckList) == true) {
         playerOnTurn->selectCardToTrow(gameDiscardDeckList);
     }
     else {
         playerOnTurn->grabCard(defaultCardToGrab,gameCardDeckList);
     }
    string nom;
    cout << "\n\nTurno de : " << playerOnTurn->getName();
    cout << "\nturno : " << indexPlayerTurn << ", Digite algo: ";
    cin >> nom;

}

void Game::start()
{
    bool endOfTheGame = false;
    int index = 0;

        fillPlayerName();
        firstPlayByDefault();

        while (endOfTheGame != true) {
            loadGraphicCardLists();
            playerTurn((getPlayerOnTurn()));
            index++;
        }
        cout << "Fin del juego. Se han jugado " << index << " turnos." << endl;
}

Game::~Game()
{
    delete playerOne;
    delete playerTwo;
    delete gameCardDeckList;
    delete gameDiscardDeckList;
    delete gameDealer;
    delete gameGraphics;
}