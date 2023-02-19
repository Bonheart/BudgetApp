#include "Date.h"


bool Date::check_if_year_is_leap(int year){


    bool check_if_year_is_leap = ((year % 4 == 0) && (year %100 != 0) || (year % 400 == 0));
    return check_if_year_is_leap;

}


string Date::get_current_data_from_PC(){

    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = 0, day = 0, month = 0;
    year = st.wYear; // year gained from system
    day = st.wDay; // day obtained from system
    month = st.wMonth; // month obtained from system
    cout << st.wYear << endl;


   // return st.wYear;
}
