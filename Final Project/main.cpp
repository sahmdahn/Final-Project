#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "fstreams.h"
#include "game.h"

using namespace std;

void main(){

	cout << "========================================\n\n";
	cout << "THE 3-D MAZE\n\n";
	cout << "Created By:\n";
	cout << "Project Manager: Sean Traynor\n";
	cout << "Quality Assurance: Alex Mann\n";
	cout << "General Developer: Sean Mason\n\n";
	cout << "Instructor: David Marchbanks\n\n";
	cout << "========================================\n\n";

	system("pause"); system("cls");

	int x = -1;
	int y = -1;
	int z = -1;

	Floor f[5];

	for (int zCoord = 0; zCoord < 5; zCoord++){
		f[zCoord].Start(x, y);

	}

	game a;
	a.Initial();
	a.begin();
}