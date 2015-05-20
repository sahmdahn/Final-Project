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