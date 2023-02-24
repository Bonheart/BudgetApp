#include "Income_Expense_Manager.h"

Income Income_Expense_Manager::add_info_about_income() {

    Income income;
    char choice;
    string income_date = "", income_title = "", income_amount = "";

    cout << "Do you wish to add an income? Choose Y/N " << endl;
    cin >> choice;

    //  income.set_incomes_id(get_new_income_id());
    // income.set_logged_users_id(LOGGED_USER_ID);

    while (choice != 89 || choice != 78 || choice != 110 || choice != 121 ) {

        if(choice == 121 || choice == 89) {

            string data_option_choice;
            cout << "Set income data. Two options: today's date (TD) or manually chosen date (MCD)" << endl;
            cin >> data_option_choice;
            transform(data_option_choice.begin(), data_option_choice.end(), data_option_choice.begin(), :: toupper);

            while(data_option_choice != "MCD" || data_option_choice != "TD") {

                if(data_option_choice == "MCD") {

                    cout << "You have chosen to enter date manually. Preparing." << endl;
                    Sleep(2000);
                    system("cls");
                    income_date = date.entering_manual_date(); // do settera
                    income_title = Helpful_Methods::load_line(); // do settera
                    income_amount = Helpful_Methods::load_line();
                    if(income_amount.find(","))

                    break;

                }
            }
        } else
            cout << "enter proper character " << endl;
            cin >> choice;
    }
    return income;
}

void Income_Expense_Manager::add_new_income() {

    Income income;

    income = add_info_about_income();
    incomes.push_back(income);

}

int Income_Expense_Manager::get_new_income_id() {

    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().get_incomes_id() + 1;

}
