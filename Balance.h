#ifndef BALANCE_H
#define BALANCE_H


#include <iostream>
#include <vector>
#include <iomanip>

#include "Helpful_Methods.h"
#include "Date.h"
#include "Income.h"
#include "Expense.h"


using namespace std;

class Balance {

    Date date;
    Income income;
    Expense expense;
    vector <Income> incomes;
    vector <Expense> expenses;

   struct sort_by_income_date {

        inline bool operator() (Income &first_date, Income &second_date){
            return (first_date.get_date_in_int() < second_date.get_date_in_int());
        }
    };

    struct sort_by_expense_date{

        inline bool operator() (Expense &first_date, Expense &second_date){
            return (first_date.get_expense_date_int() < second_date.get_expense_date_int());
        }
    };

public:
    float current_month_income( Income income);
    float current_month_expense( Expense expense);
    void sort_income(Income income);
    void sort_expense(Expense expense);
    void display_current_months_balance (vector <Income> incomes, vector <Expense> expenses);
    void display_info_about_incomes(vector <Income> incomes);
    void display_info_about_expenses(vector <Expense> expenses);
    float calculate_last_month_income(Income income);
    float calculate_expense_of_last_month(Expense expense);
    void display_last_month_balance(vector <Income> incomes, vector <Expense> expenses);
    void display_incomes();
    float calculate_selected_period_of_time_incomes(Income income,int beggining_date_int, int ending_date_int);
    float calculate_selected_period_of_time_expenses(Expense expense,int beggining_date_int, int ending_date_int);
    void display_selected_period_of_time_balance(vector <Income> incomes, vector <Expense> expenses);
};



#endif // BALANCE_H
