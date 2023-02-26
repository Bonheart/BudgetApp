#include "Date.h"

bool Date::check_if_year_is_leap(int year) {

    bool leap_year;

    leap_year = (((year % 4 == 0) && (year %100 != 0) || (year % 400 == 0)));
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

    SYSTEMTIME st;
    GetSystemTime(&st);

    int current_year = 0, i = 1;
    int month_days = 0;
    string current_date_in_string = "";
    current_year = st.wYear;

    int entered_month = 0, entered_year = 0, entered_day = 0;
    string data_in_string = "", year_in_string = "", month_in_string = "", day_in_string = "";

    cout << "This Budget APP works only in date range 2000-01-01 - current year's month. Any attempts to exceed this range will be punished." << endl;
    system("pause");
    system("cls");

    cout << "Enter year" << endl;
    cin >> entered_year;
    while((entered_year < 2000) || (entered_year > current_year)) {

        system("cls");
        cout << "You entered wrong year " << i << " time. " << 3 - i << " attempts remaining." << endl;
        cout << "Enter year once again: " << endl;
        cin >> entered_year;

        if (i == 3) {
            cout << "You were warned. Goodbye." << endl;
            exit(0);
        }
        i++;
    }

    Helpful_Methods::display_months_list();

    cin >> entered_month;
    i = 1;
    while (entered_month < 1 || entered_month > 12) {

        system ("cls");
        cout << "You entered wrong month's number. Attempts left: " << 3 - i << endl;
        Sleep(3000);
        system ("cls");
        Helpful_Methods::display_months_list();
        cin >> entered_month;

        if (i == 3) {
            cout << "You were warned. Goodbye." << endl;
            exit(0);
        }
        i++;
    }

    system ("cls");
    month_days = check_amount_of_days_in_month(check_if_year_is_leap(entered_year),entered_month);

    i = 1;

    cout << "Enter day: " << endl;
    cin >> entered_day;

    while(month_days < entered_day || entered_day < 1) {

        cout << "Entered day is out of range" << " (1 - " << month_days << " )" << endl;
        cout << "Attempts left: " << 3 - i << endl;
        cin >> entered_day;

        if( i == 3) {
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
