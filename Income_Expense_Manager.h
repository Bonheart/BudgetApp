#ifndef INCOME_EXPENSE_MANAGER_H
#define INCOME_EXPENSE_MANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Income_file.h"
#include "Date.h"
#include "Helpful_Methods.h"
#include "Expense.h"
#include "Expense_file.h"
#include "Balance.h"

using namespace std;

class Income_Expense_Manager{

    vector <Income> incomes;
    vector <Expense> expenses;
    Expense add_info_about_expense();
    Income add_info_about_income();
    Date date;
    Income_File income_file;
    Expense_File expense_file;
    Balance balance;
    const int LOGGED_USER_ID; // to wpieprzyc w constansa

    public:

    Income_Expense_Manager(string income_file_name,string expense_file_name, int logged_user_id) : income_file(income_file_name),expense_file(expense_file_name), LOGGED_USER_ID(logged_user_id) {

        incomes = income_file.load_income_from_file(LOGGED_USER_ID);
        expenses = expense_file.load_expenses_from_file(LOGGED_USER_ID);

    };
    int get_new_income_id();
    void add_new_income();
    int get_new_expense_id();
    void add_new_expense();
    void display_current_months_balance();
    void display_last_months_balance();
    void display_selected_period_of_time_balance();

};

#endif // INCOME_EXPENSE_MANAGER_H
