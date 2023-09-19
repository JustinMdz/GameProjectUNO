#include "Librarys.h"
#include "Graphics.h"
#include "Game.h"
int main()
{
    Game* unoGame = new Game();
    unoGame->run();
    delete unoGame;
    return 0;
}