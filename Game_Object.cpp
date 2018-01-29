#include <iostream>
using namespace std;
#include "Game_Object.h"
#include "Cart_Vector.h"

//constructor for game object
Game_Object::Game_Object(char in_code){
	display_code = in_code;
	id_num = 1;
	state = 's';
	cout << "Game_Object constructed" << endl;
	
}

//constructor for game object
Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code){
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	state = 's';
	cout << "Game_Object constructed" << endl;

}

//Destructor for game object
Game_Object::~Game_Object(){
	cout << "Game_Object destructed" << endl;

}

//Gets location of the object
Cart_Point Game_Object::get_location(){
	return location;

}

//Gets id of the object
int Game_Object::get_id(){
	return id_num;

}

//Gets state of the object
char Game_Object::get_state(){
	return state;

}

//Show status for game object
void Game_Object::show_status(){
	cout << display_code << id_num << " at " << location;

}

//Sets the code for the object on the grid
void Game_Object::drawself(char* ptr){
	//ptr[1] = static_cast<char>(id_num + '0');
	ptr[0] = display_code;
	ptr[1] = char(id_num + '0');
}

 



