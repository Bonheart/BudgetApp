#include <iostream>
#include "Markup.h"
#include "User_Manager.h"
#include "BUDGET-APP.h"

using namespace std;

int main() {

    Budget_App budget("users.xml", "income.xml"); // created default xml file. gotta make a Constructor in BUDGET-APP.h and User_Manager.h

    char choice;

    while(true) {

        if(budget.check_if_user_is_logged()!= true ) {

            choice = budget.select_option_from_main_menu();

            switch (choice) {

            case '1':
                budget.user_registration();
                break;
            case '2':
                budget.user_login();
                break;
            case '3':
                exit(0);

            }
        }

        else {


            choice = budget.select_option_from_users_menu();

            switch(choice) {
            case '1':
                budget.add_income();
                break;

            case '7':
                budget.change_users_password();
                break;

            case '8':
                budget.user_logout();
                break;
            default:
                cout << "Enter proper number." << endl;

            }


        }
    }


    return 0;
}
