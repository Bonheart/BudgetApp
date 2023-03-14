#include "BUDGET-APP.h"

void Budget_App::user_registration() {

    user_manager.user_registration(); // already have object "user_manager" of "User_Manager" class in BUDGET-APP.h as private set, so I can operate on object

}

void Budget_App::user_login() {

    user_manager.user_login();

    income_expense_manager = new Income_Expense_Manager( EXPENSE_FILE_NAME, INCOME_FILE_NAME, user_manager.get_logged_users_id());

}

char Budget_App::select_option_from_main_menu() {

    return Helpful_Methods::select_option_from_main_menu();

}

char Budget_App::select_option_from_users_menu() {

    return Helpful_Methods::select_option_from_users_menu();

}

bool Budget_App::check_if_user_is_logged() {

    return user_manager.check_if_user_is_logged();
}

void Budget_App::user_logout() {

    user_manager.user_logout();
    delete income_expense_manager;
    income_expense_manager = NULL;

}

void Budget_App::change_users_password() {

    user_manager.change_users_password();

}

void Budget_App::add_income() {

    if(user_manager.check_if_user_is_logged()) {

        income_expense_manager -> add_new_income() ;
    }

    else {
        cout << "Log in first." << endl;
        system("pause");
    }

}

void Budget_App::add_expense(){

    if(user_manager.check_if_user_is_logged()){

        income_expense_manager ->add_new_expense();

    }
    else{
        cout << "Log in first." << endl;
        system("pause");
    }
}

void Budget_App::display_current_months_balance(){

    income_expense_manager -> display_current_months_balance();
}

void Budget_App::display_last_months_balance(){

    income_expense_manager -> display_last_months_balance();

}

void Budget_App::display_selected_period_of_time_balance(){

    income_expense_manager -> display_selected_period_of_time_balance();
}
