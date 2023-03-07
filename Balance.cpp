#include "Balance.h"

void Balance::sort_income(Income income) {

    sort(incomes.begin(), incomes.end(), sort_by_income_date());
}

void Balance::sort_expense(Expense expense) {

    sort(expenses.begin(), expenses.end(), sort_by_expense_date());
}


float Balance::current_month_income(Income income) {

    SYSTEMTIME st;
    GetSystemTime(&st);

    float income_float = 0;
    int year = 0, month = 0, day = 0, actual_date_int = 0, beggining_date_int = 0;
    string day_number_in_string = "", month_number_in_string = "", day_in_string = "", months_beginning = "", years_beginning = "", begin_date = "", actual_date = "", day_begin = "01";

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    day_in_string = Helpful_Methods::int_to_string_conversion(day);

    if (day_in_string.length() == 1) {
        day_number_in_string = "0"+ day_in_string;
    } else day_number_in_string = day_in_string;

    months_beginning = Helpful_Methods::int_to_string_conversion(month);

    if (months_beginning.length() == 1) {
        month_number_in_string = "0"+ months_beginning;
    } else month_number_in_string = months_beginning;

    years_beginning = Helpful_Methods::int_to_string_conversion(year);

    begin_date = years_beginning + month_number_in_string + day_begin;

    actual_date = years_beginning + month_number_in_string + day_number_in_string;

    actual_date_int = Helpful_Methods::string_to_int_conversion(actual_date);

    beggining_date_int = Helpful_Methods::string_to_int_conversion(begin_date);

    if (income.get_date_in_int() >= beggining_date_int && income.get_date_in_int() <= actual_date_int) {

        income_float = Helpful_Methods::string_to_float_conversion(income.get_incomes_amount());

        return income_float;

    } else return 0;
}



float Balance::current_month_expense(Expense expense) {

    SYSTEMTIME st;
    GetSystemTime(&st);

    float expense_float = 0;
    int year = 0, month = 0, day = 0, actual_date_int = 0, beggining_date_int = 0;
    string day_number_in_string = "", month_number_in_string = "", day_in_string = "", months_beginning = "", years_beginning = "", begin_date = "", actual_date = "", day_begin = "01";

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    day_in_string = Helpful_Methods::int_to_string_conversion(day);

    if (day_in_string.length() == 1) {
        day_number_in_string = "0" + day_in_string;
    } else day_number_in_string = day_in_string;

    months_beginning = Helpful_Methods::int_to_string_conversion(month);

    if (months_beginning.length() == 1) {
        month_number_in_string = "0" + months_beginning;
    } else month_number_in_string = months_beginning;

    years_beginning = Helpful_Methods::int_to_string_conversion(year);

    begin_date = years_beginning + month_number_in_string + day_begin;

    actual_date = years_beginning + month_number_in_string + day_number_in_string;

    actual_date_int = Helpful_Methods::string_to_int_conversion(actual_date);

    beggining_date_int = Helpful_Methods::string_to_int_conversion(begin_date);

    if (expense.get_expense_date_int() >= beggining_date_int && expense.get_expense_date_int() <= actual_date_int) {

        expense_float = Helpful_Methods::string_to_float_conversion(expense.get_expense_amount());

        return expense_float;
    } else {
        return 0;
    }
}


bool answer(char choice){


    while (choice != 'y' || choice != 'n'){

        if(choice == 'y'){
            return true;
        }
        else if( choice == 'n'){
            return false;
        }
        cout << "Enter proper character: " << endl;
        cin >> choice;
    }
}

void Balance::display_current_months_balance(vector <Income> incomes, vector <Expense> expenses) {

    SYSTEMTIME st;
    GetSystemTime(&st);

    float incomes_amount = 0;
    float income_sum = 0;
    system("cls");

    char choice;

    sort(incomes.begin(), incomes.end(), sort_by_income_date());
    sort(expenses.begin(), expenses.end(), sort_by_expense_date());

    if (incomes.empty() == false) {

        Helpful_Methods::displaying_current_month_and_year_income();

        cout << "Do you wish to display all incomes? Answer (y/n)" << endl;
        cin >> choice;

        if ( answer(choice) == true) {
            display_info_about_incomes(incomes);
        }
        else{
            cout << "You chose not to display all incomes. Moving forward." << endl;
        }

        for (unsigned int i = 0; i < incomes.size(); i ++) {

            sort_income(i);
            incomes_amount = Helpful_Methods::string_to_float_conversion(incomes[i].get_incomes_amount());
            income_sum = income_sum + incomes_amount;
        }

    } else {
        cout << "No incomes in ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear);
        cout << "sorry." << endl;
    }
    system("pause");
    system("cls");

    float expense_sum = 0;
    float expense_amount = 0;

    if (expenses.empty() == false) {

        Helpful_Methods::displaying_current_month_and_year_expense();

        cout << "Do you wish to display all expenses? Answer (y/n)" << endl;
        cin >> choice;

        if ( answer(choice) == true) {
            display_info_about_expenses(expenses);
        }
        else{
            cout << "You chose not to display all expenses. Moving forward." << endl;
        }
        system("pause");
        system("cls");

        for (unsigned int i = 0; i < expenses.size(); i ++) {

            sort_expense(i);
            expense_amount = Helpful_Methods::string_to_float_conversion(expenses[i].get_expense_amount());
            expense_sum = expense_sum + expense_amount;

        }
    } else {
        cout << "No expenses in: ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear);
    }

    Helpful_Methods::display_summary_income_expense_current_month();

    cout << "Income sum is equal:  " << setprecision(20) << income_sum << endl;
    cout << "Expense sum is equal:  " <<  expense_sum << endl;

    system("pause");
    system("cls");

    Helpful_Methods::display_summary_income_expense_current_month();
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Do you wish to display difference between incomes and expenses? (y/n)" << endl;
    cin >> choice;
    system("cls");

    if(answer(choice) == true) {

        float income_expense_difference = income_sum - expense_sum;
        cout << "Calulating process. Please wait." << endl;
        Sleep(3000);

        cout << "--------------- Difference is equal --------------- " << endl;
        cout << "---------------       " << setprecision(20) << income_expense_difference << "          --------------- "<< endl << endl;
        system("pause");

    }

    if(answer(choice) == false){

        cout << "Difference has not been calculated. Goodbye." << endl;

    }
}

void Balance::display_info_about_incomes(vector <Income> incomes) {

    for (unsigned int i = 0; i < incomes.size(); i ++) {

        cout << "Income title:                         " << incomes[i].get_incomes_title() << endl;
        cout << "Income amount:                        " << incomes[i].get_incomes_amount() << endl;
        cout << "Income date:                          " << incomes[i].get_date_in_string() << endl;
        cout << endl;
    }
}

void Balance::display_info_about_expenses(vector <Expense> expenses) {

    for (unsigned int i = 0; i < expenses.size(); i ++) {

        cout << "Income title:                         " << expenses[i].get_expense_title() << endl;
        cout << "Income amount:                        " << expenses[i].get_expense_amount() << endl;
        cout << "Income date:                          " << expenses[i].get_expense_date() << endl;
        cout << endl;
    }
}
