#include <iostream>
#include "Space_Station.h"
using namespace std;


//Default Constructor for space station
Space_Station::Space_Station() : Game_Object('s'){
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station default constructed" << endl;
	
}

//Constructor for space station
Space_Station::Space_Station(Cart_Point inputLoc, int inputId) 
	: Game_Object(inputLoc, inputId, 's'){
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station constructed" << endl;

}

//Destructor for space station
Space_Station::~Space_Station(){
	cout << "Space Station destructed" << endl;

}

//Increments moonstones
void Space_Station::deposit_moonstones(double deposit_amount){
	amount_moonstones = amount_moonstones + deposit_amount;
	
}

//add one astronaut
bool Space_Station::add_astronaut(){
		number_astronauts++;

}

//gets number of astronauts
int Space_Station::get_astronauts(){
	return number_astronauts;
	
}

//Updates space station
bool Space_Station::update(){
	if ((amount_moonstones >= 10) && (state != 'u'))
	{
		state = 'u';
		display_code = 'S';
		cout << display_code << id_num << " has been upgraded." << endl;
		return true;
	}
	else
		return false;

}


//Show status for space station
void Space_Station::show_status(){
	cout << "Space Station status: ";
	Game_Object::show_status();
	if (state ==  'u')
		cout << " contains " << amount_moonstones << " moonstones and contains " << number_astronauts << " astronauts. Upgraded." << endl;
	else
		cout << " contains " << amount_moonstones << " moonstones and contains " << number_astronauts << " astronauts. Not yet upgraded." << endl;
}


	
		
	






	

	
	

