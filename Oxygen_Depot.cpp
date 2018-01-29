#include <iostream>
#include "Oxygen_Depot.h"
using namespace std;

//Default constructor for oxygen depot
Oxygen_Depot::Oxygen_Depot() : Game_Object('O'){
    state = 'f';
    cout << "Oxygen_Depot default constructed." << endl;
    amount_oxygen = 50;
    
}

//Constructor for oxygen depot
Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId)
    : Game_Object(inputLoc, inputId, 'O') {
    cout << "Oxygen_Depot constructed." << endl;
    amount_oxygen = 50;

}

//Destructor for oxygen depot
Oxygen_Depot::~Oxygen_Depot(){
	cout << "Oxygen Depot destructed" << endl;

}


//Checks to see if oxygen depot is empy
bool Oxygen_Depot::is_empty(){
    if (amount_oxygen == 0)
        return true;
    else
        return false;

}
   
//Extracts oxygen from depot
double Oxygen_Depot::extract_oxygen(double amount_to_extract){
    if (amount_oxygen >= amount_to_extract)
    {
        amount_oxygen -= amount_to_extract;
        return amount_to_extract;
    }
    else
    {
        double temp = amount_oxygen;
        amount_oxygen = 0;
        return temp; 
    }
}

//Updates oxygen depot
bool Oxygen_Depot::update(){
    if (amount_oxygen == 0 && display_code != 'o')
    {
        state = 'e';
        display_code = 'o';
        cout << "Oxygen_Depot (" << id_num << ") has been depleted" << endl;
        return true;
    }
    else 
        return false;

}

//Show status for oxygen depot
void Oxygen_Depot::show_status(){
    cout << "Oxygen Depot status: "; 
    cout << display_code << id_num << " at location " << location << " contains " 
    << amount_oxygen << "." << endl;

}
 
    




