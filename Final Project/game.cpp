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
	system("pause"); system("cls");

	int a = 0;

	do{
		
		direction();
		system("pause"); system("cls");

	} while (a == 0);
}

//} while (x!=xEnd && y!=yEnd, x!=zEnd)

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
			cout << "There is a wall there." << endl;
		}
		
		break;
	case'a':
		if(f[z].CanMove(x - 1, y)){
			cout << "You moved one space East." << endl;
			x--;
		}
		else{
			cout << "There is a wall there." << endl;
		}
		break;
	case's':
		if (f[z].CanMove(x, y - 1)){
			cout << "You moved one space South." << endl;
			y--;
		}
		else{
			cout << "There is a wall there." << endl;
		}
		break;
	case'd':
		if (f[z].CanMove(x + 1, y)){
			cout << "You moved one space West." << endl;
			x++;
		}
		else{
			cout << "There is a wall there." << endl;
		}
		break;
	default:
		cout << "That is not a valid input." << endl;
		cout << "You stupid." << endl;
		break;
	}
}
