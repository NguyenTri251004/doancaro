#include"Function_C.h"
#include"Control.h"
#include"view.h"
#include"Game.h"
using namespace std;

void main()
{
    toado s = {33,21};
    matrix arr[18][20];
    DrawBoard(); //so o ban co 18x20 
    resetData(arr);
    GotoXY(33, 21);
    PvP(arr,s);
}
