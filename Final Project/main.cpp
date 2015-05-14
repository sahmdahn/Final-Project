#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "fstreams.h"

using namespace std;

void Initial(Floor f[]);

void main(){
	int x = -1;
	int y = -1;
	int z = -1;
	char dir;

	
	Floor f[5];

	Initial(f);

	for (int zCoord = 0; zCoord < 5; zCoord++){

	}

	//User input for direction
	cout << "Choose a direction: " << endl;
	cout << "(w,a,s,d)" << endl;
	cin >> dir;

	//Testing the dir value to see if the user can move that way
	switch (dir){
	case 'w':
		f[z].CanMove(x, y + 1);
		break;
	case'a':
		f[z].CanMove(x - 1, y);
	case's':
		f[z].CanMove(x, y - 1);
	case'd':
		f[z].CanMove(x + 1, y);
	}
}


void Initial(Floor f[]){
	//Initialize values
	fstream in;
	in.open("map.txt", ios::in);
	for (int i = 0; i < 5; i++){
		f[i].readin(in);
	}
	in.close();
}