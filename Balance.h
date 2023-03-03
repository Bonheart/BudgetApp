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
    vector <Income> incomes;
    vector <Expense> expenses;

    struct Income_sorter {

        inline bool operator() (Income &first_income_date,  Income &second_income_date) {

            return (first_income_date.get_date_in_int() < second_income_date.get_date_in_int());
        }
    };


    struct Expense_sorter {

        inline bool operator() (Expense &first_expense_date,  Expense &second_expense_date) {

            return (first_expense_date.get_expense_date_int() < second_expense_date.get_expense_date_int());
        }
    };

public:



    void sort_income_balance(Income income);
    void sort_expense_balance(Expense expense);
};



#endif // BALANCE_H
