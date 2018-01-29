#include <iostream>
using namespace std;
#include "Game_Command.h"
#include <cstdlib>

//Start moving
void do_move_command(Model& model, View& view){
	int id, x, y;
	cin >> id >> x >> y ;
	

	Cart_Point loc = Cart_Point(x, y);
	
	if(model.get_Person_ptr(id))
	{
		Person* person_ptr = model.get_Person_ptr(id);
		person_ptr->start_moving(loc);

	}

	model.display(view);

}

//Starting supplying at a depot
void do_work_command(Model& model, View& view){
	int id1, id2;
	cin >> id1 >> id2;
	
	if(model.get_Person_ptr(id1) && model.get_Oxygen_Depot_ptr(id2))
	{
		Person* person_ptr = model.get_Person_ptr(id1);
		Oxygen_Depot* depot_ptr = model.get_Oxygen_Depot_ptr(id2);
		person_ptr->start_supplying(depot_ptr);
	}
	model.display(view);
	

}

//Start depositing at a space station
void do_deposit_command(Model& model, View& view){
	int id1, id2;
	cin >> id1 >> id2;
	if(model.get_Person_ptr(id1) && model.get_Space_Station_ptr(id2))
	{
		Person* person_ptr = model.get_Person_ptr(id1);
		Space_Station* station_ptr = model.get_Space_Station_ptr(id2);
		person_ptr->start_depositing(station_ptr);

	}
	model.display(view);

}

//Stop command
void do_stop_command(Model& model, View& view){
	int id;
	cin >> id;
	
	if(model.get_Person_ptr(id))
	{
		Person* person_ptr = model.get_Person_ptr(id);
		person_ptr->stop();
	}

}

//Locking to a space station
void do_lock_command(Model& model, View& view){
	int id1, id2;
	cin >> id1 >> id2;
	
	if(model.get_Person_ptr(id1) && model.get_Space_Station_ptr(id2))
	{
		Person* person_ptr = model.get_Person_ptr(id1);
		Space_Station* station_ptr = model.get_Space_Station_ptr(id2);
		person_ptr->go_to_station(station_ptr);
	}

	model.display(view);

}

//Advances one time step
void do_go_command(Model& model, View& view){
	cout << "Advancing one tick." << endl;

	model.update();

	model.show_status();
	model.display(view);


}

//Advance one step until update function returns true for at least one object, or 5 time steps have passed
void do_run_command(Model& model, View& view){
	cout << "Advancing to next event." << endl;

	int check = 0;
	int steps = 0;
	do{
		if(model.update())
		{
			check++;
		}
		steps++;

	}
	while(check == 0 && steps < 5);

	model.show_status();
	model.display(view);

}

//Quits the program
void do_quit_command(Model& model){
	cout << "Terminating program." << endl;
	model.~Model();
	exit(0);

}
