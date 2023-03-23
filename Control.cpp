#include"Function_C.h"
#include"view.h"
#include "Control.h"
using namespace std;
toado td = { 33,21 }; //toa do khoi tao con tro tren ban co
//khoi tao du lieu ma tran
void resetData(int matrix[73][41]) {
    for (int i = 0; i < 74; i++)
        for (int j = 0; j < 42; j++)
            matrix[i][j] = -1;
}
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
//Danh X O
bool checkFullBoard(int matrix[73][41]) {
    for (int i = 0; i < 74; i++)
        for (int j = 0; j < 42; j++)
            if (matrix[i][j] == -1)
                return false;
    return true;
}
int CheckThangThua(int A[73][41], int x)
{
    // x thang tra ve 1
    for (int i = 0; i < 5; i++) //check hang ngang 
    {
        if (A[td.x - 16 + 4 * i][td.y] == x && A[td.x - 12 + 4 * i][td.y] == x && A[td.x - 8 + 4 * i][td.y] == x && A[td.x - 4 + 4 * i][td.y] == x && A[td.x + 4 * i][td.y] == x)
            return 1;
    }
    for (int i = 0; i < 5; i++) // check hang doc 
    {
        if (A[td.x][td.y - 8 + 2 * i] == x && A[td.x][td.y - 6 + 2 * i] == x && A[td.x][td.y - 4 + 2 * i] == x && A[td.x][td.y - 2 + 2 * i] == x && A[td.x][td.y + 2 * i] == x)
            return 1;
    }
    for (int i = 0; i < 5; i++) // check duong cheo 
    {
        if ((A[td.x - 16 + 4 * i][td.y - 8 + 2 * i] == x) && (A[td.x - 12 + 4 * i][td.y - 6 + 2 * i] == x) && (A[td.x - 8 + 4 * i][td.y - 4 + 2 * i] == x) && (A[td.x - 4 + 4 * i][td.y - 2 + 2 * i] == x) && (A[td.x + 4 * i][td.y + 2 * i] == x))
            return 1;
    }
    for (int i = 0; i < 5; i++) // check duong cheo DB x thang
    {
        if ((A[td.x + 16 - 4 * i][td.y - 8 + 2 * i] == x) && (A[td.x + 12 - 4 * i][td.y - 6 + 2 * i] == x) && (A[td.x + 8 - 4 * i][td.y - 4 + 2 * i] == x) && (A[td.x + 4 - 4 * i][td.y - 2 + 2 * i] == x) && (A[td.x - 4 * i][td.y + 2 * i] == x))
            return 1;
    }
    if (checkFullBoard(A) == true)
        return 0;
    return -1;
}
void print_Win(int matrix[73][41], int turn) {
    int check = CheckThangThua(matrix, turn);
    if ((check == 1) && (turn == 1)) {
        GotoXY(100, 20);
        cout << "X win";
    }
    else if ((check == 1) && (turn == 0)) {
        GotoXY(100, 20);
        cout << "O win";
    }
    else if (check == 0) {
        GotoXY(100, 20);
        cout << "Draw";
    }
}
void print_X_0(int matrix[73][41], toado s, int& turn, int& countX, int& countO) {
    GotoXY(s.x, s.y);
    if ((turn == 1) && (matrix[s.x][s.y] == -1) && (matrix[s.x][s.y] != 0)) {
        matrix[s.x][s.y] = 1;
        TextColor(14);
        cout << "X";
        print_Win(matrix, turn);
        turn = 0;
        countX += 1;
    }
    else if ((turn == 0) && (matrix[s.x][s.y] == -1) && (matrix[s.x][s.y] != 1)) {
        matrix[s.x][s.y] = 0;
        TextColor(12);
        cout << "O";
        print_Win(matrix, turn);
        turn = 1;
        countO += 1;
    }
}
//Dieu kien + danh 
void CommandControl(int matrix[73][41], int& turn, int& countX, int& countO) {
    GotoXY(td.x, td.y);
    int command = _getch();
    if ((command == 'a' || command == 'A') && td.x > 5)
        moveLeft(td);
    else if ((command == 'd' || command == 'D') && td.x < 71)
        moveRight(td);
    else if ((command == 's' || command == 'S') && td.y < 41)
        moveDown(td);
    else if ((command == 'w' || command == 'W') && td.y > 4)
        moveUp(td);
    else if (command == 32)
        print_X_0(matrix, td, turn, countX, countO);
}

//41 //73
//20 x 18
    


