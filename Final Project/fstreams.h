#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Floor{
private:
	char map[6][6];
public:
	Floor();
	void readin(fstream &in);
	bool CanMove(int x, int y);
	
	//Getters
	char Get(int x, int y);
	void bob();
};

