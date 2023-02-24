#ifndef HELPFUL_METHODS_H
#define HELPFUL_METHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Helpful_Methods{

public:
    static string load_line();
    static string change_first_letter_to_big_one(string text_to_convert);
    static char select_option_from_main_menu();
    static char select_option_from_users_menu();
    static string int_to_string_conversion(int number);
    static void display_months_list();
    static void check_how_many_commas_user_entered(string text);


};



#endif // HELPFUL_METHODS_H
