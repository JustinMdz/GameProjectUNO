#include "Librarys.h"
#include "Graphics.h"
#include "DeckCardList.h"
#include "Dealer.h"
#include "Player.h"
#include "Game.h"
int main()
{
    Player* playerOne = new Player();
    Graphics* backWindow = new Graphics();

    DeckCardList* mazo = new DeckCardList();
    DeckCardList* discardList = new DeckCardList();

    Dealer* dealer = new Dealer(mazo);

    mazo->runList();
    dealer->shuffleCardDeckList(mazo);

    discardList->moveFirstCardOnList(discardList, mazo);
    discardList->moveFirstCardOnList(discardList, mazo);
    discardList->moveFirstCardOnList(discardList, mazo);
    discardList->moveFirstCardOnList(discardList, mazo);
    discardList->moveFirstCardOnList(discardList, mazo);//

    cout << "Cartas en el mazo: " << endl << endl;
    mazo->printList();

    cout << "\n\nCartas en descarte: " << endl << endl;
    discardList->printList();

    cout << "\n\nCartas jugador: \n\n";
    playerOne->grabCard(7, mazo);
    playerOne->printPlayerDeck();

    backWindow->setDiscardListToShow(discardList);
    backWindow->setGameDeckCardListToShow(mazo);

    DeckCardList* deck = playerOne->getPlayerDeck();

    backWindow->setPlayerDeckToShow(deck);

    backWindow->runBackground();

    return 0;
}