#ifndef BALANCE_H
#define BALANCE_H


#include <iostream>
#include <vector>

#include "Helpful_Methods.h"
#include "Date.h"
#include "Income.h"
#include "Expense.h"


using namespace std;

class Balance {

    Date date;
    Income income;
    Expense expense;
    vector <Income> sorted_incomes;
    vector <Expense> sorted_expenses;

    float balance, income_sum, expense_sum;

    float calculate_income(int first_date_income, int second_date_income);
    float calculate_expense(int first_date_expense, int second_date_expense);

    vector <Income> sorted_incomes_vector(vector <Income> incomes);
    vector <Expense> sorted_expenses_vector(vector <Expense> expenses);


public:
    Balance(vector <Income> incomes, vector <Expense> expenses){

        balance = 0;
        income_sum = 0;
        expense_sum = 0;

      //  sorted_expenses = sorted_expenses_vector(expenses);
    }

    void display_current_months_balance(vector < Income > incomes, vector < Expense > expenses);
    void calculate_current_month();
};



#endif // BALANCE_H
