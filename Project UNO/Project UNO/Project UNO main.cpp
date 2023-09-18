#include "Librarys.h"
#include "Graphics.h"
#include "Game.h"
int main()
{
    Game* unoMainGame = new Game();
    unoMainGame->processGamePrincipalMenuOptions();
    return 0;
}