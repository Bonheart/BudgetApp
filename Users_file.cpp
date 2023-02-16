#include "Users_file.h"

void Users_File::add_user_to_file(User user){

    CMarkup xml;

    bool check_if_file_exists = xml.Load("users.xml");

    if (check_if_file_exists == false){

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users"); // adding root main name

    }

    xml.FindElem(); // findning an element (above) -> AddElem("Users"). This main element is being researched
    xml.IntoElem(); // I have to step inside main element so I can add another minor elements later
    xml.AddElem("User"); // User element added, where I'm going to nest child's tag
    xml.IntoElem(); // stepping inside "User" element.

    xml.AddElem("User's ID ", user.get_users_id());
    xml.AddElem("User's name ", user.get_users_name());
    xml.AddElem("User's surname ", user.get_users_surname());
    xml.AddElem("User's login ", user.get_users_login());
    xml.AddElem("User's password ", user.get_users_password());


    xml.Save("users.xml");



}

