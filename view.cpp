#include"Function_C.h"
#include "view.h"
using namespace std;
void HideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void FullScreen() {
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
void setColor(int textCol, int bgCol) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (textCol + (bgCol * 16)));
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) { //tọa độ
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawBoard() { //vẽ bảng
    setColor(3, 15);
    
    for (int i = -3; i <= 40; i++) //vẽ ô bên trong
    {
        for (int j = -8; j <= 24; j++)
        {
            if (i < 4) printf(" ");
            else if (j < 3) printf(" ");
            else if (i % 2 == 0 && j > 4 && j < 23)  printf("%c%c%c%c", 197, 196, 196, 196);
            else if (i % 2 == 1 && j > 4 && j < 23) printf("%c   ", 179);
            else if (i % 2 == 0 && j == 23) printf("%c", 197);
            else if (i % 2 == 1 && j == 23) printf("%c", 179);
        }
        printf("\n");
    }
    for (int i = 7; i < 44; i++) {  //39->54 vẽ khung bên ngoài
        GotoXY(11, i); printf("%c", 186);
    }
    for (int i = 7; i < 44; i++) {
        GotoXY(83, i); printf("%c", 186);
    }
    for (int i = 11; i < 84; i++) {
        GotoXY(i, 7); printf("%c", 205);
    }
    for (int i = 11; i < 84; i++) {
        GotoXY(i, 43); printf("%c", 205);
    }
    GotoXY(11, 7); printf("%c", 201);
    GotoXY(11, 43); printf("%c", 200);
    GotoXY(83, 7); printf("%c", 187);
    GotoXY(83, 43); printf("%c", 188);
    for (int i = 6; i < 45; i++) {  //39->54 vẽ khung vien
        GotoXY(9, i); printf("%c", 186);
    }
    for (int i = 6; i < 45; i++) {
        GotoXY(85, i); printf("%c", 186);
    }
    for (int i = 10; i < 85; i++) {
        GotoXY(i, 6); printf("%c", 205);
    }
    for (int i = 10; i < 85; i++) {
        GotoXY(i, 44); printf("%c", 205);
    }
    GotoXY(9, 6); printf("%c", 201);
    GotoXY(9, 44); printf("%c", 200);
    GotoXY(85, 6); printf("%c", 187);
    GotoXY(85, 44); printf("%c", 188);
    //nối liền nét đứt giữa ô trong và viền ngoài
    {
        int x = 15;
        while (x != 83)
        {
            GotoXY(x, 7);
            printf("%c", 209);
            x += 4;
        }
        x = 15;
        while (x != 83)
        {
            GotoXY(x, 43);
            printf("%c", 207);
            x += 4;
        }
        x = 9;
        while (x != 43)
        {
            GotoXY(11, x);
            printf("%c", 199);
            x += 2;
        }
        x = 9;
        while (x != 43)
        {
            GotoXY(83, x);
            printf("%c", 182);
            x += 2;
        }  
    }
}
//Hien thi luot danh
void ShowNumberTurn(int countX, int countO, int& turn) {
    GotoXY(151, 39); setColor(5, 15); printf("Luot Choi");

    if (turn == 1) {
        setColor(1, 15);
        GotoXY(151, 40); cout << "##     ## ";
        GotoXY(151, 41); cout << " ##   ##  ";
        GotoXY(151, 42); cout << "  ## ##   ";
        GotoXY(151, 43); cout << "   ###    ";
        GotoXY(151, 44); cout << "  ## ##   ";
        GotoXY(151, 45); cout << " ##   ##  ";
        GotoXY(151, 46); cout << "##     ##";
    }
    else if (turn == 0) {
        setColor(12, 15);
        GotoXY(151, 40); printf(" #######   ");
        GotoXY(151, 41); printf("##     ## ");
        GotoXY(151, 42); printf("##     ## ");
        GotoXY(151, 43); printf("##     ## ");
        GotoXY(151, 44); printf("##     ##  ");
        GotoXY(151, 45); printf("##     ## ");
        GotoXY(151, 46); printf(" ####### ");
    }

    GotoXY(121, 13); setColor(1, 15); printf("Player #1");
    GotoXY(116, 16); printf("So quan da danh - ");
    GotoXY(181, 13); setColor(12, 15); printf("Player #2");
    GotoXY(176, 16); printf("So quan da danh - ");
    setColor(1, 15);
    GotoXY(134, 16); cout << countX;
    setColor(12, 15);
    GotoXY(194, 16); cout << countO;


}
void Khung()
{
    // KHUNG NGOAI
    setColor(11, 15);
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
    GotoXY(98, 0); setColor(1, 15); cout << " DO AN CO CARO ";
    //Vien quanh ten nhom
    setColor(2, 15);
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
    setColor(2, 15);
    GotoXY(67, 10); printf("  $$$$$$      $$$$$$$         $$$$$$       $$$$$     $$$$$$$$$     $$$$$$$\n"); Sleep(40);
    GotoXY(67, 11); printf("$$$    $$$  $$$     $$$     $$$    $$$    $$$ $$$    $$$    $$$  $$$     $$$\n"); Sleep(40); setColor(3, 15);
    GotoXY(67, 12); printf("$$$         $$$     $$$     $$$          $$$   $$$   $$$   $$$   $$$     $$$\n"); Sleep(40);
    GotoXY(67, 13); printf("$$$         $$$     $$$     $$$         $$$$$$$$$$$  $$$$$$$$    $$$     $$$\n"); Sleep(40); setColor(4, 15);
    GotoXY(67, 14); printf("$$$    $$$  $$$     $$$     $$$    $$$  $$$     $$$  $$$   $$$   $$$     $$$\n"); Sleep(40);
    GotoXY(67, 15); printf("  $$$$$$      $$$$$$$         $$$$$$    $$$     $$$  $$$    $$$    $$$$$$$  \n");

}
void Custom()
{
    /*setColor(3, 15);
    GotoXY(120, 55); printf("  $$$$$$      $$$$$$$         $$$$$$       $$$$$     $$$$$$$$$     $$$$$$$\n"); Sleep(40);
    GotoXY(120, 56); printf("$$$    $$$  $$$     $$$     $$$    $$$    $$$ $$$    $$$    $$$  $$$     $$$\n"); Sleep(40); setColor(3, 15);
    GotoXY(120, 57); printf("$$$         $$$     $$$     $$$          $$$   $$$   $$$   $$$   $$$     $$$\n"); Sleep(40);
    GotoXY(120, 58); printf("$$$         $$$     $$$     $$$         $$$$$$$$$$$  $$$$$$$$    $$$     $$$\n"); Sleep(40); setColor(4, 15);
    GotoXY(120, 59); printf("$$$    $$$  $$$     $$$     $$$    $$$  $$$     $$$  $$$   $$$   $$$     $$$\n"); Sleep(40);
    GotoXY(120, 60); printf("  $$$$$$      $$$$$$$         $$$$$$    $$$     $$$  $$$    $$$    $$$$$$$  \n");*/

    //ve X
    setColor(1, 15);
    GotoXY(121, 5); printf("##     ## ");
    GotoXY(121, 6); printf(" ##   ##");
    GotoXY(121, 7); printf("  ## ##   ");
    GotoXY(121, 8); printf("   ###");
    GotoXY(121, 9); printf("  ## ## ");
    GotoXY(121, 10); printf(" ##   ## ");
    GotoXY(121, 11); printf("##     ## ");

    //ve O
    setColor(12, 15);
    GotoXY(181, 5); printf(" #######   ");
    GotoXY(181, 6); printf("##     ## ");
    GotoXY(181, 7); printf("##     ## ");
    GotoXY(181, 8); printf("##     ## ");
    GotoXY(181, 9); printf("##     ##  ");
    GotoXY(181, 10); printf("##     ## ");
    GotoXY(181, 11); printf(" ####### ");
    //khung player 1
    for (int i = 13; i <= 20; i++)
    {
        setColor(1, 15);
        GotoXY(104, i); printf("%c", 186);
        GotoXY(146, i); printf("%c", 186);
    }
    for (int i = 104; i <= 146; i++)
    {
        setColor(1, 15);
        GotoXY(i, 13); printf("%c", 205);
        GotoXY(i, 20); printf("%c", 205);
    }
    GotoXY(104, 13); printf("%c", 201);
    GotoXY(104, 20); printf("%c", 200);
    GotoXY(146, 13); printf("%c", 187);
    GotoXY(146, 20); printf("%c", 188);

    //khung player 2
    for (int i = 13; i <= 20; i++)
    {
        setColor(12, 15);
        GotoXY(183-19, i); printf("%c", 186);
        GotoXY(225-19, i); printf("%c", 186);
    }

    for (int i = 183-19; i <= 225-19; i++)
    {
        setColor(12, 15);
        GotoXY(i, 13); printf("%c", 205);
        GotoXY(i, 20); printf("%c", 205);
    }
    GotoXY(183-19, 13); printf("%c", 201);
    GotoXY(183-19, 20); printf("%c", 200);
    GotoXY(225-19, 13); printf("%c", 187);
    GotoXY(225-19, 20); printf("%c", 188);

    //khung turn
    for (int i = 39; i <= 47; i++)
    {
        setColor(5, 15);
        GotoXY(134, i); printf("%c", 186);
        GotoXY(184-7, i); printf("%c", 186);
    }

    for (int i = 134; i <= 181-4; i++)
    {
        setColor(5, 15);
        GotoXY(i, 39); printf("%c", 205);
        GotoXY(i, 47); printf("%c", 205);
    }
    GotoXY(138-4, 39); printf("%c", 201);
    GotoXY(138-4, 47); printf("%c", 200);
    GotoXY(181-4, 39); printf("%c", 187);
    GotoXY(181-4, 47); printf("%c", 188);


    //khung huong dan choi
}
