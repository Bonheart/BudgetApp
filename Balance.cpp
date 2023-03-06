#include "Balance.h"

bool lower_expense( Expense first_expense_date, Expense second_expense_date){

    return first_expense_date.get_expense_date_int() < second_expense_date.get_expense_date_int();
}

vector <Expense> Balance::sorted_expenses_vector (vector <Expense> expenses){

    sort(expenses.begin(), expenses.end(), lower_expense);
    return expenses;

}

bool lower_income( Income first_income_date, Income second_income_date){

    return first_income_date.get_date_in_int() < second_income_date.get_date_in_int();
}

vector <Income> Balance::sorted_incomes_vector (vector <Income> incomes){

    sort(incomes.begin(), incomes.end(), lower_income);
    return incomes;

}

/*
void Balance::display_current_months_balance(vector <Income> incomes, vector <Expense> expenses){

    float incomes_amount = 0, incomes_sum = 0;

    if (!incomes.empty()){

        cout << " ------ Incomes List  -------" << endl;

        for(int i = 0; i < incomes.size(); i++){

            sort_income_balance(i);
            incomes_sum += incomes_amount;


        }


    }

}
*/

float Balance::calculate_income(int first_date_income, int second_date_income){

    for (int i = 0; i < sorted_incomes.size(); i ++){

        if(sorted_incomes[i].get_date_in_int() >= first_date_income && sorted_incomes[i].get_date_in_int() <= second_date_income){

            income_sum = income_sum + sorted_incomes[i].get_amount_in_float();
        }
    }

    return income_sum;
}

float Balance::calculate_expense(int first_date_expense, int second_date_expense){

    for (int i = 0; i < sorted_expenses.size(); i ++){

        if(sorted_expenses[i].get_expense_date_int() >= first_date_expense && sorted_expenses[i].get_expense_date_int() <= second_date_expense){

            expense_sum = expense_sum + sorted_expenses[i].get_amount_in_float();
        }
    }

    return expense_sum;
}

void Balance::calculate_current_month(){

    string date_beginning_in_string, current_date;

    int date_beginning_in_int, date_end_in_int, day;

    current_date = date.get_current_data_from_PC();

    date_end_in_int = Helpful_Methods::date_without_dashes_in_int(current_date);
    day = Helpful_Methods::string_to_int_conversion(Helpful_Methods::extract_day(current_date));

    date_beginning_in_int = date_end_in_int - day + 1;

    income_sum = calculate_income(date_beginning_in_int, date_end_in_int);
    expense_sum = calculate_expense(date_beginning_in_int, date_end_in_int);



}
