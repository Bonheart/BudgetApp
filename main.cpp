#include <iostream>
#include "Markup.h"
#include "User_Manager.h"
#include "BUDGET-APP.h"



using namespace std;

int main() {
    vector <Income> incomes;
    vector <Expense> expenses;

    Budget_App budget("users.xml","expenses.xml","incomes.xml"); // created default xml file. gotta make a Constructor in BUDGET-APP.h and User_Manager.h

    char choice;

    while(true) {

        if(budget.check_if_user_is_logged() != true ) {

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

            case '2':
                budget.add_expense();
                break;

            case '3':
                budget.display_current_months_balance();
                break;
            case '4':
               budget.display_last_months_balance();
                break;
            case '5':
               budget.display_selected_period_of_time_balance();
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
