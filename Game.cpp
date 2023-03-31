#pragma comment (lib, "winmm.lib")
#include "Game.h"
#include "control.h"
#include "Windows.h"
using namespace std;
//khoi tao du lieu
void resetData(matrix arr[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            arr[i][j].x = 13 + j * 4;
            arr[i][j].y = 8 + i * 2;
            arr[i][j].z = 7; //chua danh
        }
}
//check ban co con trong o nao hay ko
bool checkFullBoard(matrix arr[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (arr[i][j].z == 7)
                return false;
    return true;
}
//check win/lose/draw
int ProcessFinish(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& a, int& s)
{
    int x = (a.y - 8) / 2;
    int y = (a.x - 13) / 4;
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
void print_Win(matrix arr[BOARD_SIZE][BOARD_SIZE], toado td, int turn) {
    int check = ProcessFinish(arr, td, turn);
    if ((check == 1) && (turn == 1)) {
        GotoXY(140, 25); cout << "##     ##    ##      ## #### ##    ## ";
        GotoXY(140, 26); cout << " ##   ##     ##  ##  ##  ##  ###   ## ";
        GotoXY(140, 27); cout << "  ## ##      ##  ##  ##  ##  ####  ## ";
        GotoXY(140, 28); cout << "   ###       ##  ##  ##  ##  ## ## ## ";
        GotoXY(140, 29); cout << "  ## ##      ##  ##  ##  ##  ##  #### ";
        GotoXY(140, 30); cout << " ##   ##     ##  ##  ##  ##  ##   ### ";
        GotoXY(140, 31); cout << "##     ##     ###  ###  #### ##    ## ";

    }
    else if ((check == 1) && (turn == 0)) {
        GotoXY(140, 25); cout << " #######     ##      ## #### ##    ## ";
        GotoXY(140, 26); cout << "##     ##    ##  ##  ##  ##  ###   ## ";
        GotoXY(140, 27); cout << "##     ##    ##  ##  ##  ##  ####  ## ";
        GotoXY(140, 28); cout << "##     ##    ##  ##  ##  ##  ## ## ## ";
        GotoXY(140, 29); cout << "##     ##    ##  ##  ##  ##  ##  #### ";
        GotoXY(140, 30); cout << "##     ##    ##  ##  ##  ##  ##   ### ";
        GotoXY(140, 31); cout << " #######      ###  ###  #### ##    ## ";
    }
    else if (check == 0) {
        GotoXY(140, 25); cout << "########  ########     ###    ##      ## ";
        GotoXY(140, 26); cout << "##     ## ##     ##   ## ##   ##  ##  ## ";
        GotoXY(140, 27); cout << "##     ## ##     ##  ##   ##  ##  ##  ## ";
        GotoXY(140, 28); cout << "##     ## ########  ##     ## ##  ##  ## ";
        GotoXY(140, 29); cout << "##     ## ##   ##   ######### ##  ##  ## ";
        GotoXY(140, 30); cout << "##     ## ##    ##  ##     ## ##  ##  ## ";
        GotoXY(140, 31); cout << "########  ##     ## ##     ##  ###  ###  ";

    }
}
//Pause khi win/draw
int ConditionPause(matrix arr[BOARD_SIZE][BOARD_SIZE], toado td, int turn) {
    if (ProcessFinish(arr, td, turn) == 1)
        return 1;
    return 0;
}
//Dung in X/O tren man hinh
int print_X_0(matrix arr[BOARD_SIZE][BOARD_SIZE], toado s, int& turn, int& countX, int& countO) {
    GotoXY(s.x, s.y);
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    if ((turn == 1) && (arr[x][y].z == 7) && (arr[x][y].z != 0)) {
        arr[x][y].z = 1;
        setColor(10, 15);
        cout << "X";
        PlaySound(L"Turn", NULL, SND_ASYNC);
        countX += 1;
        return 1;
    }
    else if ((turn == 0) && (arr[x][y].z == 7) && (arr[x][y].z != 1)) {
        arr[x][y].z = 0;
        setColor(12, 15);
        cout << "O";
        PlaySound(L"Turn", NULL, SND_ASYNC);
        countO += 1;
        return 0;
    }
}
//che do PvP
void PvP(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& s) {
    int x = 0, turn = 1, countX = 0, countO = 0;
    while (1)
    {
        ShowNumberTurn(countX, countO, turn);
        int command = CommandControl(s);
        if (command == 0) {
            continue;
        }
        else if (command == 1)
        {
            int x = print_X_0(arr, s, turn, countX, countO);
            if (ConditionPause(arr, s, turn) == 1) {
                print_Win(arr, s, turn);
                ShowNumberTurn(countX, countO, turn);
                HideCursor();
                break;
            }
            if (x == 1)
                turn = 0;
            else if (x == 0)
                turn = 1;
        }
    }
}

//ham goi cho menu PvP
void PlayGame_PvP() {
    matrix arr[BOARD_SIZE][BOARD_SIZE];
    toado s = { 33,22 };
    DrawBoard();
    resetData(arr);
    PvP(arr, s);
}
