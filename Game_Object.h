#ifndef Game_Object_h
#define Game_Object_h
#include "Cart_Point.h"

class Game_Object{
public:
	Game_Object(char);
	Game_Object(Cart_Point, int, char);
	virtual bool update() = 0;
	Cart_Point get_location();
	int get_id();
	char get_state();
	virtual void show_status();
	virtual ~Game_Object();
	void drawself(char* ptr);


protected:
	Cart_Point location;
	int id_num;
	char display_code;
	char state;

};

#endif
