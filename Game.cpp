#include "Game.h"
#include"Function_C.h"
#include"Control.h"
#include"view.h"
using namespace std;
toado td = { 33,21 };
//khoi tao du lieu
void resetData(matrix arr[18][20]) {
    for (int i = 0; i < 18; i++)
        for (int j = 0; j < 20; j++)
        {
            arr[i][j].x = 5 + i * 4;
            arr[i][j].y = 3 + j * 2;
            arr[i][j].z = -1; //chua danh
        }
}
bool checkFullBoard(matrix arr[18][20]) {
    for (int i = 0; i < 18; i++)
        for (int j = 0; j < 20; j++)
            if (arr[i][j].z == -1)
                return false;
    return true;
}
int CheckThangThua(matrix arr[18][20], toado a, int s)
{
    int x = (a.x - 1) / 4 - 1;
    int y = (a.y - 1) / 2 - 1;
    // x thang tra ve 1
    for (int i = 0; i < 5; i++) //check hang ngang 
    {
        if (arr[x - 4 + i][y].z == s && arr[x - 3 + i][y].z == s && arr[x - 2 + i][y].z == s && arr[x - 1 + i][y].z == s && arr[x + i][y].z == s)
            return 1;
    }
    for (int i = 0; i < 5; i++) // check hang doc 
    {
        if (arr[x][y - 4 + i].z == s && arr[x][y - 3 + i].z == s && arr[x][y - 2 + i].z == s && arr[x][y - 1 + i].z == s && arr[x][y + i].z == s)
            return 1;
    }
    for (int i = 0; i < 5; i++) // check duong cheo DN
    {
        if ((arr[x - 4 + i][y - 4 + i].z == s) && (arr[x - 3 + i][y - 3 + i].z == s) && (arr[x - 2 + i][y - 2 + i].z == s) && (arr[x - 1 + i][y - 1 + i].z == s) && (arr[x + i][y + i].z == s))
            return 1;
    }
    for (int i = 0; i < 5; i++) // check duong cheo DB
    {
        if ((arr[x + 4 - i][y - 4 + i].z == s) && (arr[x + 3 - i][y - 3 + i].z == s) && (arr[x + 2 - i][y - 2 + i].z == s) && (arr[x + 1 - i][y - 1 + i].z == s) && (arr[x - i][y + i].z == s))
            return 1;
    }
    if (checkFullBoard(arr) == true)
        return 0;
    return -1;
}
//in ai win
int print_Win(matrix arr[18][20], toado td, int turn) {
    int check = CheckThangThua(arr, td, turn);
    if ((check == 1) && (turn == 1)) {
        GotoXY(100, 20);
        cout << "X win";
        return 1;
    }
    else if ((check == 1) && (turn == 0)) {
        GotoXY(100, 20);
        cout << "O win";
        return 1;
    }
    else if (check == 0) {
        GotoXY(100, 20);
        cout << "Draw";
        return 1;
    }
    return 0;
}
//Dung khi Win/Draw
int ConditionPause(matrix arr[18][20], int turn) {
    if (print_Win(arr, td, turn) == 1)
        return 1;
    return 0;
}
void print_X_0(matrix arr[18][20], toado s, int& turn, int& countX, int& countO) {
    GotoXY(s.x, s.y);
    int x = (s.x - 1) / 4 - 1;
    int y = (s.y - 1) / 2 - 1;
    if ((turn == 1) && (arr[x][y].z == -1) && (arr[x][y].z != 0)) {
        arr[x][y].z = 1;
        TextColor(14);
        cout << "X";
        countX += 1;
        print_Win(arr, s, turn);
        turn = 0;
    }
    else if ((turn == 0) && (arr[x][y].z == -1) && (arr[x][y].z != 1)) {
        arr[x][y].z = 0;
        TextColor(12);
        cout << "O";
        countO += 1;
        print_Win(arr, s, turn);
        turn = 1;
    }
}
void CommandControl(matrix arr[18][20], int& turn, int& countX, int& countO) {
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
        print_X_0(arr, td, turn, countX, countO);
}
//che do PvP
void PvP(matrix arr[18][20]) {
    int turn = 1, countX = 0, countO = 0;
    do {
        ShowNumberTurn(countX, countO, turn);
        CommandControl(arr, turn, countX, countO);
    } while (ConditionPause(arr, turn) != 1);
}
