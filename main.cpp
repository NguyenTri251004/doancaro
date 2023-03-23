#include"Function_C.h"
#include"Control.h"
#include"view.h"
#include"Game.h"
using namespace std;

void main()
{
    matrix arr[18][20];
    DrawBoard(); //18x20 o
    resetData(arr);
    GotoXY(33, 21);
    PvP(arr);
}
