#include "fstreams.h"
#include <fstream>

floor::floor(){
	fstream in;
	in.open("map.txt", ios::in);
	char tmp;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			in.get(map[x][y]);
		}
	}
}