#include "Librarys.h"
#include "Graphics.h"
#include "DeckCardList.h"
int main()
{
    DeckCardList list;
    list.runList();
    list.printList();

    Graphics background;
    background.runBackground();
    return 0;
}