#pragma once
#include"Function_C.h"
#include"Control.h"
#include"view.h"
#define BOARD_SIZE 18
struct matrix {
	int x, y, z;
};
void resetData(matrix arr[BOARD_SIZE][BOARD_SIZE]);
void PlayGame_PvP();
void PlayGame_PvE();
