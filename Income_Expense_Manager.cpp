#include "Income_Expense_Manager.h"

void Income_Expense_Manager::add_new_income() {

    Income income = add_info_about_income();

    incomes.push_back(income);

    income_file.add_income_to_file(income);

    cout << "income added." << endl;
    system("pause");
}

Income Income_Expense_Manager::add_info_about_income() {

    Income income;
    string income_date = "", income_title = "", income_amount = "";

    income.set_incomes_id(income_file.get_last_income_id());
    income.set_logged_users_id(LOGGED_USER_ID);

    Date::get_fully_beginning_date_of_previous_month();
    string data_option_choice;

    cout << "Set income data. Two options: today's date (TD) or manually chosen date (MCD)" << endl;
    cin >> data_option_choice;
    transform(data_option_choice.begin(), data_option_choice.end(), data_option_choice.begin(), :: toupper);

    while(true) {

        if(data_option_choice == "MCD") {

            cout << "You have chosen to enter date manually. Preparing." << endl;
            Sleep(2000);
            system("cls");

            income_date = Date::entering_manual_date();

            cout << "Please provide title: " << endl;
            income.set_date_in_string(income_date);
            income.set_date_in_int(Helpful_Methods::date_without_dashes_in_int(income_date));

            //system("cls");

            income_title = Helpful_Methods::load_string();
            income.set_incomes_title(income_title);
            system("cls");

            income_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            while (Helpful_Methods::check_if_income_or_expense_does_have_only_dot_and_digits(income_amount) != true || Helpful_Methods::check_how_many_dots_user_entered(income_amount) != false) {

    //            cout << "Try again: " << endl;
                income_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            }
            income.set_incomes_amount(income_amount);
            break;

        }

        else if (data_option_choice == "TD") {

            income_title = Helpful_Methods::load_string();

            income.set_incomes_title(income_title);

            income_date = Date::get_current_data_from_PC();

            income.set_date_in_string(income_date);

            income.set_date_in_int(Helpful_Methods::date_without_dashes_in_int(income_date));

            income_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            while (Helpful_Methods::check_if_income_or_expense_does_have_only_dot_and_digits(income_amount) != true || Helpful_Methods::check_how_many_dots_user_entered(income_amount) != false){

//                cout << "Try again: " << endl;
                income_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            }
            income.set_incomes_amount(income_amount);
            break;
        }

        else {
            cout << "Try again:" << endl;
            cin >> data_option_choice;
            transform(data_option_choice.begin(), data_option_choice.end(), data_option_choice.begin(), :: toupper);
        }
    }

    return income;
}

void Income_Expense_Manager::add_new_expense() {

    Expense expense = add_info_about_expense();

    expenses.push_back(expense);

    expense_file.add_expense_to_file(expense);

    cout << "Expense added." << endl;
    system("pause");

}

Expense Income_Expense_Manager::add_info_about_expense() {

    Expense expense;
    string expense_date = "", expense_title = "", expense_amount = "";

    expense.set_expense_id(expense_file.get_last_expense_id());
    expense.set_logged_user_id(LOGGED_USER_ID);

    string data_option_choice;

    cout << "Set expense data. Two options: today's date (TD) or manually chosen date (MCD)" << endl;
    cin >> data_option_choice;
    transform(data_option_choice.begin(), data_option_choice.end(), data_option_choice.begin(), :: toupper);

    while(true) {

        if(data_option_choice == "MCD") {

            cout << "You have chosen to enter date manually. Preparing." << endl;
            Sleep(2000);
            system("cls");

            expense_date = Date::entering_manual_date();
            expense.set_expense_date(expense_date);
            expense.set_expense_date_in_int(Helpful_Methods::date_without_dashes_in_int(expense_date));
            system("cls");

            cout << "Please provide title: " << endl;
            expense_title = Helpful_Methods::load_string();
            expense.set_expense_title(expense_title);
            system("cls");

            expense_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            while (Helpful_Methods::check_if_income_or_expense_does_have_only_dot_and_digits(expense_amount) != true || Helpful_Methods::check_how_many_dots_user_entered(expense_amount) != false) {

                expense_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            }
            expense.set_expense_amount(expense_amount);
            break;

        }

        else if (data_option_choice == "TD") {

            expense_title = Helpful_Methods::load_string();
            expense.set_expense_title(expense_title);

            expense_date = Date::get_current_data_from_PC();
            expense.set_expense_date(expense_date);
            expense.set_expense_date_in_int(Helpful_Methods::date_without_dashes_in_int(expense_date));

            expense_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();
            while (Helpful_Methods::check_if_income_or_expense_does_have_only_dot_and_digits(expense_amount) != true || Helpful_Methods::check_how_many_dots_user_entered(expense_amount) != false) {

                expense_amount = Helpful_Methods::check_if_given_amount_is_positive_or_is_equal_to_zero();

            }
            expense.set_expense_amount(expense_amount);

            break;
        } else {
            cout << "Try again:" << endl;
            cin >> data_option_choice;
            transform(data_option_choice.begin(), data_option_choice.end(), data_option_choice.begin(), :: toupper);
        }
    }
    return expense;
}

float Income_Expense_Manager::incomes_sum(int beginning_date, int ending_date) {

    Income income;

    vector <Income> second_incomes;

    string incomes_amount = "";
    float incomes_float = 0, incomes_sum = 0;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {

        if (itr -> Income::get_date_in_int() >= beginning_date && itr -> Income::get_date_in_int() <= ending_date) {

           second_incomes.push_back(*itr);
            incomes_amount = itr -> get_incomes_amount();
            incomes_float = Helpful_Methods::string_to_float_conversion(incomes_amount);
            incomes_sum += incomes_float;

        }
    }

    sort(second_incomes.begin(), second_incomes.end(), [](const Income &first, const Income &second) {

        return first.get_date_in_int() < second.get_date_in_int();

    });

     for (unsigned int i = 0; i <  incomes.size(); i++) {

        if (incomes[i].get_date_in_int() >= beginning_date && incomes[i].get_date_in_int() <= ending_date) {

            cout << "Income date: " << incomes[i].get_date_in_string() << endl;
            cout << "Income title: " << incomes[i].get_incomes_title() << endl;
            cout << "Income amount: "<< incomes[i].get_incomes_amount() << endl;
            cout << endl;
        }
    }
    cout << endl;

    return incomes_sum;
}

float Income_Expense_Manager::expenses_sum(int beginning_date, int ending_date) {

    Expense expense;

    vector <Expense> second_expense;

    string expense_amount = "";
    float incomes_float = 0, incomes_sum = 0;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {

        if (itr -> Expense::get_expense_date_int() >= beginning_date && itr -> Expense::get_expense_date_int() <= ending_date) {

            second_expense.push_back(*itr);
            expense_amount = itr -> get_expense_amount();
            incomes_float = Helpful_Methods::string_to_float_conversion(expense_amount);
            incomes_sum += incomes_float;

        }
    }

    sort(second_expense.begin(), second_expense.end(), [](const Expense &first, const Expense &second) {

        return first.get_expense_date_int() < second.get_expense_date_int();

    });

    for (unsigned int i = 0; i <  second_expense.size(); i++) {

        if (second_expense[i].get_expense_date_int() >= beginning_date && second_expense[i].get_expense_date_int() <= ending_date) {

        cout << "Expense date: " << second_expense[i].get_expense_date() << endl;
        cout << "Expense title: " << second_expense[i].get_expense_title() << endl;
        cout << "Expense amount: "<< second_expense[i].get_expense_amount() << endl;
        cout << endl;
      }
    }
    cout << endl;

    return incomes_sum;
}

void Income_Expense_Manager::display_current_months_balance() {

    SYSTEMTIME st;
    GetSystemTime(&st);

    string beginning_date = Date::get_fuly_beginning_date_of_current_month();

    int beginning_date_int = Helpful_Methods::string_to_int_conversion(beginning_date);
    int ending_date_int = Helpful_Methods::date_without_dashes_in_int(Date::get_current_data_from_PC());
    /*
    cout << "string poczatkowa data: " << beginning_date << endl;
    cout << "int poczatkowa data: " << beginning_date_int << endl;
    cout << "string koncowa data: " << ending_date_int << endl;
    system("pause");
    */
    float sum_of_incomes = incomes_sum(beginning_date_int, ending_date_int);
    float sum_of_expenses = expenses_sum(beginning_date_int, ending_date_int);
    float difference = sum_of_incomes - sum_of_expenses ;

    cout << "Balance of: ";
    Date::display_months_name(st.wMonth);
    cout << " " << st.wYear << endl;
    cout << ">>>>>>>> " << difference << " <<<<<<<<" << endl;

    system("pause");
}

void Income_Expense_Manager::display_last_months_balance(){

    SYSTEMTIME st;
    GetSystemTime(&st);

    int beginning_of_last_month = Helpful_Methods::string_to_int_conversion(Date::get_fully_beginning_date_of_previous_month());
    int ending_of_last_month = Helpful_Methods::string_to_int_conversion(Date::get_fully_end_date_of_previous_month());

    float sum_of_incomes = incomes_sum(beginning_of_last_month, ending_of_last_month);
    float sum_of_expenses = expenses_sum(beginning_of_last_month, ending_of_last_month);

    float difference = sum_of_incomes - sum_of_expenses ;

    cout << "Balance of: ";
    Date::display_months_name(st.wMonth - 1);
    cout << " " << st.wYear << endl;
    cout << ">>>>>>>> " << difference << " <<<<<<<<" << endl;

    system("pause");

}

void Income_Expense_Manager::display_selected_period_of_time_balance(){

    string beginning_string = Date::entering_manual_date();
    string ending_string = Date::entering_manual_date();
    int beginning_of_chosen_period = Helpful_Methods::date_without_dashes_in_int(beginning_string);
    int ending_of_chosen_period = Helpful_Methods::date_without_dashes_in_int(ending_string);

    float sum_of_incomes = incomes_sum(beginning_of_chosen_period, ending_of_chosen_period);
    float sum_of_expenses = expenses_sum(beginning_of_chosen_period, ending_of_chosen_period);

    float difference = sum_of_incomes - sum_of_expenses ;

    cout << ">>>>>>>>  Balance of period " ;
    cout << beginning_string;
    cout << " - " ;
    cout << ending_string  << " <<<<<<<<" << endl;

    cout << ">>>>>>>> " << difference << " <<<<<<<<" << endl;

    system("pause");

}
