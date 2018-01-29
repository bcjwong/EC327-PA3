#include <iostream>
using namespace std;
#include "Model.h"
#include <cstdlib>


//Model constructor
Model::Model(){
	for (int i = 0; i < num_objects; i++)
	{
		object_ptrs[i] = NULL;
	}
	
	time = 0;
	count_down = 10;

	
	Person* a1 = new Astronaut(1, Cart_Point(5, 1));
	
	Person* a2 = new Astronaut(2, Cart_Point(10, 1));
	
	Oxygen_Depot* o1 = new Oxygen_Depot(Cart_Point(1, 20), 1);
	
	Oxygen_Depot* o2 = new Oxygen_Depot(Cart_Point(10, 20), 2);
	
	Space_Station* s1 = new Space_Station();
	
	Space_Station* s2 = new Space_Station(Cart_Point(5, 5), 2);
	
	object_ptrs[0] = a1;
	person_ptrs[0] = a1;
	object_ptrs[1] = a2;
	person_ptrs[1] = a2;
	object_ptrs[2] = o1;
	depot_ptrs[0] = o1;
	object_ptrs[3] = o2;
	depot_ptrs[1] = o2;
	object_ptrs[4] = s1;
	station_ptrs[0] = s1;
	object_ptrs[5] = s2;
	station_ptrs[1] = s2;
	
	
	
	num_objects = 6;
	num_persons = 2;
	num_depots = 2;
	num_stations = 2;
	
	cout << "Model default constructed" << endl;

	
	
}


//Model copy constructor
Model::Model(const Model& copy){
	time = copy.time;
	count_down = copy.count_down;
	num_objects = copy.num_objects;
	num_persons = copy.num_persons;
	num_depots = copy.num_depots;
	num_stations = copy.num_stations;
	
	for (int i = 0; i < num_objects; i++)
	{
		object_ptrs[i] = copy.object_ptrs[i];
		person_ptrs[i] = copy.person_ptrs[i];
		depot_ptrs[i] = copy.depot_ptrs[i];
		station_ptrs[i] = copy.station_ptrs[i];
	}
	
}

	
	
//Model destructor
Model::~Model(){
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}

	cout << "Model destructed" << endl;
	
}

//Gets person pointer if its valid
Person* Model::get_Person_ptr(int id){
	for (int i = 0; i < num_persons; i++)
	{
		if (person_ptrs[i]->get_id() == id)
			return person_ptrs[i];
	}
	return 0;

}

//Gets oxygen pointer if its valid
Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id){
	for (int i = 0; i < num_depots; i++)
	{
		if (depot_ptrs[i]->get_id() == id)
			return depot_ptrs[i];
	}
	return 0;

}

//Gets space station pointer if its valid
Space_Station* Model::get_Space_Station_ptr(int id){
	for (int i = 0; i < num_stations; i++)
	{
		if(station_ptrs[i]->get_id() == id)
			return station_ptrs[i];
	}
	return 0;
}


//Checks takeoff condition and updates all objects
bool Model::update(){
	time++;
	if (count_down == 0)
	{
		cout << "You lose!" << endl;
		exit(0);
	}
	else
	{
	int readyStation = 0;
	
	
	if(station_ptrs[0]->get_state() == 'u' && station_ptrs[1]->get_state() == 'u')
	{
		cout << "Ready for takeoff? " << count_down << "..." << endl;
		int leftAstro = num_persons - (station_ptrs[0]->get_astronauts() + station_ptrs[1]->get_astronauts());
		if(station_ptrs[0]->get_astronauts() && station_ptrs[1]->get_astronauts() && (station_ptrs[0]->get_astronauts() + station_ptrs[1]->get_astronauts()) == num_persons)
		{
			cout << "Blast Off! You win!" << endl;
			exit(0);
		}
		else
		{
			cout << "Missing " << leftAstro << " Astronauts!" << endl;
			count_down--;
		}
		
	}			 
	
	
	update_check = 0;
	for (int i = 0; i < num_objects; i++)
	{
		
		if(object_ptrs[i]->update())
		{
			update_check++;
		}	
	}
	if(update_check > 0)
		return true;
	
	}

}

//Displays the grid
void Model::display(View &view){
	view.clear();
	for (int i = 0; i < num_objects; i++)
	{
		view.plot(object_ptrs[i]);
	}
	view.draw();
	
}

//Show status of all the objects
void Model::show_status(){
	cout << "Time: " << time << endl;
	for (int i = 0; i < num_objects; i++)
		object_ptrs[i]->show_status();
	
}

		










