#include "Income_file.h"

void Income_File::add_income_to_file(Income income){

    CMarkup xml;

    bool check_if_file_exists = xml.Load("income.xml");


    if (check_if_file_exists == false){ // if file doesnt exist, file will be created here

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes"); // adding root main name

    }

    xml.FindElem(); // findning an element (above) -> AddElem("Users"). This main element is being researched
    xml.IntoElem(); // I have to step inside main element so I can add another minor elements later
    xml.AddElem("Income"); // User element added, where I'm going to nest child's tag
    xml.IntoElem(); // stepping inside "User" element.

    xml.AddElem("title", income.get_incomes_title());


    xml.Save("income.xml");

}
