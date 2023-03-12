#include "Income_file.h"

bool Income_File::add_income_to_file(Income income){ // zmienic na voida jkbc

    CMarkup xml;

    bool check_if_file_exists = xml.Load("incomes.xml");

    if (check_if_file_exists == false){ // if file doesnt exist, file will be created here

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes"); // adding root main name

    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();

    xml.AddElem("ID", income.get_incomes_id());
    xml.AddElem("UserID", income.get_logged_users_id());
    xml.AddElem("Date", income.get_date_in_string());
    xml.AddElem("Title", income.get_incomes_title());
    xml.AddElem("Amount", income.get_incomes_amount());

    xml.Save("incomes.xml");

   last_income_id++;

   return true;
}

vector <Income> Income_File::load_income_from_file(int logged_user_id) {

    CMarkup xml;

    Income income;
    vector <Income> incomes;

    string string_data = "", income_title = "", income_amount = "";
    int income_id ;

    int found_logged_user_id_in_file {};
    int date_in_int;
/*
    if(check_if_file_exists == true){
        cout << "jestem tutaj incomes.xml" << endl;
    }

*/

        xml.Load("incomes.xml");
        xml.FindElem();
        xml.IntoElem();

     while(xml.FindElem("Income")) {

            xml.IntoElem();
            xml.FindElem("ID");
            income_id = atoi(MCD_2PCSZ(xml.GetData()));


            xml.FindElem("UserID");
            found_logged_user_id_in_file = atoi(MCD_2PCSZ(xml.GetData()));
            //income.set_incomes_id(found_logged_user_id_in_file);

            xml.FindElem("Date");
            string_data = xml.GetData();
            //income.set_date_in_string(string_data);

            xml.FindElem("Title");
            income_title = xml.GetData();
            //income.set_incomes_title(income_title);

            xml.FindElem("Amount");
            income_amount = xml.GetData();
            //income.set_incomes_amount(income_amount);

            xml.OutOfElem();

            date_in_int = Helpful_Methods::date_without_dashes_in_int(string_data);

            if(found_logged_user_id_in_file == logged_user_id) {

                income.set_incomes_id(income_id);
                income.set_date_in_string(string_data);
                income.set_incomes_title(income_title);
                income.set_incomes_amount(income_amount);
                income.set_date_in_int(date_in_int);
                last_income_id++;
                incomes.push_back(income);

            }

            else if ( string_data == "" && income_title == "" && income_amount == "" && income_id == 0){
                last_income_id = 0;
            }

            else {
                last_income_id = income_id;
                  last_income_id++;
            }
        }

    return incomes;
}

int Income_File::get_last_income_id() {

    return last_income_id;
}
