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

    xml.AddElem("User ID ", user.get_users_id());
    xml.AddElem("User name ", user.get_users_name());
    xml.AddElem("User surname ", user.get_users_surname());
    xml.AddElem("login", user.get_users_login());
    xml.AddElem("User password ", user.get_users_password());


    xml.Save("users.xml");
}

vector <User> Users_File::load_users_from_file(){

    User user;

    CMarkup xml;

    vector <User> users;
    string users_login;

    bool check_if_file_exists = xml.Load("users.xml");

    xml.FindElem("Users"); // finding my main root element Users
    xml.IntoElem(); // stepping into root element

    while (xml.FindElem("User")){


        xml.IntoElem();
        xml.FindElem("login");
        users_login = xml.GetData();
        xml.OutOfElem();

    }

    user.set_users_login(users_login);

    users.push_back(user);


    return users;
}
