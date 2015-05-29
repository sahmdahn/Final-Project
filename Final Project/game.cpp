#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>

#include "game.h"
#include "fstreams.h"

int instruct(char tmp, int z);

//Constructor
game::game(){
	x = 0;
	y = 1;
	z = 0;
	a = 0;
}

void game::Initial() {
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

void game::begin(){
	cout << "Your in the maze." << endl;
	cout << "Get out!" << endl;
	system("pause"); system("cls");

	for (int zCoord = 0; zCoord < 5; zCoord++){
		f[zCoord].Start(x, y);
	}

	do{

		direction();

	} while (a == 0);
}

//Testing the dir value to the array to see if the user can move that way
void game::direction(){
	char dir;
	dir = instruct(tmp, z);
	
	switch (dir){
	case 'w':
		if (f[z].CanMove(x, y - 1)){
			y--;
			cout << "You moved one space North." << endl;
			cout << endl;
			cout << endl;
			Sleep(500);
			HandleMove(x, y);
		}
		else{
			Sleep(500);
			cout << "There is a wall there." << endl;
			cout << endl;
			cout << endl;
		}
		break;
	case'a':
		if (f[z].CanMove(x - 1, y)){
			x--;
			cout << "You moved one space West." << endl;
			cout << endl;
			cout << endl;
			Sleep(500);
			HandleMove(x, y);
		}
		else{
			Sleep(500);
			cout << "There is a wall there." << endl;
			cout << endl;
			cout << endl;
		}
		break;
	case's':
		if (f[z].CanMove(x, y + 1)){
			y++;
			cout << "You moved one space South." << endl;
			cout << endl;
			cout << endl;
			Sleep(500);
			HandleMove(x, y);
		}
		else{
			Sleep(500);
			cout << "There is a wall there." << endl;
			cout << endl;
			cout << endl;
		}
		break;
	case'd':
		if (f[z].CanMove(x + 1, y)){
			x++;
			cout << "You moved one space East." << endl;
			cout << endl;
			cout << endl;
			Sleep(500);
			HandleMove(x, y);
		}
		else{
			Sleep(500);
			cout << "There is a wall there." << endl;
			cout << endl;
			cout << endl;
		}
		break;
	case '9':
		system("cls");
		cout << "You dirty little cheater >:)" << endl;
		cout << "You have been teleported to the end." << endl;
		TheEnd();
		break;

	default:
		cout << "That is not a valid input." << endl;
		cout << "You stupid." << endl;
		cout << endl;
		cout << endl;

		break;
	}
}

//User input for direction
int instruct(char tmp, int z){
	cout << "FLOOR " << z + 1 << endl;
	cout << "Choose a direction: " << endl;
	cout << "w = North	" << "a = West	" << "s = South	" << "d = East	" << endl;;
	cin >> tmp;
	return tmp;
}

//Testing the value
bool Floor::CanMove(int x, int y){
	if (x < 0 || x>5){
		return false;
	}
	else if (y < 0 || y>5){
		return false;
	}
	else if (map[x][y] == '*'){
		return false;
	}
	else{
		return true;
	}
}

//Handles the users input to see if they can move their on the map
void game::HandleMove(int newx, int newy){
	x = newx;
	y = newy;

	switch (f[z].Get(x, y)){
	case '1':
		system("cls");
		cout << "You are now on FLOOR 1." << endl;
		z = 0;
		break;
	case '2':
		system("cls");
		cout << "You are now on FLOOR 2." << endl;
		z = 1;
		break;
	case '3':
		system("cls");
		cout << "You are now on FLOOR 3." << endl;
		z = 2;
		break;
	case '4':
		system("cls");
		cout << "You are now on FLOOR 4." << endl;
		z = 3;
		break;
	case '5':
		system("cls");
		cout << "You are now on FLOOR 5." << endl;
		z = 4;
		break;
	case'S':
		system("cls");
		cout << "Your back at the start :(." << endl;
		break;
	case 'E':
		if (TheEnd()){
			z = 0;
			int xTemp = -1, yTemp = -1;
			for (int zCoord = 0; zCoord < 5; zCoord++){
				f[zCoord].Start(xTemp, yTemp);
				if (xTemp != -1) {
					x = xTemp;
					y = yTemp;
					z = zCoord;
					break;
				}
				else{
					cout << "System Error!" << endl;
					cout << "&(*^UI&*F^*$Giy7t%KJ&^%^45**&kt5^F^" << endl;
				}
			}
		}
		break;
	}
};

bool game::TheEnd() {
	char c;

	do{
		cout << "CONGRATULATIONS!!! You have reached the END!!!" << endl;
		cout << "Try again [Y/N]?" << endl;
		cin >> c;
		system("cls");

		if (c == 'y'){
			begin();
		}
		else if (c == 'n'){
			cout << "You have chosen to exit the game." << endl;
			cout << "Thanks for playing!" << endl;
			system("pause");
			a = 1;
			return false;
		}
		else{
			cout << "Invalid Input." << endl;
			Sleep(500); system("cls");
		}
	} while (c != 'y' || c != 'n');
}
