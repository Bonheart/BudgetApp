#include <iostream>
#include "Markup.h"
#include "User_Manager.h"
#include "BUDGET-APP.h"

using namespace std;

int main()
{


    Budget_App budget("users.xml"); // created default xml file. gotta make a Constructor in BUDGET-APP.h and User_Manager.h

    char choice;

    while(true){

        choice = budget.select_option_from_users_menu();

        switch (choice){

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

    return 0;
}
