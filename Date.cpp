#include "Date.h"

bool Date::check_if_year_is_leap(int year) {

    bool leap_year;

    leap_year = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
        return leap_year;
}

string Date::get_current_data_from_PC() {

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

    if(month_converted_to_string.length() == 1){

        month_converted_to_string = "0" + month_converted_to_string;
    }
    if(day_converted_to_string.length() == 1){

        day_converted_to_string = "0" + day_converted_to_string;
    }

    todays_date_converted_to_string = year_converted_to_string + "-" + month_converted_to_string + "-" + day_converted_to_string;

    return todays_date_converted_to_string;
}

int Date::check_amount_of_days_in_month(bool check_if_year_is_leap, int month) {

    int days;

    if (month == 4 || month == 6 || month == 9 || month == 10) {

        days = 30;
        return days;
    }

    else if (month == 2) {

        if(check_if_year_is_leap == true) {
            days = 29;
            cout << "LEAP YEAR - be aware of amount of February's days" << endl;
        } else {
            days = 28;
            cout << "This year IS NOT leap." << endl;
            return days;
        }

    } else {
        days = 31;
    }

    return days;
}

string Date::entering_manual_date() {

    Date date;

    SYSTEMTIME st;
    GetSystemTime(&st);

    int current_year = 0, i = 1;
    int month_days = 0;
    string current_date_in_string = "";
    current_year = st.wYear;

    int entered_month = 0, entered_year = 0, entered_day = 0;
    string data_in_string = "", year_in_string = "", month_in_string = "", day_in_string = "";

    system("cls");
    cin.sync();

    cout << "Provide Year: " << endl;
    entered_year = Helpful_Methods::load_int();
    while((entered_year < 2000) || (entered_year > current_year)) {

        system("cls");
        cout << "You entered wrong year " << i << " time. " << 3 - i << " attempts remaining." << endl;
        cout << "Enter year once again: " << endl;
        entered_year = Helpful_Methods::load_int();

        if (i == 3) {
            cout << "You were warned. Goodbye." << endl;
            exit(0);
        }
        i++;
    }

    Helpful_Methods::display_months_list();

    entered_month = Helpful_Methods::load_int();
    i = 1;
    while (entered_month < 1 || entered_month > 12) {

        system ("cls");
        cout << "You entered wrong month's number. Attempts left: " << 3 - i << endl;
        Sleep(3000);
        system ("cls");
        Helpful_Methods::display_months_list();
        entered_month = Helpful_Methods::load_int();

        if (i == 3) {
            cout << "You were warned. Goodbye." << endl;
            exit(0);
        }
        i++;
    }

    system ("cls");
    month_days = date.check_amount_of_days_in_month(check_if_year_is_leap(entered_year),entered_month);

    i = 1;

    cout << "Enter day: " << endl;
    entered_day = Helpful_Methods::load_int();

    while(month_days < entered_day || entered_day < 1) {

        cout << "Entered day is out of range" << " (1 - " << month_days << " )" << endl;
        cout << "Attempts left: " << 3 - i << endl;
        entered_day = Helpful_Methods::load_int();

        if( i == 2) {

            cout << "Given day has been entered wrong 3 times. Goodbye." << endl;
            exit(0);

        }
        i++;
    }
    string enetered_month_converted_to_string = "";
    enetered_month_converted_to_string = Helpful_Methods::int_to_string_conversion(entered_month);

    string entered_day_converted_to_string = "";
    entered_day_converted_to_string = Helpful_Methods::int_to_string_conversion(entered_day);


    if (enetered_month_converted_to_string.length() == 1) {
        enetered_month_converted_to_string = "0" + enetered_month_converted_to_string;
    }
    if (entered_day_converted_to_string.length() == 1) {
        entered_day_converted_to_string = "0" + entered_day_converted_to_string;
    }
    current_date_in_string = Helpful_Methods::int_to_string_conversion(entered_year) + "-" + enetered_month_converted_to_string + "-" + entered_day_converted_to_string;

    return current_date_in_string;
}

void Date::display_months_name(int month){

    switch(month){

    case 1:
        cout << "January " ;
    break;
    case 2:
        cout << "February " ;
    break;
    case 3:
        cout << "March " ;
    break;
    case 4:
        cout << "April " ;
    break;
    case 5:
        cout << "May " ;
    break;
    case 6:
        cout << "June " ;
    break;
    case 7:
        cout << "July " ;
    break;
    case 8:
        cout << "August " ;
    break;
    case 9:
        cout << "September " ;
    break;
    case 10:
        cout << "October " ;
    break;
    case 11:
        cout << "November " ;
    break;
    case 12:
        cout << "December " ;
    break;

    }

}

void Date::display_current_year(int year){

    cout << year ;

}

string Date::get_previous_month(){

    SYSTEMTIME st;
    GetSystemTime(&st);


    int  month = 0, previous_month = 0;
    string month_in_string = "";

    month = st.wMonth;

    if (month == 1)
    {
        previous_month = 12;
    }
    else
    {
        previous_month = month - 1;
    }

    switch(previous_month){

    case 1:
        month_in_string = "01";
    break;
    case 2:
        month_in_string = "02";
    break;
    case 3:
        month_in_string = "03";
    break;
    case 4:
        month_in_string = "04";
    break;
    case 5:
        month_in_string = "05";
    break;
    case 6:
        month_in_string = "06";
    break;
    case 7:
        month_in_string = "07";
    break;
    case 8:
        month_in_string = "08";
    break;
    case 9:
        month_in_string = "09";
    break;
    case 10:
        month_in_string = "10";
    break;
    case 11:
        month_in_string = "11";
    break;
    case 12:
        month_in_string = "12";
    break;

    }
    return month_in_string;
}

string Date::get_end_day(string month){

    Date date;
    SYSTEMTIME st;
    GetSystemTime(&st);

    int year;
    year = st.wYear;

    string days = "";

    if (month == "04" || month == "06" || month == "09" || month == "11") {

        days = "30";
        return days;
    }

    else if (month == "02") {

        if(date.check_if_year_is_leap(year) == true) {
            days = "29";
        } else {
            days = "28";
            return days;
        }

    } else {
        days = "31";
    }

    return days;

}

string Date::get_fully_end_date_of_previous_month(){

     SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    string year_in_string = "";
    year_in_string = Helpful_Methods::int_to_string_conversion(year);

    string date = "";
    date = year_in_string + get_previous_month() + get_end_day(get_previous_month());
    return date;

}

string Date::get_fully_beginning_date_of_previous_month(){

  SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    string year_in_string = "";
    year_in_string = Helpful_Methods::int_to_string_conversion(year);

    string date = "";
    date = year_in_string + get_previous_month() + "01";
    return date;


}

string Date::get_actual_month(){

    SYSTEMTIME st;
    GetSystemTime(&st);


    int  month = 0;
    string month_in_string = "";

    month = st.wMonth;



    switch(month){

    case 1:
        month_in_string = "01";
    break;
    case 2:
        month_in_string = "02";
    break;
    case 3:
        month_in_string = "03";
    break;
    case 4:
        month_in_string = "04";
    break;
    case 5:
        month_in_string = "05";
    break;
    case 6:
        month_in_string = "06";
    break;
    case 7:
        month_in_string = "07";
    break;
    case 8:
        month_in_string = "08";
    break;
    case 9:
        month_in_string = "09";
    break;
    case 10:
        month_in_string = "10";
    break;
    case 11:
        month_in_string = "11";
    break;
    case 12:
        month_in_string = "12";
    break;

    }
    return month_in_string;
}

string Date::get_fuly_beginning_date_of_current_month(){

     SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    string year_in_string = "";
    year_in_string = Helpful_Methods::int_to_string_conversion(year);

    string date = "";
    date = year_in_string + get_actual_month() + "01";
    return date;

}
