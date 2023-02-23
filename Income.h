#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

    int incomes_id;
    int logged_users_id;
    int date;
    string amount_of_income; // amount in string, because I'll have to convert "," into "." and that will be easier
    string income_title;
    string string_date;


public:

    void set_incomes_id(int new_income_id);
    void set_logged_users_id(int new_logged_users_id);
    void set_date(int new_date);
    void set_incomes_amount(string new_income_amount);
    void set_incomes_title(string new_income_title);
    void set_date_in_string(string new_date_in_string);

    int get_incomes_id();
    int get_logged_users_id();
    int get_date();
    string get_incomes_amount();
    string get_incomes_title();
    string get_date_in_string();

};



#endif // INCOME_H
