#include <iostream>
#include <cmath>
using namespace std;
#include "Cart_Point.h"



Cart_Point::Cart_Point(){
	x = 0.0;
	y = 0.0;

}

Cart_Point::Cart_Point(double inputx, double inputy){
	x = inputx;
	y = inputy;

}


double cart_distance(Cart_Point p1, Cart_Point p2){
	double xdist = p1.x - p2.x;
	double ydist = p1.y - p2.y;
	double dist = sqrt(pow(xdist, 2) + pow(ydist, 2));
	return dist;
}

ostream& operator<<(ostream& outputStream, const Cart_Point& obj)
{
	outputStream << "(" << obj.x << ", " << obj.y << ")";
	return outputStream;
}

Cart_Point operator+(const Cart_Point& p1, const Cart_Vector& v1)
{
	double x, y;
	x = p1.x + v1.x;
	y = p1.y + v1.y;
	return Cart_Point(x, y);
}

Cart_Vector operator-(const Cart_Point& p1, const Cart_Point& p2)
{
	double x, y;
	x = p1.x - p2.x;
	y = p1.y - p2.y;
	return Cart_Vector(x, y);
}





		
