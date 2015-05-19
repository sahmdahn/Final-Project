#include "fstreams.h"
#include <fstream>

//Constructor
Floor::Floor(){
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			map[x][y] = 'c';
		}
	}
}

void Floor::Start(int &xCoord, int &yCoord){
	//Don't need
	for (int y = 0; y < 6; y++){
		for (int x = 0; x < 6; x++){
			cout << map[x][y];
		}
		cout << endl;
	}
	system("pause");
	
	for (int y = 0; y < 6; y++){
		for (int x = 0; x < 6; x++){
			if (map[x][y] == 'S'){
				xCoord = x;
				yCoord = y;
				return;
			}
		}
	}
}

/*Testing the value to make sure its not
biggger/smaller than the array*/
bool Floor::CanMove(int x, int y){
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


//Getters
char Floor::Get(int x, int y){
	return map[x][y];
}

//Setters
void Floor::Set(int x, int y, char c) {
	map[x][y] = c;
}