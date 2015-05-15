#include "fstreams.h"
#include <fstream>

Floor::Floor(){
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			map[x][y] = 'c';
		}
	}
}

void Floor::readin(fstream &in){
	in.open("map.txt", ios::in);
	if (in.is_open()){
		char tmp;
		while (!in.eof()){
			in.get(tmp);
			//in >> map[x][y];
			cout << tmp;
		}
		//for (int x = 0; x < 6; x++) {
			//for (int y = 0; y < 6; y++) {
				
				
			//}
		//}
		cout << endl;
	}
}

void Floor::Start(int &xCoord, int &yCoord){
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			if (map[x][y] == 'S'){
				xCoord = x;
				yCoord = y;
				return;
			}
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

//Getters
char Floor::Get(int x, int y){
	return map[x][y];
}