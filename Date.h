#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "Helpful_Methods.h"

using namespace std;

class Date{

public:

    static bool check_if_year_is_leap(int year);
    static string get_current_data_from_PC();
    int check_amount_of_days_in_month(bool check_if_year_is_leap, int month);
    static string entering_manual_date();
    static void display_months_name(int month);
    static void display_current_year(int year);
    static string get_previous_month();
    static string get_end_day(string month);
    static string get_fully_end_date_of_previous_month();
    static string get_fully_beginning_date_of_previous_month();
    static string get_fuly_beginning_date_of_current_month();
    static string get_actual_month();


};






#endif // DATE_H
