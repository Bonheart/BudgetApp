#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

using namespace std;

class Date{

public:

    bool check_if_year_is_leap(int year);
    string get_current_data_from_PC();



};






#endif // DATE_H
