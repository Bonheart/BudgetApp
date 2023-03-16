#include "Helpful_Methods.h"

string Helpful_Methods::load_line() {

    string input = "";
    cin.sync(); // sync, so nothing is gonna crash in getting data's
    getline(cin,input);

    return input;
}

string Helpful_Methods::change_first_letter_to_big_one(string txt_to_convert) {

    if(!txt_to_convert.empty()) {

        transform(txt_to_convert.begin(), txt_to_convert.end(), txt_to_convert.begin(), :: tolower);
        txt_to_convert[0] = toupper(txt_to_convert[0]); // // first string's array[0](string is seen as letter chain - which means an array) is converted to upper letter
    }

    return txt_to_convert;
}

char Helpful_Methods::select_option_from_main_menu() {

    char choice;

    system("cls");

    cout << "    >>> USERS MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User Register" << endl;
    cout << "2. User Login" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    cin >> choice;

    return choice;
}

char Helpful_Methods::select_option_from_users_menu() {

    char choice;

    system("cls");

    cout <<" Choose an option below you wish to do " << endl;
    cout <<" --------------------------------------" << endl;
    cout <<" 1. Add income." << endl;
    cout <<" 2. Add expense." << endl;
    cout <<" 3. Display current month's balance." << endl;
    cout <<" 4. Display last month's balance." << endl;
    cout <<" 5. I want to choose balance's period of time myself!" << endl;
    cout <<" 7. Change password." << endl;
    cout <<" 8. Logout" << endl;

    cin >> choice;

    return choice;
}

string Helpful_Methods::int_to_string_conversion(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

void Helpful_Methods::display_months_list() {

    cout << ">>>>>>>>>>>>>>>>> MONTH LIST <<<<<<<<<<<<<<<<<<: " << endl;
    cout << "1. January" << endl;
    cout << "2. February" << endl;
    cout << "3. March" << endl;
    cout << "4. April" << endl;
    cout << "5. May" << endl;
    cout << "6. June" << endl;
    cout << "7. July" << endl;
    cout << "8. August" << endl;
    cout << "9. September" << endl;
    cout << "10. October" << endl;
    cout << "11. November" << endl;
    cout << "12. December" << endl;
    cout << "Enter month's number: " << endl;

}

bool Helpful_Methods::check_how_many_dots_user_entered(string text) {

     int counting = 0;

    for( unsigned int i = 0; i < text.length(); i++) {

        if(text[i] == '.') {

            counting++;

        }
    }
    if(counting < 2){
        return false;
    }
    else {
        return true;
    }
}

int Helpful_Methods::date_without_dashes_in_int(string text) {

    int text_in_int;

    text.erase(remove(text.begin(), text.end(), '-'), text.end());

    text_in_int = stoi(text);

    return text_in_int;
}

bool Helpful_Methods::check_if_income_or_expense_does_have_only_dot_and_digits(string str){

    return str.find_first_not_of("0123456789.") == std::string::npos;
}

string Helpful_Methods::load_string(){

    string text = "";
    string number = "";

    while (true)
    {
        getline(cin, text);
      //  cin.sync();

        stringstream myStream(text);

        if (myStream >> number)
            break;

        cout << "Please provide title: " << endl;
    }
    return number;

}

string Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero(){

    string text = "";
    string number = "";


    while (true)
    {
        cout << "Enter amount: " << endl;
        getline(cin, text);
        cin.sync();

        stringstream myStream(text);

        if (myStream >> number)
            break;

    }
    return number;

}

int Helpful_Methods::load_int(){

    string text = "";
    int number = 0;

    while (true)
    {
        getline(cin, text);

        stringstream myStream(text);

        if (myStream >> number)
            break;
<<<<<<< HEAD

        cout << "Given input is not a number. Try again" << endl;

=======
<<<<<<< HEAD
        cout << "Given input is not a number. Try again" << endl;
=======

        cout << "Given input not a number. Try again" << endl;
>>>>>>> feature_balance
>>>>>>> 98d62c06fa3499d15b8ad334881ba3667a2e50ef
    }
    return number;
}

int Helpful_Methods::string_to_int_conversion (string text) {

    int int_number;
    istringstream iss(text);
    iss >> int_number;

    return int_number;
}

float Helpful_Methods::string_to_float_conversion (string text) {

    float float_number;
    float_number = stof(text);

    return float_number;
}

void Helpful_Methods::displaying_current_month_and_year_income(){

    SYSTEMTIME st;
    GetSystemTime(&st);

    cout << " --------------- INCOMES OF: ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear)  ;
        cout <<" --------------- " << endl;
        Sleep(1000);
}

void Helpful_Methods::displaying_current_month_and_year_expense(){

    SYSTEMTIME st;
    GetSystemTime(&st);

    cout << " --------------- EXPENSES OF: ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear)  ;
        cout <<" --------------- " << endl;
        Sleep(1000);
}

void Helpful_Methods::display_summary_income_expense_current_month(){

    SYSTEMTIME st;
    GetSystemTime(&st);

    cout << " --------------- INCOMES AND EXPENSES OF: ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear)  ;
        cout <<" --------------- " << endl;
        Sleep(1000);
}
