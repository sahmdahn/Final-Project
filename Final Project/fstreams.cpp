#include <fstream>

#include "fstreams.h"

//Constructor
Floor::Floor(){
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			map[x][y] = 'c';
		}
	}
}

void Floor::Start(int &xCoord, int &yCoord){
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

//Getters
char Floor::Get(int x, int y){
	return map[x][y];
}

//Setters
void Floor::Set(int x, int y, char c) {
	map[x][y] = c;
}