#include "BUDGET-APP.h"


void Budget_App::user_registration(){

    user_manager.user_registration(); // already have object "user_manager" of "User_Manager" class in BUDGET-APP.h as private set, so I can operate on object

}

void Budget_App::user_login(){

    user_manager.user_login();
 //   date.get_current_data_from_PC();
 //   date.entering_manual_date();

}

char Budget_App::select_option_from_main_menu(){

    return Helpful_Methods::select_option_from_main_menu();

}

char Budget_App::select_option_from_users_menu(){

    return Helpful_Methods::select_option_from_users_menu();

}

bool Budget_App::check_if_user_is_logged(){

    return user_manager.check_if_user_is_logged();
}


void Budget_App::user_logout(){

    user_manager.user_logout();

}

void Budget_App::change_users_password(){

    user_manager.change_users_password();

}
