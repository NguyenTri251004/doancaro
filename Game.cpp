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
int ProcessFinish(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& a, int s)
{
    int x = (a.y - 8) / 2;
    int y = (a.x - 13) / 4;
    // x thang tra ve 1
    for (int i = 0; i < 5; i++) //check hang ngang 
    {
        if (arr[x - 4 + i][y].z == s && arr[x - 3 + i][y].z == s && arr[x - 2 + i][y].z == s && arr[x - 1 + i][y].z == s && arr[x + i][y].z == s) {
            return 1;
        }
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
int PvP_print_X_0(matrix arr[BOARD_SIZE][BOARD_SIZE], toado s, int& turn, int& countX, int& countO) {
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
            int x = PvP_print_X_0(arr, s, turn, countX, countO);
            if (ConditionPause(arr, s, turn) == 1) {
                print_Win(arr, s, turn);
                PlaySound(L"Win", NULL, SND_ASYNC);
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
int CheckDuong4X(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& s, int XO) {
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    for (int i = 0; i < 4; i++)
        if (arr[x - 3 + i][y].z == XO && arr[x - 2 + i][y].z == XO && arr[x - 1 + i][y].z == XO && arr[x + i][y].z == XO) {
            return 1;
        }
    for (int i = 0; i < 4; i++)
        if (arr[x][y - 3 + i].z == XO && arr[x][y - 2 + i].z == XO && arr[x][y - 1 + i].z == XO && arr[x][y + i].z == XO) {
            return 2;
        }
    for (int i = 0; i < 4; i++)
        if ((arr[x - 3 + i][y - 3 + i].z == XO) && (arr[x - 2 + i][y - 2 + i].z == XO) && (arr[x - 1 + i][y - 1 + i].z == XO) && (arr[x + i][y + i].z == XO)) {
            return 3;
        }
    for (int i = 0; i < 4; i++)
        if ((arr[x + 3 - i][y - 3 + i].z == XO) && (arr[x + 2 - i][y - 2 + i].z == XO) && (arr[x + 1 - i][y - 1 + i].z == XO) && (arr[x - i][y + i].z == XO)) {
            return 4;
        }
    return 0;
}
int CheckDuong3X(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& s,int XO) {
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    for (int i = 0; i < 3; i++)
        if (arr[x - 2 + i][y].z == XO && arr[x - 1 + i][y].z == XO && arr[x + i][y].z == XO) {
            return 1;
        }
    for (int i = 0; i < 3; i++)
        if (arr[x][y - 2 + i].z == XO && arr[x][y - 1 + i].z == XO && arr[x][y + i].z == XO) {
            return 2;
        }
    for (int i = 0; i < 3; i++)
        if ((arr[x - 2 + i][y - 2 + i].z == XO) && (arr[x - 1 + i][y - 1 + i].z == XO) && (arr[x + i][y + i].z == XO)) {
            return 3;
        }
    for (int i = 0; i < 3; i++)
        if ((arr[x + 2 - i][y - 2 + i].z == XO) && (arr[x + 1 - i][y - 1 + i].z == XO) && (arr[x - i][y + i].z == XO)) {
            return 4;
        }
    return 0;
}
int CheckDuong2X(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& s) {
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    for (int i = 0; i < 2; i++)
        if (arr[x - 1 + i][y].z == 1 && arr[x + i][y].z == 1) {
            return 1;
        }
    for (int i = 0; i < 2; i++)
        if (arr[x][y - 1 + i].z == 1 && arr[x][y + i].z == 1) {
            return 2;
        }
    for (int i = 0; i < 2; i++)
        if ((arr[x - 1 + i][y - 1 + i].z == 1) && (arr[x + i][y + i].z == 1)) {
            return 3;
        }
    for (int i = 0; i < 2; i++)
        if ((arr[x + 1 - i][y - 1 + i].z == 1) && (arr[x - i][y + i].z == 1)) {
            return 4;
        }
    return 0;
}
int CaseCheck(toado& s, matrix arr[BOARD_SIZE][BOARD_SIZE], int m, int Case,int XO) { 
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    if (Case == 1) {
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x - i][y].z == 0)
                    break;
            if (XO == 0)
                if (arr[x - i][y].z == 1)
                    break;
            if (arr[x - i][y].z == 7) {
                arr[x - i][y].z = 1;
                GotoXY(4 * y + 13, 2 * (x - i) + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x + i][y].z == 0)
                    break;
            if (XO == 0)
                if (arr[x + i][y].z == 1)
                    break;
            if (arr[x + i][y].z == 7) {
                arr[x + i][y].z = 1;
                GotoXY(4 * y + 13, 2 * (x + i) + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
    }
    else if (Case == 2) {
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x][y - i].z == 0)
                    break;
            if (XO == 0)
                if (arr[x][y - i].z == 1)
                    break;
            if (arr[x][y - i].z == 7) {
                arr[x][y - i].z = 1;
                GotoXY(4 * (y - i) + 13, 2 * x + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x][y + i].z == 0)
                    break;
            if (XO == 0)
                if (arr[x][y + i].z == 1)
                    break;
            if (arr[x][y + i].z == 7) {
                arr[x][y + i].z = 1;
                GotoXY(4 * (y + i) + 13, 2 * x + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
    }
    else if (Case == 3) {
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x - i][y - i].z == 0)
                    break;
            if (XO == 0)
                if (arr[x - i][y - i].z == 1)
                    break;
            if (arr[x - i][y - i].z == 7) {
                arr[x - i][y - i].z = 1;
                GotoXY(4 * (y - i) + 13, 2 * (x - i) + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x + i][y + i].z == 0)
                    break;
            if (XO == 0)
                if (arr[x + i][y + i].z == 1)
                    break;
            if (arr[x + i][y + i].z == 7) {
                arr[x + i][y + i].z = 1;
                GotoXY(4 * (y + i) + 13, 2 * (x + i) + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
    }
    else if (Case == 4) {
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x + i][y - i].z == 0)
                    break;
            if (XO == 0)
                if (arr[x + i][y - i].z == 1)
                    break;
            if (arr[x + i][y - i].z == 7) {
                arr[x + i][y - i].z = 1;
                GotoXY(4 * (y - i) + 13, 2 * (x + i) + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
        for (int i = 0; i <= m; i++) {
            if (XO == 1)
                if (arr[x - i][y + i].z == 0)
                    break;
            if (XO == 0)
                if (arr[x - i][y + i].z == 1)
                    break;
            if (arr[x - i][y + i].z == 7) {
                arr[x - i][y + i].z = 1;
                GotoXY(4 * (y + i) + 13, 2 * (x - i) + 8);
                setColor(10, 15);
                cout << "X";
                return 1;
            }
        }
    }
    return -1;  
}
toado ViTriTotNhat(matrix arr[BOARD_SIZE][BOARD_SIZE], int XO) {
    toado s;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            if (arr[i][j].z == XO) {
                s = { arr[i][j].x,arr[i][j].y };
                int Case4x = CheckDuong4X(arr, s, XO);
                int Case3x = CheckDuong3X(arr, s, XO);
                if (XO == 0) {
                    int x = (s.y - 8) / 2;
                    int y = (s.x - 13) / 4;
                    for (int i = 0; i < 4; i++)
                        if (arr[x - 3 + i][y].z == XO && arr[x - 2 + i][y].z == XO && arr[x - 1 + i][y].z == XO && arr[x + i][y].z == XO) {
                            if (arr[x - 4 + i][y].z == 1 && arr[x + 2 * i][y].z == 1)
                                continue;
                        }
                    for (int i = 0; i < 4; i++)
                        if (arr[x][y - 3 + i].z == XO && arr[x][y - 2 + i].z == XO && arr[x][y - 1 + i].z == XO && arr[x][y + i].z == XO) {
                            if (arr[x][y - 4 + i].z == 1 && arr[x][y + 2 * i].z == 1)
                                continue;
                        }
                    for (int i = 0; i < 4; i++)
                        if ((arr[x - 3 + i][y - 3 + i].z == XO) && (arr[x - 2 + i][y - 2 + i].z == XO) && (arr[x - 1 + i][y - 1 + i].z == XO) && (arr[x + i][y + i].z == XO)) {
                            if (arr[x - 4 + i][y - 4 + i].z == 1 && arr[x + 2 * i][y + 2 * i].z == 1)
                                continue;
                        }
                    for (int i = 0; i < 4; i++)
                        if ((arr[x + 3 - i][y - 3 + i].z == XO) && (arr[x + 2 - i][y - 2 + i].z == XO) && (arr[x + 1 - i][y - 1 + i].z == XO) && (arr[x - i][y + i].z == XO)) {
                            if (arr[x + 4 - i][y - 4 + i].z == 1 && arr[x - 2 * i][y + 2 * i].z == 1)
                                continue;
                        }
                }
                if (Case4x != 0)
                    return s;
                else if (Case3x != 0)
                    return s;
                else if (XO == 1) {
                    int Case2x = CheckDuong2X(arr, s);
                    if (Case2x != 0)
                        return s;
                }
            }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            if (arr[i][j].z == XO) {
                s = { arr[i][j].x,arr[i][j].y };
                return s;
            }
    }
}
int AI(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& s) {
    //Check doi thu quan O 
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    toado temp = ViTriTotNhat(arr, 0);
    int Case4x = CheckDuong4X(arr, temp, 0);
    if (Case4x != 0) {
        int th1 = CaseCheck(temp, arr, 4, Case4x,0);
        if (th1 == 1)
            return 1;
    }
    Case4x = 0;
    Case4x = CheckDuong4X(arr, s, 1);
    if (Case4x != 0) {
        int th1 = CaseCheck(s, arr, 4, Case4x, 1);
        if (th1 == 1)
            return 1;
    }
    int Case3x = CheckDuong3X(arr, temp, 0);
    if (Case3x != 0) {
        int th2 = CaseCheck(temp, arr, 3, Case3x,0);
        if (th2 == 1)
            return 1;
    }
    Case3x = CheckDuong3X(arr, temp, 1);
    int Case2x = CheckDuong2X(arr, s);
    if (Case3x != 0) {
        int th2 = CaseCheck(s, arr, 3, Case3x,1);
        if (th2 == 1)
            return 1;
    }
    else if (Case2x != 0) {
        int th3 = CaseCheck(s, arr, 2, Case2x,1);
        if (th3 == 1)
            return 1;
    }
    // 1 X 
    if (arr[x + 1][y].z == 7) {
        arr[x + 1][y].z = 1;
        GotoXY(4 * y + 13, 2 * (x + 1) + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x - 1][y].z == 7) {
        arr[x - 1][y].z = 1;
        GotoXY(4 * y + 13, 2 * (x - 1) + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x + 1][y + 1].z == 7) {
        arr[x + 1][y + 1].z = 1;
        GotoXY(4 * (y + 1) + 13, 2 * (x + 1) + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x - 1][y - 1].z == 7) {
        arr[x - 1][y - 1].z = 1;
        GotoXY(4 * (y - 1) + 13, 2 * (x - 1) + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x - 1][y + 1].z == 7) {
        arr[x - 1][y + 1].z = 1;
        GotoXY(4 * (y + 1) + 13, 2 * (x - 1) + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x + 1][y - 1].z == 7) {
        arr[x + 1][y - 1].z = 1;
        GotoXY(4 * (y - 1) + 13, 2 * (x + 1) + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x][y - 1].z == 7) {
        arr[x][y - 1].z = 1;
        GotoXY(4 * (y - 1) + 13, 2 * x + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    else if (arr[x][y + 1].z == 7) {
        arr[x][y + 1].z = 1;
        GotoXY(4 * (y + 1) + 13, 2 * x + 8);
        setColor(10, 15);
        cout << "X";
        return 1;
    }
    return -1;
}
int PvE_print_X_0(matrix arr[BOARD_SIZE][BOARD_SIZE], toado s, int& turn, int& countO){
    GotoXY(s.x, s.y);
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    if ((turn == 0) && (arr[x][y].z == 7) && (arr[x][y].z != 1)) {
        arr[x][y].z = 0;
        setColor(12, 15);
        cout << "O";
        PlaySound(L"Turn", NULL, SND_ASYNC);
        countO += 1;
        return 0;
    }
}
void PvE(matrix arr[BOARD_SIZE][BOARD_SIZE], toado& s) {
    int d = 0, turn = 0, countX = 1, countO = 0;
    GotoXY(s.x, s.y);
    setColor(10, 15);
    cout << "X";
    int x = (s.y - 8) / 2;
    int y = (s.x - 13) / 4;
    arr[x][y].z = 1;
    while (1)
    {
        ShowNumberTurn(countX, countO, turn);
        if (turn == 0) {
            int command = CommandControl(s);
            if (command == 0) {
                continue;
            }
            else if (command == 1)
            {
                d = PvE_print_X_0(arr, s, turn, countO);
                if (ConditionPause(arr, s, 0) == 1) {
                    print_Win(arr, s, turn);
                    PlaySound(L"Win", NULL, SND_ASYNC);
                    ShowNumberTurn(countX, countO, turn);
                    HideCursor();
                    break;
                }
            }
            if (d == 0)
                turn = 1;
            continue;
        }
        else if (turn == 1) {
            int kq = 0;
            toado temp = ViTriTotNhat(arr,1);
            int x = AI(arr, temp);
            if (x == 1) {
                countX += 1;
                kq = ProcessFinish(arr, temp, 1);
                if (kq == 1)
                {
                    print_Win(arr, temp, turn);
                    PlaySound(L"Win", NULL, SND_ASYNC);
                    ShowNumberTurn(countX, countO, turn);
                    HideCursor();
                    break;
                }
            }
            turn = 0;
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
void PlayGame_PvE() {
    matrix arr[BOARD_SIZE][BOARD_SIZE];
    toado s = { 33,22 };
    DrawBoard();
    resetData(arr);
    PvE(arr, s);
}
//ham load va save game
void LoadGame(string s)
{
    matrix arr[BOARD_SIZE][BOARD_SIZE];
    resetData(arr);
    bool load = true;
    ifstream f1(s);
    ifstream f;
    if (!f1)
    {
        GotoXY(100, 100);
        cout << "File ban nhap khong ton tai";
        load = false;
        _getch();
    }
    else {
        f.open(s, ios::in);
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                f >> arr[i][j].z;
            }
        }
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                switch (arr[i][j].z)
                {
                case 1:
                    GotoXY(13 + j * 4, 8 + i * 2);
                    cout << "X";
                    break;
                case 0:
                    GotoXY(13 + j * 4, 8 + i * 2);
                    cout << "O";
                    break;
                case 7: cout << " ";
                    break;
                }
            }
        }
    }
}
void SaveGame(matrix arr[BOARD_SIZE][BOARD_SIZE])
{
    ofstream f;
    string s;
    GotoXY(100, 100);
    cout << "Ten file de luu: ";
    getline(cin, s);
    f.open(s, ios::out);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            GotoXY(13 + j * 4, 8 + i * 2);
            f << arr[i][j].z;
        }
        cout << endl;
    }
    f.close();
    GotoXY(100, 100);
    cout << "Luu thanh cong! ";
    _getch();
}
