#include "Date.h"


bool Date::check_if_year_is_leap(int year){


    bool check_if_year_is_leap = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
    cout << "Entered year is leap" << endl;
    return check_if_year_is_leap;

}


string Date::get_current_data_from_PC(){

    SYSTEMTIME st;
    GetSystemTime(&st);

    int year = 0, day = 0, month = 0;
    string todays_date_converted_to_string = "", year_converted_to_string = "", month_converted_to_string = "", day_converted_to_string = "";

    year = st.wYear;
    day = st.wDay;
    month = st.wMonth;

    year_converted_to_string = Helpful_Methods::int_to_string_conversion(year);
    month_converted_to_string = Helpful_Methods::int_to_string_conversion(month);
    day_converted_to_string = Helpful_Methods::int_to_string_conversion(day);

    todays_date_converted_to_string = year_converted_to_string + "-" + month_converted_to_string + "-" + day_converted_to_string;

    cout << todays_date_converted_to_string << endl;

    return todays_date_converted_to_string;


}

int Date::check_amount_of_days_in_month(bool check_if_year_is_leap, int month) {

    int days;

    if (month == 3 || month == 6 || month == 9 || month == 10){

        days = 30;
        cout << "This month has 30 days" << endl;
    }

    else if (month == 2){

        if(check_if_year_is_leap == true){
            days = 29;
            cout << "This year is leap. It has 29 days." << endl;
        }
        else{
            days = 28;
            cout << "This year is not leap, so it only has 28 days" << endl;
        }

    }
    else{
        days = 31;
        cout << "This month has 31 days" << endl;
    }

    return days;
}

