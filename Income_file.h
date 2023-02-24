#ifndef INCOME_FILE_H
#define INCOME_FILE_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"

using namespace std;


class Income_File{

public:

    Income_File(string income_filename){};
    void add_income_to_file(Income income);
    vector <Income> load_income_from_file();

};




#endif // INCOME_FILE_H
