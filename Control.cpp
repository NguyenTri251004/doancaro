#include"Function_C.h"
#include"view.h"
#include "Control.h"
//Ham move
void moveRight(toado &a) {
    GotoXY(a.x + 4, a.y);
    a.x += 4;
}
void moveLeft(toado &a) {
    GotoXY(a.x-4, a.y);
    a.x -= 4;
}
void moveDown(toado &a) {
    GotoXY(a.x, a.y+2); 
    a.y += 2;
}
void moveUp(toado &a) {
    GotoXY(a.x, a.y-2); 
    a.y -= 2;
}

    


