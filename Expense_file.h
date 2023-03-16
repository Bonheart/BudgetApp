#ifndef EXPENSE_FILE_H
#define EXPENSE_FILE_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Helpful_Methods.h"
#include "Expense.h"
#include "Markup.h"
#include "Helpful_Methods.h"

using namespace std;


class Expense_File{

    int last_expense_id;

public:

    Expense_File(string expense_filename){

        last_expense_id = 0;

    }
    vector <Expense> load_expenses_from_file(int logged_user_id);
    void add_expense_to_file(Expense expense);
    int get_last_expense_id();




};



#endif // EXPENSE_FILE_H
