#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>

#include"fstreams.h"

using namespace std;

class game{
private:
	int x;
	int y;
	int z;
	Floor f[5];
public:
	game();
	void begin();
	void direction();
	void HandleMove(int newx, int newy);

};

void game::HandleMove(int newx, int newy){
	x = newx;
	y = newy;
	switch (f[z].Get(x, y)){
	case '*':
		return false;
	case 1:
		z = 1;
		break;
	case 2:
		z = 2;
		break;
	case 3:
		z = 3;
		break;
	case 4:
		z = 4;
		break;
	case 5:
		z = 5;
		break;
	case 'E':

	}
}