#pragma once
#include"Function_C.h"
#include"Control.h"
#include"view.h"
#include<fstream>
#include<string>
#define BOARD_SIZE 18
struct matrix {
	int x, y, z;
};
void resetData(matrix arr[BOARD_SIZE][BOARD_SIZE]);
int PlayGame_PvP(int&scoreX,int&scoreO);
int PlayGame_PvE(int &score,int&scoreO);
void SaveGame(matrix arr[BOARD_SIZE][BOARD_SIZE]);
void LoadGameBoard(matrix arr[BOARD_SIZE][BOARD_SIZE]);

