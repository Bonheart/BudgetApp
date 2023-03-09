#ifndef BUDGET_APP_H
#define BUDGET_APP_H

#include <iostream>

#include "User_Manager.h"
#include "Helpful_Methods.h"
#include "Income_Expense_Manager.h"
#include "Balance.h"

using namespace std;

class Budget_App{

    User_Manager user_manager;
    Income_Expense_Manager *income_expense_manager;
    Balance balance;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;


public:
    Budget_App(string users_file_name, string income_file_name, string expense_file_name) : user_manager(users_file_name),INCOME_FILE_NAME(income_file_name),EXPENSE_FILE_NAME(expense_file_name) {

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
    void add_expense();

    void display_date();
    void display_incomes();

    bool check_if_user_is_logged();

    void display_current_months_balance();
    void display_last_months_balance();
    void display_selected_period_of_time_balance();

};

#endif // BUDGET_APP_H
