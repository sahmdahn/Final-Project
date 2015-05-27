#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>

#include "game.h"
#include "fstreams.h"

int instruct(char tmp, int z);

game::game(){
	x = 0;
	y = 1;
	z = 0;
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

	do{
		
		direction();

	} while (true);
}

//Testing the dir value to the array to see if the user can move that way
//Moving the user that way
void game::direction(){
	char dir;
	dir = instruct(tmp, z);
	
	switch (dir){
	case 'w':
		if (f[z].CanMove(x, y - 1)){
			y--;
			cout << "You moved one space North." << endl;
			HandleMove(x, y);
		}
		else{
			cout << "There is a wall there." << endl;
		}		
		break;
	case'a':
		if(f[z].CanMove(x - 1, y)){
			x--;
			cout << "You moved one space West." << endl;
			HandleMove(x, y);
		}
		else{
			cout << "There is a wall there." << endl;
		}
		break;
	case's':
		if (f[z].CanMove(x, y + 1)){
			y++;
			cout << "You moved one space South." << endl;
			HandleMove(x, y);
		}
		else{
			cout << "There is a wall there." << endl;
		}
		break;
	case'd':
		if (f[z].CanMove(x + 1, y)){
			x++;
			cout << "You moved one space East." << endl;
			HandleMove(x, y);
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
	system("pause"); system("cls");
}

int instruct(char tmp, int z){
	//User input for direction
	cout << "You are on floor " << z + 1 << endl;
	cout << "Choose a direction: " << endl;
	cout << "W = North	" << "A = West	" << "S = South	" << "D = East	" << endl;;
	cin >> tmp;
	return tmp;
}

/*Testing the value to make sure its not
biggger/smaller than the array
And that it doesnt hit a wall*/
bool Floor::CanMove(int x, int y){
	if (x < 0 || x>5){
		return false;
	}
	if (y < 0 || y>5){
		return false;
	}
	if (map[x][y] == '*'){
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
		cout << "You are now on floor one." << endl;
		z = 0;
		break;
	case '2':
		cout << "You are now on floor two." << endl;
		z = 1;
		break;
	case '3':
		cout << "You are now on floor three." << endl;
		z = 2;
		break;
	case '4':
		cout << "You are now on floor four." << endl;
		z = 3;
		break;
	case '5':
		cout << "You are now on floor five." << endl;
		z = 4;
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
					cout << "&(*^UI&*F^*$Giy7t%KJ&^%^45**&kt5^F^" << endl;
				}
			}
		}
		break;
	}
};

bool game::TheEnd() {
	char c;
	cout << "Try again [Y/N]?" << endl;
	cin >> c;
	system("cls");

	if (c == 'y'){
		return true;
	}
	else{
		cout << "You have chosen to exit the game." << endl;
		cout << "Thanks for playing!" << endl;
		return false;
	}
}
