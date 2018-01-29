#include <iostream>
#ifndef Oxygen_Depot_h
#define Oxygen_Depot_h
#include "Game_Object.h"
#include "Cart_Point.h"


class Oxygen_Depot : public Game_Object{

private:
	double amount_oxygen;

public:
	Oxygen_Depot();
	Oxygen_Depot(Cart_Point, int);
	bool is_empty();
	double extract_oxygen(double amount_to_extract = 20.0);
	bool update();
	void show_status();
	~Oxygen_Depot();
	
	
};

#endif
