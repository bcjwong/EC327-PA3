#include <iostream>
using namespace std;
#include "Astronaut.h"

//Default constructor
Astronaut::Astronaut() : Person('A'){
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	cout << "Astronaut default constructed" << endl;
	checker = 0;

}

//Constructor for astronaut
Astronaut::Astronaut(int in_id, Cart_Point in_loc) 
	: Person(in_loc, in_id, 'A'){
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	cout << "Astronaut constructed" << endl;
	checker = 0;
}

//Destructor for astronaut
Astronaut::~Astronaut(){
	cout << "Astronaut destructed" << endl;

}

//All update states for astronaut
bool Astronaut::update(){
	//cout << "ASTRONAUT UPDATE STATE is: " << state<< endl;
	switch(state){
		case 's':
			return false;
			break;
		case 'm':
		if (amount_oxygen <= 0)
		{
			cout << "I can't move, I'm out of oxygen." << endl;
			state = 'l';
			return false;
		}
		else
		{
			if (update_location())
			{
				state = 's';
				return true;
			}
			else
			{
				amount_moonstones += 1;
				amount_oxygen -= 1;
				return false;
				
			}
		}
		break;
		case 'o':
		if (amount_oxygen <= 0)
		{
			cout << "I can't move, I'm out of oxygen." << endl;
			state = 'l';
			return false;
		}
		else
		{
			if (update_location())
			{
				
				state = 'g';
				return true;
			}
			else
			{
				amount_moonstones += 1;
				amount_oxygen -= 1;
				return false;
			}
		}
		break;
		case 'g':
		{
			double amount_extracted = depot->extract_oxygen();
			cout << display_code << id_num << ": Got " << amount_extracted << " oxygen." << endl;
			state = 's';
			amount_oxygen += amount_extracted;
			return true;
			break;
		}
		case 'i':
		if (amount_oxygen <= 0)
		{
			cout << "I can't move, I'm out of oxygen." << endl;
			state = 'l';
			return false;
		}
		else
		{
			if(Person::update_location())
			{
				state = 'd';
				return true;
			}
			else
			{
				amount_moonstones += 1;
				amount_oxygen -= 1;
				return false;
			}
		}
		break;
		case 'd':
			cout << display_code << id_num << ": Deposit " << amount_moonstones << " moonstones." << endl;
			home->deposit_moonstones(amount_moonstones);
			amount_moonstones = 0;
			state = 's';
			return true;
			break;
		case 'l':
		if (amount_oxygen <= 0)
		{
			cout << "I can't move, I'm out of oxygen." << endl;
			return false;
		}
		else
		{
			if(Person::update_location())
			{
				if(checker == 0){
					home->add_astronaut();
					checker++;
				}
				return true;
			}
			else
			{
				amount_moonstones += 1;
				amount_oxygen -= 1;
				return false;
			}
		break;
		}
	}

}

//Astronaut starts supplying at an oxygen depot
void Astronaut::start_supplying(Oxygen_Depot* inputDepot){
	depot = inputDepot;
	setup_destination(depot->get_location());
	state = 'o';
	cout << "Astronaut " << id_num << " supplying at Oxygen Depot " << inputDepot->get_id() << endl;
	cout << display_code << id_num << ": Yes, my lord." << endl;
	
}

//Astronaut starts depositing at space station
void Astronaut::start_depositing(Space_Station* inputStation){
	home = inputStation;
	setup_destination(home->get_location());

	state = 'i';
	cout << "Astronaut " << id_num << " depositing to Space Station " << inputStation->get_id() << endl;
	cout << display_code << id_num << ": Yes, my lord." << endl;

}

//Astronaut locking into a space station
void Astronaut::go_to_station(Space_Station* inputStation){
	home = inputStation;
	state = 'l';
	cout << "Astronaut " << id_num << " locking in at Space Station " << inputStation->get_id() << endl;
	setup_destination(home->get_location());
	

}

//Show status for astronaut
void Astronaut::show_status(){
	cout << "Astronaut status: ";
	Person::show_status();
	switch(state){
		case 's':
			cout << " with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
			break;
		case 'o':
			cout << " is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
			break;
		case 'g':
			cout << " getting oxygen from Depot." << endl;
			break;
		case 'i':
			cout << " is inbound to home with load: " << amount_moonstones << " moon stones and " << amount_oxygen << " oxygen." << endl;
			break;
		case 'd':
			cout << " is depositing " << amount_moonstones << " moon stones." << endl;
			break;
		case 'l':
			if(amount_oxygen > 0)
				cout << "at Space Station." << endl;
			else
				cout << "Out of oxygen." << endl;
			break;
			

	}

	
	

}



