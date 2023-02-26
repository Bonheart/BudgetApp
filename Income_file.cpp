#include "Income_file.h"

void Income_File::add_income_to_file(Income income){

    CMarkup xml;

    bool check_if_file_exists = xml.Load("income.xml");


    if (check_if_file_exists == false){ // if file doesnt exist, file will be created here

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes"); // adding root main name

    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();

    xml.AddElem("ID", income.get_incomes_id());
    xml.AddElem("User ID", income.get_logged_users_id());
    xml.AddElem("Date", income.get_date_in_string());
    xml.AddElem("Title", income.get_incomes_title());
    xml.AddElem("Amount", income.get_incomes_amount());


    xml.Save("income.xml");

    last_income_id++;

}

int Income_File::get_last_income_id(){

    return last_income_id ;
}
