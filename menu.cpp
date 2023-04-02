#include "menu.h"
#include"control.h"
#include "view.h"
#include "Function_C.h"
#include"Game.h"
using namespace std;
void printOptions(int x) {
    setColor(3, 15);
    int left = 99, top = 24;
    GotoXY(left, top);
    putchar(201);
    for (int i = 1; i < 12; i++) {
        putchar(205);
    }
    putchar(187);
    for (int i = 1; i < x; i++) { //(8/2 = so o )
        GotoXY(left, top + i);
        if (i % 2 != 0) {
            putchar(186);
            GotoXY(left + 12, top + i);
            putchar(186);
        }
        else {
            putchar(199);
            for (int i = 1; i < 12; i++) {
                putchar(196);
            }
            putchar(182);
        }
    }
    GotoXY(left, top + x);
    putchar(200);
    for (int i = 1; i < 12; i++) {
        putchar(205);
    }
    putchar(188);
}
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
    GotoXY(86, 30);  printf("-NGUOI CHOI 1-");    GotoXY(110, 30);  printf("-NGUOI CHOI 2-"); setColor(1, 15);
    GotoXY(86, 32); printf("A: Sang Trai");     GotoXY(110, 32); printf("4: Sang Trai");
    GotoXY(86, 33); printf("D: Sang Phai");     GotoXY(110, 33); printf("6: Sang Phai");
    GotoXY(86, 34); printf("S: Len Tren");      GotoXY(110, 34); printf("8: Len Tren");
    GotoXY(86, 35); printf("W: Xuong Duoi");    GotoXY(110, 35); printf("2: Xuong Duoi");
    GotoXY(86, 36); printf("Enter: OK");            GotoXY(110, 36); printf("5: OK");
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
    GotoXY(94, 25);  setColor(3, 15);  printf("--------ABOUT--------");
    GotoXY(91, 28); setColor(12, 15); printf("DO AN CUOI KI I - GAME CO CARO");
    GotoXY(95, 29); setColor(12, 15); printf("----- NHOM 12 -----");      GotoXY(34, 17);

    GotoXY(87, 31); setColor(1, 15); printf("- Ho va ten -");          GotoXY(115, 31); setColor(1, 15); printf("- MSSV -");
    GotoXY(87, 32); setColor(11, 15); printf("Pham Van Minh");          GotoXY(115, 32); setColor(11, 15); printf("22127272");
    GotoXY(87, 33); setColor(11, 15); printf("Truong Nhat Huy");        GotoXY(115, 33); setColor(11, 15); printf("22127168");
    GotoXY(87, 34); setColor(11, 15); printf("Nguyen The Quan");        GotoXY(115, 34); setColor(11, 15); printf("22127341");
    GotoXY(87, 35); setColor(11, 15); printf("Nguyen Phuoc Minh Tri");  GotoXY(115, 35); setColor(11, 15); printf("22127424");

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
void HienThiLuaChonMenu(toado s) {
    char a[10] = "PLAY GAME";
    char b[10] = "HELP";
    char c[10] = "ABOUT";
    char d[10] = "EXIT";
    setColor(4, 15);
    GotoXY(101, 25);
    cout << a;
    GotoXY(103, 27);
    cout << b;
    GotoXY(103, 29);
    cout << c;
    GotoXY(103, 31);
    cout << d;
    if (s.y == 25) {
        setColor(1, 15);
        GotoXY(101, 25);
        cout << a;
        setColor(4, 15);
    }
    else if (s.y == 27) {
        setColor(1, 15);
        GotoXY(103, 27);
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
        system("cls");
        PlayGame_PvP();
        //ask continue = while && luu file

    }
    else if (y == 27) {
        //pve
    }
    else if (y == 29) {
        system("cls");
        Menu(choice);
    }
}
void Menu(int& choice) {
    Khung();
    HideCursor();
    toado menu = { 98,25 };
    printOptions(8);
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
        Help(choice);
    else if (y == 29)
        About(choice);
    else if (y == 31)
        system("cls");
}
