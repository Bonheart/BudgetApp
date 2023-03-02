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
    vector <Income> incomes;
    vector <Expense> expenses;

    struct Income_sorter {

        inline bool operator() ( Income &first_date_income,  Income &second_date_income) {

            return (first_date_income.get_date_in_int() < second_date_income.get_date_in_int());
        }
    };

    struct Expense_sorter{

        inline bool operator () (Expense &first_date_expense, Expense &second_date_expense){

            return (first_date_expense.get_expense_date_int() < second_date_expense.get_expense_date_int());
        }

    };

public:

};


#endif // BALANCE_H
