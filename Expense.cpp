#include "Expense.h"

void Expense::set_expense_id(int new_expense_id){

    if(new_expense_id > 0){
        expense_id = new_expense_id;
    }

}

void Expense::set_logged_user_id(int new_logged_user_id){

    if(new_logged_user_id > 0){

        logged_user_id = new_logged_user_id;

    }
}

void Expense::set_expense_amount(string new_expense_amount){

    expense_amount = new_expense_amount;

}

void Expense::set_expense_date(string new_expense_date){

    expense_date_in_string = new_expense_date;

}

void Expense::set_expense_title(string new_expense_title){

    expense_title = new_expense_title;

}

void Expense::set_expense_date_in_int(int new_expense_date_in_int){

    expense_date_in_int = new_expense_date_in_int;

}


string Expense::get_expense_amount(){

    return expense_amount;
}

string Expense::get_expense_date(){

    return expense_date_in_string;
}

string Expense::get_expense_title(){

    return expense_title;
}

int Expense::get_expense_id(){

    return expense_id;
}

int Expense::get_logged_user_id(){

    return logged_user_id;
}

int Expense::get_expense_date_int(){


    return expense_date_in_int;
}
