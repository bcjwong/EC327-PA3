#ifndef Model_h
#define Model_h
#include "Cart_Point.h"
#include "Person.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Astronaut.h"
#include "View.h"

class Model{

private:
    int time;
    int count_down;
    int update_check;
    
    Game_Object* object_ptrs[10];
    int num_objects;
    Person* person_ptrs[10];
    int num_persons;
    Oxygen_Depot* depot_ptrs[10];
    int num_depots;
    Space_Station* station_ptrs[10];
    int num_stations;
    Model(const Model& copy);

public:
    Model();
    ~Model();
    Person* get_Person_ptr(int );
    Oxygen_Depot* get_Oxygen_Depot_ptr(int );
    Space_Station* get_Space_Station_ptr(int );
    bool update();
    void display(View &);
    void show_status();


};

#endif
