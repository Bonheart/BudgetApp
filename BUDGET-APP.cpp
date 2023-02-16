#include "BUDGET-APP.h"


void Budget_App::user_registration(){

    user_manager.user_registration(); // already have object "user_manager" of "User_Manager" class in BUDGET-APP.h as private set, so I can operate on object

}

void Budget_App::user_login(){

    user_manager.user_login();

}

char Budget_App::select_option_from_main_menu(){

    return Helpful_Methods::select_option_from_main_menu();

}

char Budget_App::select_option_from_users_menu(){

    return Helpful_Methods::select_option_from_users_menu();

}
