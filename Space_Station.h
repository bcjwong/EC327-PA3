#include <iostream>
#ifndef Space_Station_h
#define Space_Station_h
#include "Cart_Point.h"
#include "Game_Object.h"

class Space_Station : public Game_Object{
private:
	double amount_moonstones;
	int number_astronauts;
	
	
public: 
	Space_Station();
	Space_Station(Cart_Point, int);
	void deposit_moonstones(double);
	bool add_astronaut();
	int get_astronauts();
	bool update();
	void show_status();
	~Space_Station();
	
};


#endif
