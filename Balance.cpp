#include "Balance.h"

void Balance::sort_income(Income income) {
    /*
    sort(incomes.begin(), incomes.end(), [](const Income& a, const Income& b) {
        return a.get_date_in_int() < b.get_date_in_int();
    });
    */
    sort(incomes.begin(), incomes.end(), sort_by_income_date());
}
void Balance::sort_expense(Expense expense) {

    sort(expenses.begin(), expenses.end(), sort_by_expense_date());
}

float Balance::current_month_income(Income income, int first_date, int second_date) {

    float income_float = 0;
    float income_sum = 0;

    if (income.get_date_in_int() >= first_date && income.get_date_in_int() <= second_date) {

       income_float = Helpful_Methods::string_to_float_conversion(income.get_incomes_amount());

       return income_float;

    }
    else return 0;
}

float Balance::current_month_expense(Expense expense) {

    float expense_float = 0;

    if (expense.get_expense_date_int() >= Helpful_Methods::date_without_dashes_in_int(Date::get_fuly_beginning_date_of_current_month()) && expense.get_expense_date_int() <= Helpful_Methods::date_without_dashes_in_int(Date::get_current_data_from_PC())) {

        expense_float = Helpful_Methods::string_to_float_conversion(expense.get_expense_amount());
        return expense_float;

    } else return 0;

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

    float income_sum = 0;
    float druga_suma = 0;
    float drugi_income = 0;

    char choice;

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
/*
         for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++){

           sort_income(*itr);
        //    incomes_amount = current_month_income(*itr);
      //      income_sum = income_sum + incomes_amount;

        }
        cout << "suma iteratora: " << income_sum << endl;
        cout << endl;
*/
        sort(incomes.begin(), incomes.end(),sort_by_income_date());
        for (unsigned int i = 0; i < incomes.size(); i++){

             float income_amount = current_month_income(incomes[i], 20230310, 20230330 );
             druga_suma += income_amount;

        }
        cout << endl;
        cout << "druga suma wynosi: " << druga_suma << endl;
        system("pause");


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

       for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++){

            sort_expense(*itr);
            expense_amount = current_month_expense(*itr);
            expense_sum = expense_sum + expense_amount;

        }
    } else {
        cout << "No expenses in: ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear);
    }

    Helpful_Methods::display_summary_income_expense_current_month();

    cout << "Income sum is equal:  " << setprecision(20) << income_sum << endl;
    cout << "Expense sum is equal:  " << setprecision(20) << expense_sum << endl;

    system("pause");
    system("cls");

    Helpful_Methods::display_summary_income_expense_current_month();
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Do you wish to display difference between incomes and expenses? (y/n)" << endl;
    cin >> choice;

    if(answer(choice) == true) {

        float income_expense_difference = druga_suma - expense_sum;
        cout << "Calculating process. Please wait." << endl;
        Sleep(3000);

        cout << "--------------- Difference is equal --------------- " << endl;
        cout << "--------------- " << setprecision(20) << income_expense_difference << " --------------- "<< endl << endl;
        system("pause");

    }

    if(answer(choice) == false){

        cout << "Difference has not been calculated. Goodbye." << endl;

    }
}

float Balance::calculate_last_month_income(Income income){

    float income_amount = 0;

    if (income.get_date_in_int() >= Helpful_Methods::date_without_dashes_in_int(Date::get_fully_beginning_date_of_previous_month()) && income.get_date_in_int() <= Helpful_Methods::date_without_dashes_in_int(Date::get_fully_end_date_of_previous_month())){

        income_amount = Helpful_Methods::string_to_float_conversion(income.get_incomes_amount());
        return income_amount;

    }

    else return 0;
}

float Balance::calculate_expense_of_last_month(Expense expense){

    float expense_amount = 0;

    if (expense.get_expense_date_int() >= Helpful_Methods::date_without_dashes_in_int(Date::get_fully_beginning_date_of_previous_month()) && expense.get_expense_date_int() <= Helpful_Methods::date_without_dashes_in_int(Date::get_fully_end_date_of_previous_month())){

        expense_amount = Helpful_Methods::string_to_float_conversion(expense.get_expense_amount());
        return expense_amount;

    }
    else return 0;

}

void Balance::display_last_month_balance(vector <Income> incomes, vector <Expense> expenses){

    SYSTEMTIME st;
    GetSystemTime(&st);

    float incomes_amount = 0;
    float income_sum = 0;
    system("cls");

    char choice;

    sort(incomes.begin(), incomes.end(), sort_by_income_date());
    sort(expenses.begin(), expenses.end(), sort_by_expense_date());

    if (incomes.empty() == false) {

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++){

         //   sort_income(*itr);
            incomes_amount = calculate_last_month_income(*itr);
            income_sum = income_sum + incomes_amount;
        }

    } else {
        cout << "No incomes in ";

        cout << "sorry." << endl;
    }
    system("pause");
    system("cls");

    float expense_sum = 0;
    float expense_amount = 0;

    if (expenses.empty() == false) {


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

       for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++){

            sort_expense(*itr);
            expense_amount = calculate_expense_of_last_month(*itr);
            expense_sum = expense_sum + expense_amount;

        }
    } else {
        cout << "No expenses in: ";
        Date::display_months_name(st.wMonth);
        Date::display_current_year(st.wYear);
    }

    cout << "Income sum is equal:  " << setprecision(20) << income_sum << endl;
    cout << "Expense sum is equal:  " << setprecision(20) << expense_sum << endl;

    system("pause");
    system("cls");

    cout << "Do you wish to display difference between incomes and expenses? (y/n)" << endl;
    cin >> choice;

    if(answer(choice) == true) {

        float income_expense_difference = income_sum - expense_sum;
        cout << "Calulating process. Please wait." << endl;
        Sleep(3000);

        cout << "--------------- Difference is equal --------------- " << endl;
        cout << "--------------- " << setprecision(20) << income_expense_difference << " --------------- "<< endl << endl;
        system("pause");

    }

    if(answer(choice) == false){

        cout << "Difference has not been calculated. Goodbye." << endl;

    }

}

void Balance::display_selected_period_of_time_balance(vector <Income> incomes, vector <Expense> expenses) {

    sort(incomes.begin(), incomes.end(), sort_by_income_date());
    sort(expenses.begin(), expenses.end(), sort_by_expense_date());

    float incomes_amount = 0;
    float income_sum = 0;
    string beggining_date = Date::entering_manual_date();
    system("cls");
    cout << "Enter ending date: " << endl;
    string ending_date = Date::entering_manual_date();

    int beggining_date_int = 0, ending_date_int = 0;

    beggining_date_int = Helpful_Methods::date_without_dashes_in_int(beggining_date);
    ending_date_int = Helpful_Methods::date_without_dashes_in_int(ending_date);
    system("cls");
    system ("pause");

    if (incomes.empty() == false) {

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {

//            sort_income(*itr);
            incomes_amount = calculate_selected_period_of_time_incomes(*itr, beggining_date_int, ending_date_int);
            income_sum = income_sum + incomes_amount;
            cout << income_sum << endl;
            system("pause");

        }

    } else {
        cout << "No incomes in selected period of time.";
    }
    system("pause");
    system("cls");

    int expense_amount = 0, expense_sum = 0;
    if (expenses.empty() == false) {

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {

            sort_expense(*itr);
            expense_amount = calculate_selected_period_of_time_expenses(*itr, beggining_date_int, ending_date_int);
            expense_sum = expense_sum + expense_amount;

        }
        cout << "KURWA OKRES : " << expense_sum << endl;
        system ("pause");
    } else {
        cout << "No expenses ";
    }
}

float Balance::calculate_selected_period_of_time_incomes(Income income, int beggining_date_int, int ending_date_int){

    float income_amount = 0;

    if (income.get_date_in_int() >= beggining_date_int && income.get_date_in_int() <= ending_date_int){

        income_amount = Helpful_Methods::string_to_float_conversion(income.get_incomes_amount());

        return income_amount;

    }

    else{
        return 0;
    }
}

float Balance::calculate_selected_period_of_time_expenses(Expense expense, int beggining_date_int, int ending_date_int){

    float expense_amount = 0;

    if (expense.get_expense_date_int() >= beggining_date_int && expense.get_expense_date_int() <= ending_date_int){

        expense_amount = Helpful_Methods::string_to_float_conversion(expense.get_expense_amount());

        return expense_amount;

    }

    else{
        return 0;
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

void Balance::display_incomes(){

        cout << "Income title:                         " << income.get_incomes_title()<< endl;
        cout << "Income amount:                        " << income.get_incomes_amount() << endl;
        cout << "Income date:                          " << income.get_date_in_string() << endl;
        cout << endl;
}
