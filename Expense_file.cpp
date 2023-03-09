#include "Expense_file.h"

int Expense_File::add_expense_to_file(Expense expense) {

    CMarkup xml;

    bool check_if_file_exists = xml.Load("expenses.xml");

    if (check_if_file_exists == false) { // if file doesnt exist, file will be created here

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses"); // adding root main name
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();

    xml.AddElem("ID", expense.get_expense_id());
    xml.AddElem("UserID", expense.get_logged_user_id());
    xml.AddElem("Date", expense.get_expense_date());
    xml.AddElem("Title", expense.get_expense_title());
    xml.AddElem("Amount", expense.get_expense_amount());

    xml.Save("expenses.xml");

    last_expense_id++;
}

vector <Expense> Expense_File::load_expenses_from_file(int logged_user_id) {

    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;

    bool check_if_file_exists(xml.Load("expenses.xml"));

    string expense_data = "", expense_title = "", expense_amount = "";
    int expense_id, expense_date_in_int;
    int found_logged_user_id_in_file {};

    if(check_if_file_exists == true) {

    //    cout << "Witaj, tutaj ja plik expense.xml x)" << endl;
      //  Sleep(1500);

        xml.FindElem();
        xml.IntoElem();

        while(xml.FindElem("Expense")) {

            xml.IntoElem();
            xml.FindElem("ID");
            expense_id = atoi(MCD_2PCSZ(xml.GetData()));

            xml.FindElem("UserID");
            found_logged_user_id_in_file = atoi(MCD_2PCSZ(xml.GetData()));

            xml.FindElem("Date");
            expense_data = xml.GetData();

            xml.FindElem("Title");
            expense_title = xml.GetData();

            xml.FindElem("Amount");
            expense_amount = xml.GetData();

            xml.OutOfElem();

            expense_date_in_int = Helpful_Methods::date_without_dashes_in_int(expense_data);

            if(found_logged_user_id_in_file == logged_user_id) {

                expense.set_expense_id(expense_id);
                expense.set_logged_user_id(found_logged_user_id_in_file);
                expense.set_expense_date(expense_data);
                expense.set_expense_date_in_int(expense_date_in_int);
                expense.set_expense_title(expense_title);
                expense.set_expense_amount(expense_amount);
                expenses.push_back(expense);

            }

            else {
                expense_id = last_expense_id;
            }

        }

    } else {
        cout << "Couldn't open file ""expenses.xml""" << endl;

    }

    last_expense_id ++;

    return expenses;
}

int Expense_File::get_last_expense_id() {

    return last_expense_id;
}
