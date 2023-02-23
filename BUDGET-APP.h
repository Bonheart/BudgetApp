#ifndef BUDGET_APP_H
#define BUDGET_APP_H

#include <iostream>

#include "User_Manager.h"
#include "Users_file.h"
#include "Helpful_Methods.h"
#include "Date.h"
#include "Income.h"

using namespace std;

class Budget_App{

    User_Manager user_manager;
    Date date;
    Income *income;


public:
    Budget_App(string users_file_name) : user_manager(users_file_name){

        income = NULL;

    };

    ~Budget_App(){

    delete income;
    income - NULL;
    };

    void user_registration();
    void user_login();
    char select_option_from_main_menu();
    char select_option_from_users_menu();
    int logged_user_id;
    void user_logout();
    void change_users_password();

    void display_date();

    bool check_if_user_is_logged();


};

#endif // BUDGET_APP_H
