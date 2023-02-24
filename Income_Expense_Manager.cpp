#include "Income_Expense_Manager.h"

Income Income_Expense_Manager::add_info_about_income() {

    Income income;
    string income_date = "", income_title, income_amount = "";

    //  income.set_incomes_id(get_new_income_id() + 1);
    // income.set_logged_users_id(LOGGED_USER_ID);
    /*
    string data_option_choice;
    cout << "Set income data. Two options: today's date (TD) or manually chosen date (MCD)" << endl;
    cin >> data_option_choice;
    transform(data_option_choice.begin(), data_option_choice.end(), data_option_choice.begin(), :: toupper);

        if(data_option_choice == "MCD") {

            cout << "You have chosen to enter date manually. Preparing." << endl;
            Sleep(2000);
            system("cls");

            income_date = date.entering_manual_date(); // do settera
            Sleep(1500);
            system("cls");

            cout << "Enter income title: " << endl;
            income_title = Helpful_Methods::load_line(); // do settera
            system("cls");

            cout << "Enter income. Remember to type amount of income separated with dots." << endl;
            income_amount = Helpful_Methods::load_line();
            income.set_incomes_amount(income_amount);

            while(Helpful_Methods::check_if_text_has_commas(income_amount) == true) {

                cout << "Entered income spearated with commas. Please separate with dots." << endl;
                income_amount = Helpful_Methods::load_line();
                system("cls");

                if (Helpful_Methods::check_if_text_has_commas(income_amount) == true){
                    cout << "Income set properly." << endl;
                    break;
                }

            //    if(Helpful_Methods::check_if_text_has_commas(income_amount) == true) {


                                        if(Helpful_Methods::check_how_many_dots_user_entered(income_amount) > 2) {

                                            do {

                                                cout << "You cannot enter more than 1 dot. Try again." << endl;
                                                income_amount = Helpful_Methods::load_line();
                                                system("cls");

                                            } while(Helpful_Methods::check_how_many_dots_user_entered(income_amount) == 1);
                                        }

               // }

            }
        }
    cout << income_title << endl;
    */
    cout << "set income title: " << endl;
    cin >> income_title;
    income.set_incomes_title(income_title);

    cout << income_title << endl;
    system("pause");

    return income;
}

void Income_Expense_Manager::add_new_income() {

    Income income = add_info_about_income();

   // incomes.push_back(income);

   // income_file.add_income_to_file(income);


    cout << "income added." << endl;
    system("pause");

}

int Income_Expense_Manager::get_new_income_id() {

    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().get_incomes_id() + 1;

}
