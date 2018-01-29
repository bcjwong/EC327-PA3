#include <iostream>
#include <cmath>
using namespace std;
#include "Cart_Vector.h"

Cart_Vector::Cart_Vector(){
	x = 0.0;
	y = 0.0;

}

Cart_Vector::Cart_Vector(double inputx, double inputy){
	x = inputx;
	y = inputy;

}

Cart_Vector operator*(const Cart_Vector& v1, double d)
{
	double x, y;
	x = v1.x * d;
	y = v1.y * d;
	return Cart_Vector(x, y);
}

Cart_Vector operator/(const Cart_Vector& v1, double d)
{
	double x, y;
	if ( d == 0)
		return Cart_Vector(v1.x, v1.y);
	x = v1.x / d;
	y = v1.y / d;
	return Cart_Vector(x, y);
}

ostream& operator<<(ostream& outputStream, const Cart_Vector& obj)
{
	outputStream << "<" << obj.x << ", " << obj.y << ">";
	return outputStream;
}




