#include <iostream>
using namespace std;
#include "math.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"

int main()
{
	/*//Cart_Point/Cart_Vector test
	cout << "--------------CHECKPOINT 1--------------" << endl;
	Cart_Point p = Cart_Point();
	Cart_Point p1 = Cart_Point(1, 1);
	Cart_Point p2 = Cart_Point(3.14, 7.07);
	Cart_Point pDest = Cart_Point(10, 10);
	//cout << "CartPoint: " << p1 << endl;		
	
	Cart_Point p4 = Cart_Point(3, 7);
	Cart_Vector v1 = Cart_Vector(5, -2);
	Cart_Point addobj = p4 + v1;
	//cout << "Sum: " << addobj << endl;
	
	Cart_Point p5 = Cart_Point(5, -2);
	Cart_Vector subobj = p4 - p5;
	//cout << "Subtract: " << subobj << endl;	
	
	
	Cart_Vector v2 = Cart_Vector(10,20);
	Cart_Vector mulobj = v2 * 5;
	//cout << "Multiplication: " << mulobj << endl;
	
	Cart_Vector divobj = v2 / 5;
	//cout << "Division: " << divobj << endl;	
	
	
	//Game_Object test
	//Game_Object gobj(p1, 42, 'f');
	//cout << "get_location: " << gobj.get_location() << endl;
	//cout << "get_id: " << gobj.get_id() << endl;
	//cout << "get_state: " << gobj.get_state() << endl;
	//cout << endl;
	
	
	
	cout << "--------------CHECKPOINT 2--------------" << endl;
	//Oxygen_Depot test
	
	Cart_Point depotPoint = Cart_Point(10, 0);
	Cart_Point stationPoint = Cart_Point(0, 10);
	Oxygen_Depot oxyobj(depotPoint, 1);
	
	//cout << oxyobj.is_empty() << endl;
	//cout << oxyobj.extract_oxygen() << endl;
	oxyobj.update();
	
	oxyobj.show_status();
	

	Space_Station spaobj(stationPoint, 1);
	spaobj.show_status();
	
	spaobj.update();
	
	cout << "--------------ASTRONAUT TEST--------------" << endl;

	Astronaut astrobj(1, p);

	//ASK CREATE OXYGEN DEPOT OBJECT ON HEAP OR CAN JUST DO ADDRESS;
	Oxygen_Depot* depotPointer = &oxyobj;
	Space_Station* stationPointer = &spaobj;
	
	cout << "--------------ASTRONAUT START SUPPLYING TEST--------------" << endl;
	astrobj.show_status();
	astrobj.start_supplying(depotPointer);
	astrobj.update();
	astrobj.show_status();
	astrobj.update();
	astrobj.show_status();
	astrobj.update();
	astrobj.show_status();
	astrobj.update();
	astrobj.stop();
	astrobj.show_status();
	oxyobj.show_status();

	cout << "--------------ASTRONAUT START DEPOSITING TEST--------------" << endl;
	spaobj.show_status();
	astrobj.show_status();
	astrobj.start_depositing(stationPointer);
	astrobj.show_status();
	astrobj.update();
	astrobj.show_status();
	astrobj.update();
	astrobj.show_status();
	astrobj.update();
	astrobj.show_status();
	astrobj.update();
	spaobj.show_status();


	cout << "--------------ASTRONAUT GO TO STATION--------------" << endl;
	Cart_Point tenten = Cart_Point(10, 10);
	Space_Station spaobj2(tenten, 2);
	Space_Station* station2Pointer = &spaobj2;
	spaobj2.show_status();
	astrobj.show_status();
	astrobj.go_to_station(station2Pointer);
	astrobj.show_status();
	astrobj.update();
	astrobj.show_status();
	spaobj2.show_status();
	astrobj.update();
	astrobj.show_status();
	spaobj2.update();
	spaobj2.show_status();
	astrobj.update();
	spaobj2.show_status();

	cout << "--------------START MOVING--------------" << endl;
	Astronaut astrobj2(2, Cart_Point(0, 0));
	astrobj2.start_moving(Cart_Point(20, 20));
	astrobj2.show_status();
	astrobj2.update();
	astrobj2.stop();
	astrobj2.show_status();
	astrobj2.start_moving(Cart_Point(20, 20));
	astrobj2.show_status();
	astrobj2.update();
	astrobj2.stop();
	astrobj2.show_status();
	astrobj2.start_moving(Cart_Point(20, 20));
	astrobj2.show_status();
	astrobj2.update();
	astrobj2.show_status();
	astrobj2.update();
	astrobj2.show_status();
	astrobj2.update();
	astrobj2.show_status();
	astrobj2.update();
	astrobj2.show_status();

	*/
	
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2017" << endl;
	cout << "Programming Assignment 3" << endl;
	
	//Creates a model and view object
	//Shows the appropriate output
	Model mod;
	View view;
	mod.show_status();
	mod.display(view);
	
	char command = 'b';
	
	while(command != 'q'){
	
	
	//Asks the user for input and errorchecks
	
	cout << "Enter command: ";
	cin >> command;
	
		while(command != 'm' && command != 'w' && command != 'd' && command != 's' && command != 'l' && command != 'g' && command != 'r' && command != 'q'){
			cout << "ERROR: Please enter a valid command!" << endl;
			cout << "Enter command: ";
			cin >> command;
		} 


		switch(command)
		{
			case 'm':
				do_move_command(mod, view);
				break;
			case 'w':
				do_work_command(mod, view);
				break;
			case 'd':
				do_deposit_command(mod, view);
				break;
			case 's':
				do_stop_command(mod, view);
				break;
			case 'l':
				do_lock_command(mod, view);
				break;
			case 'g':
				do_go_command(mod, view);
				break;
			case 'r':
				do_run_command(mod, view);
				break;
			case 'q':
				do_quit_command(mod);
				break;
		}
	

	
	}
	cout << "Terminating program" << endl;
	



	
	
	
	return 0;
}


	
