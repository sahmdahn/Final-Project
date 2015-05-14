#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "fstreams.h"

using namespace std;

void main(){
	Floor f[5];
	

	fstream in;
	in.open("map.txt", ios::in);
	for (int i = 0; i < 5; i++){
		f[i].readin(in);
	}
	in.close();
		





	/*

	block *pos = NULL, *map = new block();

	block *row = map;
	for (int r = 0; r < 5; r++){
		block *col = row;
		block*up = row;
		for (int c = 0; c < 5; c++){

			block *left = col;
			col->setRight(new block());
			col -= col->getRight();
			col->setLeft(left);

			if (left->getUp() != NULL){
				left->getUp()->setDown(left);
			}
		}
		row->setDown(new block());
		row = row->getDown();
	}

	for (block *row = map; row->getDown() != NULL; row = row->getDown()){
		for (block *col = map; col->getRight() != NULL; col = row->getRight()){
			if (col->isWall()){
				cout << "|";
			}
			else{
				cout << "_";
			}
		}
		cout < endl;
	}



	int numbers[5];
	int * p;

	p = numbers;

	for (int n = 0; n < 5; n++){
		numbers[n] = *p*(n + 1);
		cout << endl;
		cout << numbers[n] << ", ";
	}
	  *p = 10;
	p++;  *p = 20;
	p = &numbers[2];  *p = 30;
	p = numbers + 3;  *p = 40;
	p = numbers;  *(p + 4) = 50;
	for (int n = 0; n<5; n++)
		cout << numbers[n] << ", ";
	return 0;*/
	system("pause");

}
