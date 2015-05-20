#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "fstreams.h"
#include "game.h"

using namespace std;

void Initial(Floor f[]);

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

	Initial(f);
	

	cout << "The map." << endl;
	for (int zCoord = 0; zCoord < 5; zCoord++){
		f[zCoord].Start(x, y);

	}
	cout << x << " ";
	cout << y;
	cout << endl;
	system("pause"); system("cls");

	game a;

	a.begin();
}


	


void Initial(Floor f[]) {
	//Initialize values
	fstream in;
	in.open("map.txt", ios::in);
	if (!in.is_open()) {
		cout << "Unable to open file" << endl;
		return;
	}
	else {
		for (int i = 0; i < 5; i++){
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 6; x++) {
					char c;
					in >> c;
					f[i].Set(x, y, c);
				}
			}
		}
	}
	in.close();
}