#include <string>
#include <fstream>
#include <iomanip>

#include "game.h"
#include "fstreams.h"

int instruct(char tmp);

game::game(){
	x = 0;
	y = 1;
	z = 0;
	a = 0;
}

void game::begin(){
	cout << "Your in the maze." << endl;
	cout << "Get the f*$% out!" << endl;
	system("pause"); system("cls");

	do{
		
		direction();
		system("pause"); system("cls");

	} while (a == 0);
}

//} while (x!=xEnd && y!=yEnd, x!=zEnd)

//Testing the dir value to see if the user can move that way
void game::direction(){
	char dir;
	dir = instruct(tmp);
	

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

int instruct(char tmp){
	//User input for direction
	cout << "Choose a direction: " << endl;
	cout << "(w,a,s,d)" << endl;
	cin >> tmp;
	return tmp;
}

void game::HandleMove(int newx, int newy){
	x = newx;
	y = newy;

	switch (f[z].Get(x, y)){
	case 1:
		z = 1;
		break;
	case 2:
		z = 2;
		break;
	case 3:
		z = 3;
		break;
	case 4:
		z = 4;
		break;
	case 5:
		z = 5;
		break;
	case 'E':
		if (TheEnd()){
			z = 0;
			for (int zCoord = 0; zCoord < 5; zCoord++){
				int xTemp = -1, yTemp = -1;
				f[zCoord].Start(xTemp, yTemp);
				if (xTemp != -1) {
					x = xTemp;
					y = yTemp;
					z = zCoord;
					break;
				}
				else{
					cout << "System Error!" << endl;
					cout << "&(*^UI&*F^*$Giy7t%&&^%^%**&ktg6u5^F^" << endl;
				}
			}
		}
		else {
			//false
			a = 1;
			//x != xEnd && y != yEnd, x != zEnd)
		}
		break;
	}
}

bool game::TheEnd() {
	char c;
	cout << "Try again [Y/N]?" << endl;
	cin >> c;
	
	if (c == 'y'){
		return true;
	}
	else{
		cout << "You have chosen to exit the game." << endl;
		cout << "Thanks for playing!" << endl;
		return false;
	}
}