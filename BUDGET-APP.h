#ifndef BUDGET_APP_H
#define BUDGET_APP_H

#include <iostream>

#include "User_Manager.h"
#include "Users_file.h"
#include "Helpful_Methods.h"
#include "Date.h"
#include "Income.h"
#include "Income_Expense_Manager.h"
#include "Income_file.h"

using namespace std;

class Budget_App{

    User_Manager user_manager;
    Date date;
    Income income;
    Income_Expense_Manager *income_expense_manager;
    Income_File income_file;


public:
    Budget_App(string users_file_name) : user_manager(users_file_name) {

       income_expense_manager = NULL;

    };

    ~Budget_App(){

    delete income_expense_manager;
    income_expense_manager = NULL;
    };

    void user_registration();
    void user_login();
    char select_option_from_main_menu();
    char select_option_from_users_menu();
    int logged_user_id;
    void user_logout();
    void change_users_password();
    void add_income();

    void display_date();

    bool check_if_user_is_logged();


};

#endif // BUDGET_APP_H
