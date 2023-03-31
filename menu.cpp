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
void HienThiLuaChonMenu(toado menu) {
    if (menu.y == 25) {
        GotoXY(98, 25);
        setColor(1, 15);
        printf("%c%c PLAY GAME %c%c", 175, 175, 174, 174);
        setColor(4, 15);
        GotoXY(103, 26);
        printf("HELP");
        GotoXY(103, 27);
        printf("ABOUT");
        GotoXY(103, 28);
        printf("EXIT");
    }
    else if (menu.y == 26) {
        GotoXY(101, 25);
        setColor(4, 15);
        printf("PLAY GAME");
        setColor(1, 15);
        GotoXY(98, 26);  printf("%c%c", 175, 175);
        GotoXY(103, 26); printf("HELP");
        GotoXY(111, 26); printf("%c%c", 174, 174);
        setColor(4, 15);
        GotoXY(103, 27);
        printf("ABOUT");
        GotoXY(103, 28);
        printf("EXIT");
    }
    else if (menu.y == 27) {
        GotoXY(101, 25);
        setColor(4, 15);
        printf("PLAY GAME");
        GotoXY(103, 26);
        printf("HELP");
        setColor(1, 15);
        GotoXY(98, 27);  printf("%c%c", 175, 175);
        GotoXY(103, 27); printf("ABOUT");
        GotoXY(111, 27); printf("%c%c", 174, 174);
        setColor(4, 15);
        GotoXY(103, 28);
        printf("EXIT");
    }
    else if (menu.y == 28) {
        GotoXY(101, 25);
        setColor(4, 15);
        printf("PLAY GAME");
        GotoXY(103, 26);
        printf("HELP");
        GotoXY(103, 27);
        printf("ABOUT");
        setColor(1, 15);
        GotoXY(98, 28);  printf("%c%c", 175, 175);
        GotoXY(103, 28); printf("EXIT");
        GotoXY(111, 28); printf("%c%c", 174, 174);
        setColor(4, 15);
    }
}
void HienThiMode(toado mode) {
    if (mode.y == 25) {
        setColor(1, 15);
        GotoXY(100, 25); printf("%c%c", 175, 175);
        GotoXY(104, 25); printf("PvP");
        GotoXY(109, 25); printf("%c%c", 174, 174);
        setColor(4, 15);
        GotoXY(104, 26);
        printf("PvE");
        GotoXY(104, 27);
        printf("EXIT");
    }
    else if (mode.y == 26) {
        GotoXY(104, 25);
        setColor(4, 15);
        printf("PvP");
        setColor(1, 15);
        GotoXY(100, 26); printf("%c%c", 175, 175);
        GotoXY(104, 26); printf("PvE");
        GotoXY(109, 26); printf("%c%c", 174, 174);
        setColor(4, 15);
        GotoXY(104, 27);
        printf("EXIT");
    }
    else if (mode.y == 27) {
        GotoXY(104, 25);
        setColor(4, 15);
        printf("PvP");
        GotoXY(104, 26);
        printf("PvE");;
        setColor(1, 15);
        GotoXY(100, 27); printf("%c%c", 175, 175);
        GotoXY(104, 27); printf("EXIT");
        GotoXY(109, 27); printf("%c%c", 174, 174);
        setColor(4, 15);

    }

}
void Menu(int& choice) {
    Khung();
    HideCursor();
    toado menu = { 98,25 };
    GotoXY(98, 25);
    setColor(1, 15);
    printf("%c%c PLAY GAME %c%c", 175, 175, 174, 174);
    setColor(4, 15);
    GotoXY(103, 26);
    printf("HELP");
    GotoXY(103, 27);
    printf("ABOUT");
    GotoXY(103, 28);
    printf("EXIT");
    while (1)
    {
        HienThiLuaChonMenu(menu);
        int x = ControlMenu(menu);
        if (x == 1) {
            if (menu.y == 25)
                choice = 1;
            else if (menu.y == 26)
                choice = 2;
            else if (menu.y == 27)
                choice = 3;
            else if (menu.y == 28)
                choice = 4;
            break;
        }
        if (x == 0) {
            GotoXY(menu.x, menu.y - 1);
            cout << "  ";
            GotoXY(menu.x + 13, menu.y - 1);
            cout << "  ";
        }
        else if (x == -1)
        {
            GotoXY(menu.x, menu.y + 1);
            cout << "  ";
            GotoXY(menu.x + 13, menu.y + 1);
            cout << "  ";
        }
    }
    system("cls");
    if (choice == 1)
    {
        Khung();
        toado mode = { 98,25 };
        int a;
        while (1)
        {
            HienThiMode(mode);
            int x = ChooseMode(mode);
            if (x == 1) {
                if (mode.y == 25) {
                    a = 1;
                }
                else if (mode.y == 26) {
                    a = 2;
                }
                else if (mode.y = 27) {
                    a = 3;
                }
                break;
            }
            if (x == 0) {
                GotoXY(mode.x + 2, mode.y - 1);
                cout << "  ";
                GotoXY(mode.x + 11, mode.y - 1);
                cout << "  ";
            }
            else if (x == -1)
            {
                GotoXY(mode.x + 2, mode.y + 1);
                cout << "  ";
                GotoXY(mode.x + 11, mode.y + 1);
                cout << "  ";
            }
        }
        system("cls");
        if (a == 1) {
            ShowConsoleCursor();
            PlayGame_PvP();
        }
        else if (a == 2)
            //PvE
            ;
        else if (a == 3)
        {
            system("cls");
            Menu(choice);
        }
    }
    else if (choice == 2)
        Help(choice);
    else if (choice == 3)
        About(choice);
}
