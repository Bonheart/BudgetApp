#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "Helpful_Methods.h"

using namespace std;

class Date{

public:

    bool check_if_year_is_leap(int year);
    string get_current_data_from_PC();
    int check_amount_of_days_in_month(bool check_if_year_is_leap, int month);
    string entering_manual_date();

};






#endif // DATE_H
