#include "Income.h"

void Income::set_incomes_id(int new_income_id){

    if (new_income_id > 0){

        incomes_id = new_income_id;

    }
}

void Income::set_logged_users_id(int logged_user_id){

    if(logged_user_id > 0){

        logged_users_id = logged_user_id;
    }
}

void Income::set_date_in_int(int new_date_in_int){

    int_date = new_date_in_int;

}

void Income::set_incomes_amount(string new_incomes_amount){


    amount_of_income = new_incomes_amount;

}


void Income::set_incomes_title(string new_incomes_title){


    incomes_title = new_incomes_title;

}

void Income::set_date_in_string(string new_date){

    string_date = new_date;

}

void Income:: set_amount_in_float(float new_amount_float){

    amount_in_float = new_amount_float;

}

int Income::get_incomes_id(){

    return incomes_id;
}

int Income::get_logged_users_id(){

    return logged_users_id;

}

int Income::get_date_in_int(){

    return int_date;
}

float Income::get_amount_in_float(){
    return amount_in_float;
}

string Income::get_incomes_amount(){

    return amount_of_income;

}

string Income::get_incomes_title(){

    return incomes_title;
}

string Income::get_date_in_string(){

    return string_date;
}
