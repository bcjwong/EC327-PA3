#include <iostream>
#ifndef cartPoint_h
#define cartPoint_h
#include "Cart_Vector.h"


class Cart_Point{
public:
	double x, y;
	Cart_Point();
	Cart_Point(double, double);

};

double cart_distance(Cart_Point, Cart_Point);

std::ostream& operator<<(std::ostream&, const Cart_Point&);

Cart_Point operator+(const Cart_Point&, const Cart_Vector&);

Cart_Vector operator-(const Cart_Point&, const Cart_Point&);

#endif	
