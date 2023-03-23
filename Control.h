#pragma once
struct toado {
	int x, y;
};
void moveRight(toado& a);
void moveLeft(toado& a);
void moveDown(toado& a);
void moveUp(toado& a);
int CommandControl(toado& s, int& turn, int& countX, int& countO);
