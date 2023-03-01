#include "Expense_file.h"

void Expense_File::add_expense_to_file(Expense expense){


    CMarkup xml;

    bool check_if_file_exists = xml.Load("expenses.xml");


    if (check_if_file_exists == false){ // if file doesnt exist, file will be created here

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

int Expense_File::get_last_expense_id(){

    return last_expense_id;
}
