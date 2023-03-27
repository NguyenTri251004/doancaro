#include "menu.h"
#include"control.h"
#include "view.h"
#include "Function_C.h"

void playgame(int& thoat)
{
    khungplay();
    TextColor(14);
    TextColor(202);
    GotoXY(98, 25); printf("%c PLAY GAME  ", 175);
    TextColor(14);
    GotoXY(98, 26); printf("HELP");
    GotoXY(98, 27); printf("ABOUT");
    GotoXY(98, 28); printf("EXIT");
    int chon = 0;
    int toado = 25;
    //Vien quanh bang dieu khien
    TextColor(11);
    for (int i = 0; i < 45; i++)
    {
        GotoXY(82 + i, 21); printf("%c", 205);
    }
    for (int i = 0; i < 45; i++)
    {
        GotoXY(82 + i, 31); printf("%c", 205);
    }

    do {
        char a = _getch();
        if (a == 80 || a == 's' || a == 'S' || a == '2') chon = 1;
        else if (a == 72 || a == 'w' || a == 'W' || a == '8') chon = 2;
        else if (a == 13 || a == 'e' || a == 'e' || a == '5') chon = 3;
        else chon = 0;
        if (chon == 1 && toado < 28) toado++;
        else if (chon == 2 && toado > 25) toado--;
        if (toado == 25)
        {
            TextColor(202);
            GotoXY(98, 25); printf("%c PLAY GAME  ", 175);
            TextColor(14);
            GotoXY(98, 26); printf("HELP         ");
            GotoXY(98, 27); printf("ABOUT        ");
            GotoXY(98, 28); printf("EXIT         ");
            TextColor(0);
        }
        if (toado == 26)
        {
            TextColor(14);
            GotoXY(98, 25); printf("PLAY GAME    ");
            TextColor(202);
            GotoXY(98, 26); printf("%c HELP       ", 175);
            TextColor(14);
            GotoXY(98, 27); printf("ABOUT        ");
            GotoXY(98, 28); printf("EXIT         ");
            TextColor(0);
        }
        if (toado == 27)
        {
            TextColor(14);
            GotoXY(98, 25); printf("PLAY GAME  ", 175);
            GotoXY(98, 26); printf("HELP       ");
            TextColor(202);
            GotoXY(98, 27); printf("%c ABOUT      ", 175);
            TextColor(14);
            GotoXY(98, 28); printf("EXIT       ");
            TextColor(0);
        }
        if (toado == 28)
        {
            TextColor(14);
            GotoXY(98, 25); printf("PLAY GAME    ", 175);
            GotoXY(98, 26); printf("HELP         ");
            GotoXY(98, 27); printf("ABOUT        ");
            TextColor(202);
            GotoXY(98, 28); printf("%c EXIT       ", 175);
        }
    } while (chon != 3);
    system("cls");
    if (toado == 26) help(thoat);
    else if (toado == 27) about(thoat);
    else if (toado == 28) thoat = 1;
}

void khungplay()
{
    // KHUNG NGOAI
    TextColor(12);
    for (int i = 0; i < 209; i++)
    {
        GotoXY(1 + i, 0); printf("%c", 220);
    }
    for (int i = 0; i < 209; i++)
    {
        GotoXY(1 + i, 46); printf("%c", 205);
    }
    for (int j = 0; j < 45; j++)
    {
        GotoXY(0, j + 1); printf("%c", 186);
    }
    for (int j = 0; j < 45; j++)
    {
        GotoXY(209, j + 1); printf("%c", 186);
    }
    // 4 GOC
    GotoXY(0, 0); printf("%c", 201);
    GotoXY(0, 46); printf("%c", 200);
    GotoXY(209, 0); printf("%c", 187);//  209
    GotoXY(209, 46); printf("%c", 188);//  209
    // CHU Ten do an
    GotoXY(98, 0); TextColor(160); printf(" DO AN CO CARO ");
    //Vien quanh ten nhom
    TextColor(2);
    for (int i = 0; i < 55; i++)
    {
        GotoXY(77 + i, 42); printf("%c", 205);
    }
    for (int i = 0; i < 55; i++)
    {
        GotoXY(77 + i, 44); printf("%c", 205);
    }
    GotoXY(98, 43); printf("---NHOM 12---");
   
    // Chu co caro
    TextColor(2);
    GotoXY(67, 10); printf("  $$$$$$      $$$$$$$         $$$$$$       $$$$$     $$$$$$$$$     $$$$$$$\n"); Sleep(40);
    GotoXY(67, 11); printf("$$$    $$$  $$$     $$$     $$$    $$$    $$$ $$$    $$$    $$$  $$$     $$$\n"); Sleep(40); TextColor(3);
    GotoXY(67, 12); printf("$$$         $$$     $$$     $$$          $$$   $$$   $$$   $$$   $$$     $$$\n"); Sleep(40);
    GotoXY(67, 13); printf("$$$         $$$     $$$     $$$         $$$$$$$$$$$  $$$$$$$$    $$$     $$$\n"); Sleep(40); TextColor(4);
    GotoXY(67, 14); printf("$$$    $$$  $$$     $$$     $$$    $$$  $$$     $$$  $$$   $$$   $$$     $$$\n"); Sleep(40);
    GotoXY(67, 15); printf("  $$$$$$      $$$$$$$         $$$$$$    $$$     $$$  $$$    $$$    $$$$$$$  \n");
}
// Trang HELP
void help(int& thoat)
{
    khungplay();
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 11); printf(" ");
    }
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 21); printf(" ");
    }
    GotoXY(98, 25);  TextColor(66); printf("    HELP    ");
    GotoXY(100, 28); TextColor(10); printf("DIEU KHIEN");
    TextColor(15);
    GotoXY(86, 30);  printf("-NGUOI CHOI 1-");    GotoXY(110, 30);  printf("-NGUOI CHOI 2-"); TextColor(11);
    GotoXY(86, 32); printf("A: Sang Trai");     GotoXY(110, 32); printf("4: Sang Trai");
    GotoXY(86, 33); printf("D: Sang Phai");     GotoXY(110, 33); printf("6: Sang Phai");
    GotoXY(86, 34); printf("S: Len Tren");      GotoXY(110, 34); printf("8: Len Tren");
    GotoXY(86, 35); printf("W: Xuong Duoi");    GotoXY(110, 35); printf("2: Xuong Duoi");
    GotoXY(86, 36); printf("E: OK");            GotoXY(110, 36); printf("5: OK");

    GotoXY(100, 40); TextColor(47); printf("  EXIT  ");
    //GotoXY(41, 40);
    TextColor(0);
    char a;
    do
    {
        a = _getch();
    } while (a != 13 && a != 'e' && a != 'E' && a != '5' && a != 8);
    system("cls");
    fflush(stdin);
    playgame(thoat);
}
// Trang about
void about(int& thoat)
{
    khungplay();
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 11); printf(" ");
    }
    for (int i = 0; i < 45; i++)
    {
        GotoXY(18 + i, 21); printf(" ");
    }
    GotoXY(98, 25);  TextColor(66);  printf("    ABOUT   ");
    GotoXY(91, 28); TextColor(12); printf("DO AN CUOI KI I - GAME CO CARO");
    GotoXY(95, 29); TextColor(12); printf("----- NHOM 12 -----");      GotoXY(34, 17);

    GotoXY(87, 31); TextColor(15); printf("- Ho va ten -");          GotoXY(115, 31); TextColor(15); printf("- MSSV -");
    GotoXY(87, 32); TextColor(11); printf("Pham Van Minh");          GotoXY(115, 32); TextColor(11); printf("22127272");
    GotoXY(87, 33); TextColor(11); printf("Truong Nhat Huy");        GotoXY(115, 33); TextColor(11); printf("22127168");
    GotoXY(87, 34); TextColor(11); printf("Nguyen The Quan");        GotoXY(115, 34); TextColor(11); printf("22127341");
    GotoXY(87, 35); TextColor(11); printf("Nguyen Phuoc Minh Tri");  GotoXY(115, 35); TextColor(11); printf("22127424");

    GotoXY(100, 40); TextColor(47); printf("  EXIT  ");
    //GotoXY(50, 40); //chua hieu dong nay
    TextColor(0);
    char a;
    do
    {
        a = _getch();
    } while (a != 13 && a != 'e' && a != 'E' && a != '5' && a != 8);
    system("cls");
    fflush(stdin);
    playgame(thoat);
}

