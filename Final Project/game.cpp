#include <string>
#include <fstream>
#include <iomanip>

#include "game.h"
#include "fstreams.h"

game::game(){
	x = 0;
	y = 1;
	z = 0;
}

void game::begin(){
	cout << "Your in the maze." << endl;
	cout << "Get the f*$% out!" << endl;
	system("pause");

	do{
		direction();

	} while (x!=xEnd && y!=yEnd, x!=zEnd)
}

//Testing the dir value to see if the user can move that way
void game::direction(){
	char dir;

	//User input for direction
	cout << "Choose a direction: " << endl;
	cout << "(w,a,s,d)" << endl;
	cin >> dir;

	switch (dir){
	case 'w':
		if (f[z].CanMove(x, y + 1)){
			y++;
			cout << "You moved one space North." << endl;
		}
		else{
			cout << "You stupid." << endl;
		}

		break;
	case'a':
		f[z].CanMove(x - 1, y);
	case's':
		f[z].CanMove(x, y - 1);
	case'd':
		f[z].CanMove(x + 1, y);
	}

}