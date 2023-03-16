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

using namespace std;

class Income_Expense_Manager{

    vector <Income> incomes;
    vector <Expense> expenses;
    Expense add_info_about_expense();
    Income add_info_about_income();
    Expense_File expense_file;
    Income_File income_file;

    float incomes_sum(int beginning_date, int ending_date);
    float expenses_sum(int beginning_date, int ending_date);

    int get_new_income_id();
    int get_new_expense_id();
    const int LOGGED_USER_ID;

    public:

    Income_Expense_Manager(string expense_file_name, string income_file_name, int logged_user_id) : expense_file(expense_file_name), income_file(income_file_name), LOGGED_USER_ID(logged_user_id) {

<<<<<<< HEAD
        expenses = expense_file.load_expenses_from_file(LOGGED_USER_ID);
        incomes = income_file.load_income_from_file(LOGGED_USER_ID);
=======
<<<<<<< HEAD
        incomes = income_file.load_income_from_file(logged_user_id);
        expenses = expense_file.load_expenses_from_file(logged_user_id);
=======
        expenses = expense_file.load_expenses_from_file(LOGGED_USER_ID);
        incomes = income_file.load_income_from_file(LOGGED_USER_ID);
>>>>>>> feature_balance
>>>>>>> 98d62c06fa3499d15b8ad334881ba3667a2e50ef

    };

    void add_new_income();
    void add_new_expense();
    void display_current_months_balance();
    void display_last_months_balance();
    void display_selected_period_of_time_balance();
};

#endif // INCOME_EXPENSE_MANAGER_H
