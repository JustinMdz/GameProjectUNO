#include "Librarys.h"
#include "Graphics.h"
#include "DeckCardList.h"
#include "Dealer.h"
int main()
{
    DeckCardList* list= new DeckCardList();
    Dealer cardsDealer(list);

    list->runList();
    list->printList();

    cardsDealer.shufleMaze(list);
    cout << endl << endl << endl;
    list->printList();

    Graphics background;
    background.runBackground();
    return 0;
}