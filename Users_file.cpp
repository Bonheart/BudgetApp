#include "Users_file.h"

void Users_File::add_user_to_file(User user){

    CMarkup xml;

    bool check_if_file_exists = xml.Load("users.xml");

    if (check_if_file_exists == false){ // if file doesnt exist, file will be created here

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users"); // adding root main name

    }

    xml.FindElem(); // findning an element (above) -> AddElem("Users"). This main element is being researched
    xml.IntoElem(); // I have to step inside main element so I can add another minor elements later
    xml.AddElem("User"); // User element added, where I'm going to nest child's tag
    xml.IntoElem(); // stepping inside "User" element.

    xml.AddElem("ID", user.get_users_id());
    xml.AddElem("Name", user.get_users_name());
    xml.AddElem("Surname", user.get_users_surname());
    xml.AddElem("Login", user.get_users_login());
    xml.AddElem("Password", user.get_users_password());


    xml.Save("users.xml");
}

vector <User> Users_File::load_users_from_file() { // I need User's data in order to administer them in code below.

    User user;

    CMarkup xml;

    vector <User> users;
    string users_login = "", users_name = "", users_surname = "", users_password = "";
    int users_id;

    bool check_if_file_exsist = xml.Load("users.xml");

    if(check_if_file_exsist == true) {
        xml.FindElem("Users"); // finding my main root element Users
        xml.IntoElem(); // stepping into root element

        while (xml.FindElem("User")) {

            xml.IntoElem();
            xml.FindElem("ID");
            users_id = stoi(xml.GetData());
            xml.FindElem("Name");
            users_name = xml.GetData();
            xml.FindElem("Surname");
            users_surname = xml.GetData();
            xml.FindElem("Login");
            users_login = xml.GetData();
            xml.FindElem("Password");
            users_password = xml.GetData();
            xml.OutOfElem();

            user.set_users_id(users_id);
            user.set_users_name(users_name);
            user.set_users_surname(users_surname);
            user.set_users_login(users_login);
            user.set_users_password(users_password);

            users.push_back(user);

        }
    } else
        cout << "Cannot open file." << endl;

    return users;
}

void Users_File::change_password_in_file(int logged_user_id, string new_users_password)
{
    CMarkup xml;
    bool fileExists = xml.Load("users.xml");

    int users_id_in_file {};
    if (fileExists)
    {
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("ID");
            users_id_in_file = stoi(xml.GetData());
            if (users_id_in_file == logged_user_id)
            {
                xml.FindElem("Password");
                xml.SetData(new_users_password);
                break;
            }
            xml.OutOfElem();
        }
        xml.Save("users.xml");
    }
    else
        cout << "Cannot open file." << endl;
}
