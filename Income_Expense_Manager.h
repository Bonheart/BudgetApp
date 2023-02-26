#ifndef INCOME_EXPENSE_MANAGER_H
#define INCOME_EXPENSE_MANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Income_file.h"
#include "Date.h"
#include "Helpful_Methods.h"

using namespace std;

class Income_Expense_Manager{

    vector <Income> incoome;
    Income add_info_about_income();
    Date date;
    Income_File income_file;
    const int LOGGED_USER_ID;

    public:

    Income_Expense_Manager(string income_file_name, int logged_user_id) : income_file(income_file_name), LOGGED_USER_ID(logged_user_id) {};
    int get_new_income_id();
    void add_new_income();


};







#endif // INCOME_EXPENSE_MANAGER_H
