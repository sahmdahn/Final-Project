#include "fstreams.h"
#include <fstream>

Floor::Floor(){
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			map[x][y] = 'c';
		}
	}
}

bool Floor::CanMove(int x, int y){
	/*Testing the value to make sure its not
	biggger/smaller than the array*/
	if (x < 0 || x>6){
		return false;
	}
	if (y < 0 || y>6){
		return false;
	}

	switch (map[x][y]){
	case '*':
		return false;
	default:
		return true;
	}
}

void Floor::Start(int &xCoord, int &yCoord){
	for (int x; x < 56; x++){
		for (int y; y < 6; y++){
			if (map[x][y] == 'S'){
				xCoord = x;
				yCoord = y;
				return;
			}
		}
	}
}

char Floor::Get(int x, int y){
	return map[x][y];
}






void Floor::readin(fstream &in){
	in.open("map.txt", ios::in);
	if (in.is_open())
	char tmp;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			in.get(map[x][y]);
		}
	}
}


void Floor::bob(){
	cout << "The array equals: " << endl;
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			cout << map[x][y];
		}
	}
	cout << endl;
}
