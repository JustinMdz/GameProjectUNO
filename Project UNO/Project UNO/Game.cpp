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

    fillPlayerName();

    while (endOfTheGame != true) {

        cout << "Game started";
    }
}

bool Game::isGameFinished(Player*& playerOnTurn)
{
    bool gameFinished = false;

    if (playerOnTurn->getPlayerDeck()->isListEmpty()) {
        gameFinished = true;
    }

    return gameFinished;
}