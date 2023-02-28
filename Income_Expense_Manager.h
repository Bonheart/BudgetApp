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
    Date date;
    Income_File income_file;
    Expense_File expense_file;
    int logged_user_id; // to wpieprzyc w constansa

    public:

    Income_Expense_Manager(string income_file_name,string expense_file_name, int logged_user_id) : income_file(income_file_name),expense_file(expense_file_name), logged_user_id(logged_user_id) {

        incomes = income_file.load_income_from_file(logged_user_id);
     //   expenses = expense_file.load_expenses_from_file(logged_user_id);

    };
    int get_new_income_id();
    void add_new_income();
    int get_new_expense_id();
    void add_new_expense();




  //  void display_income(int logged_user_id);


};







#endif // INCOME_EXPENSE_MANAGER_H
