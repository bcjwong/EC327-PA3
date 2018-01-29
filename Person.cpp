#include <iostream>
#include <math.h>
using namespace std;
#include "Person.h"


//Default constructor for person
Person::Person() : Game_Object('p'){
	speed = 5.0;
	cout << "Person default constructed" << endl;

}

//Constructor for person
Person::Person(char in_code) : Game_Object(in_code){
	speed = 5.0;
	cout << "Person constructed" << endl;

}


Person::Person(Cart_Point in_loc, int in_id, char in_code)
	: Game_Object(in_loc, in_id, in_code){
	speed = 5.0;
	cout << "Person constructed" << endl;

}

//Person destructor
Person::~Person(){
	cout << "Person destructed" << endl;

}


//Updates location of the person
bool Person::update_location(){
	if(fabs((destination-location).x) <= fabs(delta.x)
		&& fabs((destination-location).y) <= fabs(delta.y))
		{
			location = destination;
			cout << display_code << id_num << ": I'm there!" << endl;
			return true;
		}
	else
		{
			location.x = location.x + delta.x;
			location.y = location.y + delta.y;
			cout << display_code << id_num << ": step..." << endl;
			return false;
		}

}

//Sets the destination of the person
void Person::setup_destination(Cart_Point dest){
	destination = dest;
	delta = (destination - location) * (speed/cart_distance(destination,location));

	
}

//Sets the person into moving state
void Person::start_moving(Cart_Point dest){
	
	if(state != 'l')
	{
		if((dest.x == location.x) && (dest.y == location.y))
		{	
			cout << "Moving " << id_num << " to " << dest << endl;
			cout << "I'm already there. see?" << endl;
		}
		else
		{	
		setup_destination(dest);
		state = 'm';
	
		cout << "Moving " << id_num << " to " << dest << endl;
		cout << display_code << id_num << ": On my way." << endl;
		}
	}
	else
	{
		cout << "Cannot move, I'm locked" << endl;
	}

}

//Stops the person
void Person::stop(){
	state = 's';
	cout << "Stopping " << id_num << endl;
	cout << display_code << id_num << ": All right." << endl;

}

//Show status of the person
void Person::show_status(){
	Game_Object::show_status();

	if (state == 's')
		cout << " is stopped ";
	if (state == 'l')
		cout << " is locked ";
	if (state == 'm' || state == 'o' || state == 'i' || state == 'd' || state == 'g')
		cout << " moving at speed " << speed << " towards " << destination << " at each step of " << delta;
}


void Person::start_supplying(Oxygen_Depot* inputDepot){
	cout << "Sorry, I can't work a depot." << endl;

}

void Person::start_depositing(Space_Station* inputStation){
	cout << "Sorry, I can't work a station." << endl;

}

void Person::go_to_station(Space_Station* inputStation){
	cout << "Sorry, I can't lock into a station." << endl;

}
