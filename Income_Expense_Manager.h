#ifndef INCOME_EXPENSE_MANAGER_H
#define INCOME_EXPENSE_MANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Date.h"

using namespace std;

class Income_Expense_Manager{

    const int LOGGED_USER_ID;
    vector <Income> incomes;
    Income add_info_about_income();
    Date date;

    public:

    Income_Expense_Manager();
    int get_new_income_id();
    void add_new_income();


};







#endif // INCOME_EXPENSE_MANAGER_H
