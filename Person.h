#ifndef Person_h
#define Person_h
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"


class Person : public Game_Object{
public:
	Person();
	Person(char);
	Person(Cart_Point, int, char);
	void start_moving(Cart_Point);
	void stop();
	void show_status();
	virtual bool update() = 0;
	virtual void start_supplying(Oxygen_Depot* );
	virtual void start_depositing(Space_Station* );
	virtual void go_to_station(Space_Station* );

	virtual ~Person();

protected:
	bool update_location();
	void setup_destination(Cart_Point);

private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;

};

#endif
