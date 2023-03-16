#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{

    string expense_date_in_string;
    string expense_amount;
    string expense_title;
    int expense_id;
    int logged_user_id;
    int expense_date_in_int;

public:

    Expense(int expense_id = 0, int logged_user_id = 0, int expense_date_in_int = 0, string expense_amount = "", string expense_title = "", string expense_date_in_string = ""){

        this -> expense_id = expense_id;
        this -> logged_user_id = logged_user_id;
        this -> expense_date_in_int = expense_date_in_int;
        this -> expense_title = expense_title;
        this -> expense_amount = expense_amount;
        this -> expense_date_in_string = expense_date_in_string;

    }

    void set_expense_date(string expens_string);
    void set_expense_amount(string expens_amount);
    void set_expense_title(string expens_title);
    void set_expense_id(int expens_id);
    void set_logged_user_id(int logged_use_id);
    void set_expense_date_in_int(int expens_date_int);


    string get_expense_date();
    string get_expense_amount();
    string get_expense_title();
    int get_expense_id();
    int get_logged_user_id();
    int get_expense_date_int();


};




#endif // EXPENSE_H
