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
