#ifndef INCOME_FILE_H
#define INCOME_FILE_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"
#include "Helpful_Methods.h"

using namespace std;

class Income_File{

    int last_income_id;

public:

    Income_File(string income_filename){

    last_income_id = 0;

    };
    int add_income_to_file(Income income);
    vector <Income> load_income_from_file(int logged_user_id);
    int get_last_income_id();

};

#endif // INCOME_FILE_H
