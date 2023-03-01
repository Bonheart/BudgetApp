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

public:

};



#endif // BALANCE_H
