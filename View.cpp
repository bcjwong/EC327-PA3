#include <iostream>
using namespace std;
#include "View.h"

//View constructor
View::View(){
	size = 11;
	scale = 2;
	origin = Cart_Point(0, 0);

}

//Gets the subscripts
bool View::get_subscripts(int &ix, int &iy, Cart_Point location){
	ix = ((location.x - origin.x) / scale);
	iy = ((location.y - origin.y) / scale);

	if(ix > size || iy > size || ix < 0 || iy < 0)
	{
		cout << "An object is outside the display." << endl;
		return false;
	}
	else
	{
		return true;
	}

}

//Sets the grid to the default pattern
void View::clear(){
	for(int i = 0; i < view_maxsize; i++)
	{
		for(int j = 0; j < view_maxsize; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}

}

//Plots the object in the proper place
//Calls the drawself to insert the characters in the cell
//If there is already a character, replaces it with * and ' '
void View::plot(Game_Object * ptr){
	int ix;
	int iy;
	if(get_subscripts(ix, iy, ptr->get_location()))
	{
		if(grid[ix][iy][0] != '.')
		{
			grid[ix][iy][0] = '*';
			grid[ix][iy][1] = ' ';
		}
		else
			ptr->drawself(grid[ix][iy]);
	}
	

}

//Outputs the grid and the axis
void View::draw(){
	int t = view_maxsize;
	for (int y = (size-1); y >= 0; y--)
	{
		if (t%4 == 0)
		{
			cout << t;
			if (t < 10)
				cout << " ";
		}
		else
		{
			cout << "  ";
		}
		for(int x = 0; x < size; x++)
		{
			cout << grid[x][y][0];
			cout << grid[x][y][1];
		}
		t = t-2;
		cout << endl;
	}
	
	cout << "  ";
	
	int y = 0;
	for (int i = 0; i <= (size/2); i++)
	{
		if(y < 10)
		{
			cout << " ";
		}
		{
			cout << y << "  ";
		}
		y = y + 4;
	}
	cout << endl;

	
}
