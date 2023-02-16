#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;


class User {

    int users_id;
    string users_name;
    string users_surname;
    string users_login;
    string users_password;

public:
    //setters
    void set_users_id(int new_id);
    void set_users_name(string new_name);
    void set_users_surname(string new_surname);
    void set_users_login(string new_login);
    void set_users_password(string new_password);
    //getters
    int get_users_id();
    string get_users_name();
    string get_users_surname();
    string get_users_login();
    string get_users_password();

};


#endif // USER_H
