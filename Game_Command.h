#include <iostream>
#ifndef Game_Command_h
#define Game_Command_h
#include "Model.h"



void do_move_command(Model&, View& );
 
void do_work_command(Model&, View& );

void do_deposit_command(Model&, View& );

void do_stop_command(Model&, View& );

void do_lock_command(Model&, View& );

void do_go_command(Model&, View& );

void do_run_command(Model&, View& );

void do_quit_command(Model& );



#endif
