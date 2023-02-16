#include "Helpful_Methods.h"

string Helpful_Methods::load_line(){

    string input = "";
    cin.sync(); // sync, so nothing is gonna crash in getting data's
    getline(cin,input);
    return input;

}

string Helpful_Methods::change_first_letter_to_big_one(string txt_to_convert){

    if(!txt_to_convert.empty()){

        transform(txt_to_convert.begin(), txt_to_convert.end(), txt_to_convert.begin(), ::tolower);
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

char Helpful_Methods::select_option_from_users_menu(){

    char choice;

    system("cls");

    cout <<" Choose an option below you wish to do " << endl;
    cout <<" --------------------------------------" << endl;
    cout <<" 1. Add income." << endl;
    cout <<" 2. Add expense." << endl;
    cout <<" 3. Display current month's balance." << endl;
    cout <<" 4. Display last month's balance." << endl;
    cout <<" 5. I want to choose balance's period of time myself!" << endl;
    cout <<" 8. Logout" << endl;

    cin >> choice;

    return choice;
}


string Helpful_Methods::int_to_string_conversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
