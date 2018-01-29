#ifndef Astronaut_h
#define Astronaut_h
#include "Person.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"

class Astronaut : public Person{

public: 
	Astronaut();
	Astronaut(int in_id, Cart_Point in_loc);
	bool update();
	void start_supplying(Oxygen_Depot* );
	void start_depositing(Space_Station* );
	void go_to_station(Space_Station* );
	void show_status();
	int checker;
	~Astronaut();

private:
	double amount_moonstones;
	double amount_oxygen;
	Oxygen_Depot* depot;
	Space_Station* home;



};

#endif
