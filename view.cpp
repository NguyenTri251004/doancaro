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
    GotoXY(100, 3); setColor(5, 15); printf("Luot Choi");
    GotoXY(101, 4); printf("--   --");

    if (turn == 1) {
        setColor(1, 15);
        GotoXY(104, 4); cout << "X";
    }
    else if (turn == 0) {
        setColor(12, 15);
        GotoXY(104, 4); cout << "O";
    }

    GotoXY(150, 3); setColor(1, 15); printf("Player 1");
    GotoXY(151, 4); printf("X - ");
    GotoXY(179, 3); setColor(12, 15); printf("Player 2");
    GotoXY(180, 4); printf("O - ");
    setColor(1, 15);
    GotoXY(155, 4); cout << countX;
    setColor(12, 15);
    GotoXY(184, 4); cout << countO;

   
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
