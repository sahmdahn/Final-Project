#include "fstreams.h"
#include <fstream>

Floor::Floor(){
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < 6; y++){
			map[x][y]
		}
	}
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