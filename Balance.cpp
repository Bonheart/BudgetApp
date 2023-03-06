#include "Balance.h"

void Balance::sort_income(Income income){

    sort(incomes.begin(), incomes.end(), sort_by_income_date());
}

void Balance::sort_expense(Expense expense){

    sort(expenses.begin(), expenses.end(), sort_by_expense_date());
}


float Balance::current_month_income(Income income){

    SYSTEMTIME st;
    GetSystemTime(&st);

    float income_float = 0;
    int year = 0, month = 0, day = 0, actual_date_int = 0, beggining_date_int = 0;
    string day_number_in_string = "", month_number_in_string = "", day_in_string = "", months_beginning = "", years_beginning = "", begin_date = "", actual_date = "", day_begin = "01";

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    day_in_string = Helpful_Methods::int_to_string_conversion(day);
    if (day_in_string.length() == 1)
    {
        day_number_in_string = "0"+ day_in_string;
    }
    else day_number_in_string = day_in_string;

    months_beginning = Helpful_Methods::int_to_string_conversion(month);
    if (months_beginning.length() == 1)
    {
        month_number_in_string = "0"+ months_beginning;
    }
    else month_number_in_string = months_beginning;

    years_beginning = Helpful_Methods::int_to_string_conversion(year);

    begin_date = years_beginning + month_number_in_string + day_begin;

    actual_date = years_beginning + month_number_in_string+day_number_in_string;

    actual_date_int = Helpful_Methods::string_to_int_conversion(actual_date);

    beggining_date_int = Helpful_Methods::string_to_int_conversion(begin_date);

    if (income.get_date_in_int() >= beggining_date_int && income.get_date_in_int() <= actual_date_int)
    {
      //  viewIncomes(income);
        income_float = Helpful_Methods::string_to_float_conversion(income.get_incomes_amount());
        return income_float;
    }
    else return 0;
}

float Balance::current_month_expense(Expense expense){

    SYSTEMTIME st;
    GetSystemTime(&st);

    float expense_float = 0;
    int year = 0, month = 0, day = 0, actual_date_int = 0, beggining_date_int = 0;
    string day_number_in_string = "", month_number_in_string = "", day_in_string = "", months_beginning = "", years_beginning = "", begin_date = "", actual_date = "", day_begin = "01";

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    day_in_string = Helpful_Methods::int_to_string_conversion(day);
    if (day_in_string.length() == 1)
    {
        day_number_in_string = "0"+ day_in_string;
    }
    else day_number_in_string = day_in_string;

    months_beginning = Helpful_Methods::int_to_string_conversion(month);
    if (months_beginning.length() == 1)
    {
        month_number_in_string = "0"+ months_beginning;
    }
    else month_number_in_string = months_beginning;

    years_beginning = Helpful_Methods::int_to_string_conversion(year);

    begin_date = years_beginning + month_number_in_string + day_begin;

    actual_date = years_beginning + month_number_in_string + day_number_in_string;

    actual_date_int = Helpful_Methods::string_to_int_conversion(actual_date);

    beggining_date_int = Helpful_Methods::string_to_int_conversion(begin_date);

    if (expense.get_expense_date_int() >= beggining_date_int && expense.get_expense_date_int() <= actual_date_int)
    {
      //  viewIncomes(expense);
        expense_float = Helpful_Methods::string_to_float_conversion(expense.get_expense_amount());
        return expense_float;
    }
    else return 0;
}

void Balance::display_current_months_balance(vector <Income> incomes, vector <Expense> expenses)
{
    float quantityIncomes = 0;
    float sumIncome = 0;
    system("cls");
    sort(incomes.begin(), incomes.end(), sort_by_income_date());
    sort(expenses.begin(), expenses.end(), sort_by_expense_date());    //string dataBezZnaku;
    if (!incomes.empty())
    {
        cout << "    >>> PRZYCHODY Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {

                sort_income(*itr);
                quantityIncomes = current_month_income(*itr);
                sumIncome = sumIncome + quantityIncomes;
        }
        cout << "Suma przychodow: " << sumIncome << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych przychodow." << endl << endl;
    }

    float quantityExpenses = 0;
    float sumExpense = 0;
    if (!expenses.empty())
    {
        cout << "    >>> WYDATKI Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
                sort_expense(*itr);
                quantityExpenses = current_month_expense(*itr);
                sumExpense = sumExpense + quantityExpenses;
        }
        cout << "Suma wydatkow: " << sumExpense << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych wydatkow." << endl << endl;
    }

    float difference = sumIncome - sumExpense;
    cout << "Roznica: " << difference << endl << endl;
    system("pause");
}
