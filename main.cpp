#include"Function_C.h"
#include"Control.h"
#include"view.h"
using namespace std;

void main()
{
    int matrix[73][41]; //-1 chua danh , 1 la cua X, 0 la cua O
    DrawBoard();
    resetData(matrix);
    GotoXY(33, 21);
    int turn = 1, countX = 0, countO = 0;
    do {
        ShowNumberTurn(countX, countO, turn);
        CommandControl(matrix, turn, countX, countO);
        int check = CheckThangThua(matrix);
        if (check == 1) {
            GotoXY(100, 20);
            cout << "X win";
        }
        else if (check == -1) {
            GotoXY(100, 20);
            cout << "O win";
        }
            
    } while (1);
}
   

