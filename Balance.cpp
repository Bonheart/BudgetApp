#include "Balance.h"

void Balance::sort_income_balance(Income income){

    sort(incomes.begin(), incomes.end(), Income_sorter());
}

