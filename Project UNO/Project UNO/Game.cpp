#include "Game.h"

Game::Game()
{
    playerOne = new Player();
    playerTwo = new Player();
    gameCardDeckList = new DeckCardList();
    gameDiscardDeckList = new DeckCardList();
    gameDealer = new Dealer();
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

void Game::start()
{
    bool endOfTheGame = false;
    int index = 0;

    fillPlayerName();
    firstPlayByDefault();

    while (endOfTheGame != true) {

        playerTurn((getPlayerOnTurn()));
        index++;
    }

    cout << "Fin del juego. Se han jugado " << index << " turnos." << endl;
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

void Game::playerTurn(Player*& playerOnTurn)
{
    /* int defaultCardToGrab = 1;
     if (playerOnTurn->checkIsTrowPossible(gameDiscardDeckList) == true) {
         playerOnTurn->selectCardToTrow();
     }
     else {
         //playerOnTurn->grabCard(defaultCardToGrab,gameCardDeckList);
     }*/
    string nom;
    cout << "\n\nTurno de : " << playerOnTurn->getName();
    cout << "\nturno : " << indexPlayerTurn << ", Digite algo: ";
    cin >> nom;

}

Player*& Game::getPlayerOnTurn()
{
    if (indexPlayerTurn % 2 == 0) {
        indexPlayerTurn++;
        return playerOne;
    }

    if (indexPlayerTurn % 2 != 0) {
        indexPlayerTurn++;
        return playerTwo;
    }
}