#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class game{
private:
	int x;
	int y;
	int z;
	char dir;
public:
	game();
	void begin();
	void direction();


};

