#include"Function_C.h"
#include"Control.h"
#include"view.h"
#include"Game.h"
#include"Menu.h"
using namespace std;

void main()
{
    int choice = 0;
    system("color f0");
    FullScreen();
    FixConsoleWindow();
    Menu(choice);
    _getch();
}

