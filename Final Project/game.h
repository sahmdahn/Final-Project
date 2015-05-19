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


};

