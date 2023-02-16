#ifndef BUDGET_APP_H
#define BUDGET_APP_H

#include <iostream>

#include "User_Manager.h"
#include "Users_file.h"
#include "Helpful_Methods.h"

using namespace std;

class Budget_App{

    User_Manager user_manager;


public:
    Budget_App(string users_file_name) : user_manager(users_file_name){};
    void user_registration();
    void user_login();
    char select_option_from_users_menu();



};

#endif // BUDGET_APP_H
