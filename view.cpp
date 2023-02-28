#include <iostream>
#include <Windows.h>
#include "view.h"
using namespace std;
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) {
 	COORD coord;
 	coord.X = x;
 	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawBoard(int pSize) {
for (int i = 0; i <= 44; i++)
	{
		for (int j = 0; j <= 24; j++)
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
    for (int i = 0; i <= 78; i++)
    {
        GotoXY(i, 0); printf("%c", 205);
        Sleep(1);
    }
    for (int i = 0; i <= 78; i++)
    {
        GotoXY(i, 46); printf("%c", 205);
        Sleep(1);
    }
    for (int i = 0; i <= 45; i++)
    {
        GotoXY(0, i); printf("%c", 186);
        Sleep(1);
    }
    for (int i = 0; i <= 45; i++)
    {
        GotoXY(79, i); printf("%c", 186);
        Sleep(1);
    }
    GotoXY(0, 0); printf("%c", 201);
    GotoXY(0, 46); printf("%c", 200);
    GotoXY(79, 0); printf("%c", 187);
    GotoXY(79, 46); printf("%c", 188);

   
    for (int i = 2; i <= 77; i++)
    {
        GotoXY(i, 1); printf("%c", 205);
        Sleep(1);
    }
    for (int i = 1; i <= 77; i++)
    {
        GotoXY(i, 45); printf("%c", 205);
        Sleep(1);
    }
    for (int i = 1; i <= 44; i++)
    {
        GotoXY(1, i); printf("%c", 186);
        Sleep(1);
    }
    for (int i = 1; i <= 44; i++)
    {
        GotoXY(78, i); printf("%c", 186);
        Sleep(1);
    }
    GotoXY(1, 1); printf("%c", 201);
    GotoXY(1, 45); printf("%c", 200);
    GotoXY(78, 1); printf("%c", 187);
    GotoXY(78, 45); printf("%c", 188);
    for (int i = 0; i < 15; i++)
    {
        GotoXY(63 + i, 4); printf("%c", 205);
    }
    for (int i = 0; i < 2; i++)
    {
        GotoXY(63, i + 2); printf("%c", 186);
    }
    GotoXY(63, 4); printf("%c", 200);
    GotoXY(67, 2);  printf("Luot Choi");
    GotoXY(68, 3); printf("--   --");
    GotoXY(71, 3); printf("%c", 2);
    for (int i = 0; i < 15; i++)
    {
        GotoXY(2 + i, 4); printf("%c", 205);
    }
    for (int i = 0; i < 2; i++)
    {
        GotoXY(17, i + 2); printf("%c", 186);
    }
    for (int i = 0; i < 43; i++)
    {
        GotoXY(19 + i, 2); printf("_");
    }
    GotoXY(17, 4); printf("%c", 188);
    GotoXY(34, 0); printf(" GAME CO CARO ");
    GotoXY(25, 2); printf("NHOM 12 - KTLT - K22");
    GotoXY(5, 2);  printf("So Quan Co");
    GotoXY(3, 3); printf("  -   |   -   ");
    GotoXY(3, 3);  printf("X");
    GotoXY(11, 3); printf("O");
    GotoXY(42, 40);
}
int AskContinue(){
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
	printf("Nhan 'y/n' de tiep tuc/dung: ");
	return toupper(getch());
}

