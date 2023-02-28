#include <iostream>
#include<Windows.h>
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
#define BOARD_SIZE 40 // Kích thức ma trận bàn cờ
#define LEFT 5 // Tọa độ trái màn hình bàn cờ
#define TOP 5 // Tọa độ trên màn hình bàn cờ
// Khai báo kiểu dữ liệu
struct _POINT { int x, y, c; }; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
_POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma trận bàn cờ
bool _TURN; //true là lượt người thứ nhất và false là lượt người thứ hai
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int _X, _Y;
void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}
void DrawBoard(int pSize) {
	for (int i = 0; i <= pSize; i++)
	{
		GotoXY(i, 0); printf("%c", 205); 
		Sleep(1);//Tạm dừng 1ms
	}
	//Sử dụng vòng lặp vẽ đường thẳng ngang phía dưới
	for (int i = 0; i <= pSize; i++)
	{
		GotoXY(i, pSize/2); printf("%c", 205);
		Sleep(1);
	}
	//Sử dụng vòng lặp vẽ đường thẳng dọc bên trái
	for (int i = 0; i <= pSize/2; i++)
	{
		GotoXY(0, i); printf("%c", 186);
		Sleep(1);
	}
	//Sử dụng vòng lặp vẽ đường thẳng dọc bên phải
	for (int i = 0; i <= pSize/2; i++)
	{
		GotoXY(pSize, i); printf("%c", 186);
		Sleep(1);
	}
	// Kẻ khung bên trong
	GotoXY(0, 0); printf("%c", 201);
	GotoXY(0, pSize/2); printf("%c", 200);
	GotoXY(pSize, 0); printf("%c", 187);
	GotoXY(pSize, pSize/2); printf("%c", 188);
}
void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE); // Vẽ màn hình game
}

int main()
{
	FixConsoleWindow();
	StartGame();
	bool validEnter = true;
	return 0;
}

