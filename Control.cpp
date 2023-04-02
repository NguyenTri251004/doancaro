#include"Function_C.h"
#include"view.h"
#include "Control.h"
//Ham move
void moveRight(toado& a) {
    GotoXY(a.x + 4, a.y);
    a.x += 4;
}
void moveLeft(toado& a) {
    GotoXY(a.x - 4, a.y);
    a.x -= 4;
}
void moveDown(toado& a) {
    GotoXY(a.x, a.y + 2);
    a.y += 2;
}
void moveUp(toado& a) {
    GotoXY(a.x, a.y - 2);
    a.y -= 2;
}
int CommandControl(toado& s) {
    GotoXY(s.x, s.y);
    int command = _getch();
    if ((command == 'a' || command == 'A') && s.x > 13)
        moveLeft(s);
    else if ((command == 'd' || command == 'D') && s.x < 80)
        moveRight(s);
    else if ((command == 's' || command == 'S') && s.y < 41)
        moveDown(s);
    else if ((command == 'w' || command == 'W') && s.y > 8)
        moveUp(s);
    else if (command == 32)
        return 1;
    return 0;
}
int ControlMenu(toado& menu) {
    GotoXY(menu.x, menu.y);
    int command = _getch();
    if ((command == 's' || command == 'S') && menu.y < 31) {
        GotoXY(menu.x, menu.y + 1);
        menu.y += 2;
        return 1;
    }
    else if ((command == 'w' || command == 'W') && menu.y > 25) {
        GotoXY(menu.x, menu.y - 1);
        menu.y -= 2;
        return 1;
    }
    if (command == 13)
        return 0;
}
int ChooseMode(toado& mode) {
    GotoXY(mode.x, mode.y);
    int command = _getch();
    if ((command == 's' || command == 'S') && mode.y < 29) {
        GotoXY(mode.x, mode.y + 1);
        mode.y += 2;
        return 1;
    }
    else if ((command == 'w' || command == 'W') && mode.y > 25) {
        GotoXY(mode.x, mode.y - 1);
        mode.y -= 2;
        return 1;
    }
    if (command == 13)
        return 0;
}
