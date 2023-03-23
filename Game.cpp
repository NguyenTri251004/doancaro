#include "Game.h"

using namespace std;
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
//check ban co con trong o nao hay ko
bool checkFullBoard(matrix arr[18][20]) {
    for (int i = 0; i < 18; i++)
        for (int j = 0; j < 20; j++)
            if (arr[i][j].z == -1)
                return false;
    return true;
}
//check win/lose/draw
int ProcessFinish(matrix arr[18][20], toado &a, int &s)
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
//in ai win/draw
void print_Win(matrix arr[18][20], toado td, int turn) {
    int check = ProcessFinish(arr, td, turn);
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
//Pause khi win/draw
int ConditionPause(matrix arr[18][20], toado td, int turn) {
    if (ProcessFinish(arr, td, turn) == 1)
        return 1;
    return 0;
}
//Dung in X/O tren man hinh
int print_X_0(matrix arr[18][20], toado s, int& turn, int& countX, int& countO) {
    GotoXY(s.x, s.y);
    int x = (s.x - 1) / 4 - 1;
    int y = (s.y - 1) / 2 - 1;
    if ((turn == 1) && (arr[x][y].z == -1) && (arr[x][y].z != 0)) {
        arr[x][y].z = 1;
        TextColor(14);
        cout << "X";
        countX += 1;
        return 1;
    }
    else if ((turn == 0) && (arr[x][y].z == -1) && (arr[x][y].z != 1)) {
        arr[x][y].z = 0;
        TextColor(12);
        cout << "O";
        countO += 1;
        return 0;
    }
}
int CommandControl(toado& s, int& turn, int& countX, int& countO) {
    GotoXY(s.x, s.y);
    int command = _getch();
    if ((command == 'a' || command == 'A') && s.x > 5)
        moveLeft(s);
    else if ((command == 'd' || command == 'D') && s.x < 71)
        moveRight(s);
    else if ((command == 's' || command == 'S') && s.y < 41)
        moveDown(s);
    else if ((command == 'w' || command == 'W') && s.y > 4)
        moveUp(s);
    else if (command == 32)
        return 1;
    return 0;
}
//che do PvP
void PvP(matrix arr[18][20],toado s) {
    int x = 0, turn = 1, countX = 0, countO = 0;
    while (1)
    {
        ShowNumberTurn(countX, countO, turn);
        int command = CommandControl(s, turn, countX, countO);
        if (command == 0)
            continue;
        else if (command == 1)
        {
            int x = print_X_0(arr, s, turn, countX, countO);
            if (ConditionPause(arr, s, turn) == 1) {
                print_Win(arr, s, turn);
                ShowNumberTurn(countX, countO, turn); //goi lai de update so luot
                break;
            }
            if (x == 1)
                turn = 0;
            else if (x == 0)
                turn = 1;
        }
    }
}