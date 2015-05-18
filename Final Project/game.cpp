#include <string>
#include <fstream>
#include <iomanip>

#include "game.h"
#include "fstreams.h"

game::game(){
	x = -1;
	y = -1;
	z = -1;
}

void game::begin(){
	cout << "Your in maze." << endl;
	cout << "Get the f*$%" << endl;
}


//User input for direction
cout << "Choose a direction: " << endl;
cout << "(w,a,s,d)" << endl;
cin >> dir;


void game::direction(){

}
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
