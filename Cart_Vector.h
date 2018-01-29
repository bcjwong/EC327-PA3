#ifndef cartVector_h
#define cartVector_h

#include <iostream>
class Cart_Vector{
public:
	double x, y;
	Cart_Vector();
	Cart_Vector(double, double);
	
};

Cart_Vector operator*(const Cart_Vector& v1, double d);

Cart_Vector operator/(const Cart_Vector& v1, double d);

std::ostream& operator<<(std::ostream& outputStream, const Cart_Vector& obj);

#endif



