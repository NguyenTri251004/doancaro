#pragma once
void HideCursor(); 
void ShowConsoleCursor();
void FullScreen();
void setColor(int textCol, int bgCol); 
void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard();
void ShowNumberTurn(int countX, int countO, int turn,int&scoreX,int&scoreO);
void Khung(); 
void Custom();
void printOptions(int x);
void AskContinue();
