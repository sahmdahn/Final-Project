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
	int a;
	char tmp;
	Floor f[5];
public:
	game();
	void begin();
	void direction();
	void HandleMove(int newx, int newy);
	bool TheEnd();
};

//Tests user input to see if they can move their on the map
void game::HandleMove(int newx, int newy){
	x = newx;
	y = newy;

	switch (f[z].Get(x, y)){
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
		if (TheEnd()){
			z = 0;
			for (int zCoord = 0; zCoord < 5; zCoord++){
				int xTemp = -1, yTemp = -1;
				f[zCoord].Start(xTemp, yTemp);
				if (xTemp != -1) {
					x = xTemp;
					y = yTemp;
					z = zCoord;
					break;
				}
				else{
					cout << "System Error!" << endl;
					cout << "&(*^UI&*F^*$Giy7t%KJ&^%^45**&kt5^F^" << endl;
				}
			}
		}
		else {
			//false
			a = 1;
			//x != xEnd && y != yEnd, x != zEnd)
		}
		break;
	}
}

bool game::TheEnd() {
	char c;
	cout << "Try again [Y/N]?" << endl;
	cin >> c;

	if (c == 'y'){
		return true;
	}
	else{
		cout << "You have chosen to exit the game." << endl;
		cout << "Thanks for playing!" << endl;
		return false;
	}
}