#ifndef View_h
#define View_h
#include "Cart_Point.h"
#include "Game_Object.h"

const int view_maxsize = 20;

class View{


public:
	View();
	void clear();
	void plot(Game_Object *);
	void draw();


private:
	int size;
	double scale;
	Cart_Point origin;
	char grid[20][20][2];
	bool get_subscripts(int &, int &, Cart_Point);


};

#endif
