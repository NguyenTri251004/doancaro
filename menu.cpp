#include "menu.h"
#include"control.h"
#include "view.h"
#include "Function_C.h"
#include"Game.h"
using namespace std;
void Help(int& choice)
{
    Khung();
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 11); printf(" ");
    }
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 21); printf(" ");
    }
    GotoXY(94, 25);  setColor(3, 15); printf("--------HELP--------");
    GotoXY(99, 28); setColor(10, 15); printf("DIEU KHIEN");
    setColor(4, 15);
    GotoXY(86, 30);  printf("Huong dan :");    GotoXY(110, 30);  printf("Thong tin them:"); setColor(1, 15);
    GotoXY(86, 32); printf("A: Sang Trai");     GotoXY(110, 32); printf("1. Ban co 18x18");
    GotoXY(86, 33); printf("D: Sang Phai");     GotoXY(110, 33); printf("2. Luat choi:");
    GotoXY(86, 34); printf("S: Len Tren");      GotoXY(110, 34); printf("- Danh du 5 quan co lien tiep de thang");
    GotoXY(86, 35); printf("W: Xuong Duoi");    GotoXY(110, 35); printf("Luat tu do(khong ap dung luat chan hai dau)");
    GotoXY(86, 36); printf("SPACE: Danh Co");
    GotoXY(93, 40); setColor(47, 15); printf("  Press Enter to EXIT  ");
    //GotoXY(41, 40);
    setColor(0, 15);
    char a;
    do
    {
        a = _getch();
    } while (a != 13);
    system("cls");
    fflush(stdin);
    Menu(choice);
}
void About(int& choice)
{
    Khung();
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 11); printf(" ");
    }
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 21); printf(" ");
    }
    GotoXY(94, 24);  setColor(3, 15);  printf("--------ABOUT--------");
    GotoXY(91, 26); setColor(12, 15); printf("DO AN CUOI KI I - GAME CO CARO");
    GotoXY(86, 28); setColor(12, 15); printf("GV HUONG DAN:    Thay Truong Toan Thinh");
    GotoXY(95, 30); setColor(12, 15); printf("----- NHOM 12 -----");      GotoXY(34, 17);

    GotoXY(87, 32); setColor(1, 15); printf("- Ho va ten -");          GotoXY(115, 32); setColor(1, 15); printf("- MSSV -");
    GotoXY(87, 33); setColor(11, 15); printf("Pham Van Minh");          GotoXY(115, 33); setColor(11, 15); printf("22127272");
    GotoXY(87, 34); setColor(11, 15); printf("Truong Nhat Huy");        GotoXY(115, 34); setColor(11, 15); printf("22127168");
    GotoXY(87, 35); setColor(11, 15); printf("Nguyen The Quan");        GotoXY(115, 35); setColor(11, 15); printf("22127341");
    GotoXY(87, 36); setColor(11, 15); printf("Nguyen Phuoc Minh Tri");  GotoXY(115, 36); setColor(11, 15); printf("22127424");

    GotoXY(93, 40); setColor(47, 15); printf("  Press Enter to EXIT  ");
    //GotoXY(50, 40); //chua hieu dong nay
    setColor(0, 15);
    char a;
    do
    {
        a = _getch();
    } while (a != 13);
    system("cls");
    fflush(stdin);
    Menu(choice);
}
void Exit()
{
    GotoXY(65, 19); printf("######## ##     ##    ###    ##    ## ##    ##    ##    ##  #######  ##     ## ");
    GotoXY(65, 20); printf("   ##    ##     ##   ## ##   ###   ## ##   ##      ##  ##  ##     ## ##     ## ");
    GotoXY(65, 21); printf("   ##    ##     ##  ##   ##  ####  ## ##  ##        ####   ##     ## ##     ## ");
    GotoXY(65, 22); printf("   ##    ######### ##     ## ## ## ## #####          ##    ##     ## ##     ## ");
    GotoXY(65, 23); printf("   ##    ##     ## ######### ##  #### ##  ##         ##    ##     ## ##     ## ");
    GotoXY(65, 24); printf("   ##    ##     ## ##     ## ##   ### ##   ##        ##    ##     ## ##     ## ");
    GotoXY(65, 25); printf("   ##    ##     ## ##     ## ##    ## ##    ##       ##     #######   #######  ");
}
void HienThiLuaChonMenu(toado s) {
    char a[10] = "PLAY GAME";
    char b[10] = "LOAD GAME";
    char c[10] = "HELP";
    char d[10] = "ABOUT";
    char e[10] = "EXIT";
    setColor(4, 15);
    GotoXY(101, 25);
    cout << a;
    GotoXY(101, 27);
    cout << b;
    GotoXY(103, 29);
    cout << c;
    GotoXY(103, 31);
    cout << d;
    GotoXY(103, 33);
    cout << e;
    if (s.y == 25) {
        setColor(1, 15);
        GotoXY(101, 25);
        cout << a;
        setColor(4, 15);
    }
    else if (s.y == 27) {
        setColor(1, 15);
        GotoXY(101, 27);
        cout << b;
        setColor(4, 15);
    }
    else if (s.y == 29) {
        setColor(1, 15);
        GotoXY(103, 29);
        cout << c;
        setColor(4, 15);
    }
    else if (s.y == 31) {
        setColor(1, 15);
        GotoXY(103, 31);
        cout << d;
        setColor(4, 15);
    }
    else if (s.y == 33) {
        setColor(1, 15);
        GotoXY(103, 33);
        cout << e;
        setColor(4, 15);
    }
}
void HienThiMode(toado mode) {
    char pvp[10] = "PvP";
    char pve[10] = "PvE";
    char exit[10] = "EXIT";
    setColor(4, 15);
    GotoXY(104, 25);
    cout << pvp;
    GotoXY(104, 27);
    cout << pve;
    GotoXY(104, 29);
    cout << exit;
    if (mode.y == 25) {
        setColor(1, 15);
        GotoXY(104, 25);
        cout << pvp;
        setColor(4, 15);
    }
    else if (mode.y == 27) {
        setColor(1, 15);
        GotoXY(104, 27);
        cout << pve;
        setColor(4, 15);
    }
    else if (mode.y == 29) {
        setColor(1, 15);
        GotoXY(104, 29);
        cout << exit;
        setColor(4, 15);
    }
}
void SelectMode(toado& mode, int choice) {
    int y;
    do {
        HienThiMode(mode);
        int x = ChooseMode(mode);
        if (x == 0) {
            y = mode.y;
            break;
        }
    } while (1);
    if (y == 25) {
        int scoreX = 0;
        int scoreO = 0;
        while (1) {
            system("cls");
            int x= PlayGame_PvP(scoreX,scoreO);
            if (x == 1)
                break;
        }
        system("cls");
        Menu(choice);
    }
    else if (y == 27) {
        int scoreX = 0;
        int scoreO = 0;
        while (1) {
            system("cls");
            int x = PlayGame_PvE(scoreX,scoreO);
            if (x == 1)
                break;
        }
        system("cls");
        Menu(choice);
    }
    else if (y == 29) {
        system("cls");
        Menu(choice);
    }
}
void LoadGame(string s, matrix arr[BOARD_SIZE][BOARD_SIZE]) {
    resetData(arr);
    bool load = true;
    ifstream f1(s);
    ifstream f;
    if (!f1) {
        GotoXY(100, 100);
        std::cout << "File ban nhap khong ton tai";
        load = false;
        return;
    }
    else {
        f.open(s, ios::in);
        char c;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                f >> c;
                arr[i][j].z = c - '0'; // convert character to integer
                arr[i][j].x = 13 + j * 4;
                arr[i][j].y = 8 + i * 2;
            }
        }
    }
}
void LoadGameMenu(int& choice) {
    Khung();
    GotoXY(96, 22);
    setColor(2, 15);
    cout << "List of saved files";
    setColor(4, 15);
    std::ifstream file("namefile.txt");
    if (file.is_open()) {
        std::string lines[5];
        int count = 0;
        std::string line;
        while (std::getline(file, line)) {
            if (count < 5) {
                lines[count] = line;
                count++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            GotoXY(101, 25 + 2 * i);
            cout << lines[i];
        }
        GotoXY(96, 35);
        GotoXY(95, 40); setColor(47, 15); printf("  Press T to EXIT  ");
        GotoXY(101, 25);
        setColor(1, 15);
        cout << lines[0];
        file.close();
        toado loadgame = { 101,25 };
        int y;
        while (1) {
            HideCursor();
            int x = ControlLoadGame(loadgame);
            setColor(4, 15);
            for (int i = 0; i < 5; i++) {
                GotoXY(101, 25 + 2 * i);
                cout << lines[i];
            }
            GotoXY(96, 35);
            GotoXY(95, 40); setColor(47, 15); printf("  Press T to EXIT  ");
            setColor(1, 15);
            if (loadgame.y != 35) {
                GotoXY(loadgame.x, loadgame.y);
                cout << lines[(loadgame.y - 25) / 2];
            }
            if (x == 0) {
                y = loadgame.y;
                break;
            }
            else if (x == -1) {
                system("cls");
                Menu(choice);
                return;
            }
        }
        system("cls");
        if (y == 25) {
            matrix arr[BOARD_SIZE][BOARD_SIZE];
            LoadGame(lines[0],arr);
            LoadGameBoard(arr);
        }
        else if (y == 27) {
            matrix arr[BOARD_SIZE][BOARD_SIZE];
            LoadGame(lines[1],arr);
            LoadGameBoard(arr);
        }
        else if (y == 29) {
            matrix arr[BOARD_SIZE][BOARD_SIZE];
            LoadGame(lines[2],arr);
            LoadGameBoard(arr);
        }
        else if (y == 31) {
            matrix arr[BOARD_SIZE][BOARD_SIZE];
            LoadGame(lines[3],arr);
            LoadGameBoard(arr);
        }
        else if (y == 33) {
            matrix arr[BOARD_SIZE][BOARD_SIZE];
            LoadGame(lines[4],arr);
            LoadGameBoard(arr);
        }
        HideCursor();
        GotoXY(34, 48); cout << "PRESS ANY KEY TO EXIT";
        _getch();
        system("cls");
        Menu(choice);
    }
}
void Menu(int& choice) {
    Khung();
    HideCursor();
    toado menu = { 98,25 };
    printOptions(10);
    int y;
    do {
        HienThiLuaChonMenu(menu);
        int x = ControlMenu(menu);
        if (x == 0) {
            y = menu.y;
            break;
        }
    } while (1);
    system("cls");
    if (y == 25)
    {
        Khung();
        printOptions(6);
        toado mode = { 98,25 };
        SelectMode(mode, choice);
    }
    else if (y == 27)
        LoadGameMenu(choice);
    else if (y == 29)
        Help(choice);
    else if (y == 31)
        About(choice);
    else if (y == 33)
        Exit();
}
